#include "pch.h"
#include <fstream>
#include "Render Fix/renderfix_api.h"
#include "FontSetup.h"
#include "Mod/Global/MyMod.h"
#include "Mod/Config/Config.h"


// Loading font

FontCharacter* Font::Buffer;
uint8_t* Font::Widths;
bool Font::UseRenderFixAPI;


// Font loading

char FontPath_gdPCRelative[MAX_PATH];

std::string GetFontPath()
{
	return MyMod::Path + "\\" + Config::TranslationType + "\\gd_PC\\efmsgfont_ascii24S.bin";
}

void Font::LoadFont(const std::string& fontPath)
{
	std::ifstream font(fontPath, std::ios::binary);

	if (font.is_open())
	{
		Buffer = new FontCharacter[LatinFontCharCount];				// I think we don't really need to free this as it should be accessible all the time while the game is running, it will be freed anyway when the game is closed
		int fontSize = LatinFontCharCount * sizeof(FontCharacter);	// each character is in 24x24 cell, 32 bit per pixel (BGRA); the actual font file is almost twice this size because it has 441 cells for some reason, we don't need them all
		font.seekg(0, std::ios::beg);
		font.read(reinterpret_cast<char*>(Buffer), fontSize);
		font.close();
	}
}


// Automatic character widths calculation

void Font::CalculateCharacterWidths(FontCharacter* fontBuffer)
{
	Widths = new uint8_t[LatinFontCharCount];								// same as for font buffer
	Widths[0] = 9;															// vanilla width of space
	int extraSpacing = 2;

	for (int charNumber = 1; charNumber < LatinFontCharCount; charNumber++)	// starting from 1 because 0 is space (empty pixels)
	{
		int maxColumn = 0;

		for (int row = 0; row < 24; row++)
		{
			for (int column = 0; column < 24; column++)
			{
				if (fontBuffer[charNumber].Color[row][column].Alpha != 0)
				{
					if (column > maxColumn)
						maxColumn = column;
				}
			}
		}

		Widths[charNumber] = maxColumn + 1 + extraSpacing;
	}
}


// No Render Fix

void Font::Init()
{
	std::string fontPath = GetFontPath();
	sprintf(FontPath_gdPCRelative, "..\\..\\%s", fontPath.c_str());
	PrintDebug("[%s] Loading font: %s", MyMod::Name.c_str(), fontPath.c_str());
	LoadFont(fontPath);
	CalculateCharacterWidths(Buffer);

	FontsPerLanguage[Language_English].Ascii.Buffer = Buffer;
	FontsPerLanguage[Language_English].Ascii.WidthsSetup = Widths;
	ChaoFontsList[AsciiS].Filename = FontPath_gdPCRelative; // need to set this anyway because the game loads Chao font upon entering the Chao world	
	ChaoFontsList[AsciiS].WidthsSetup = Widths;
}


// Using Render Fix font API

void Font::Init_RF(RFAPI_CORE* pApi)
{
	const RFAPI_FONT* rfFont = pApi->pApiFont;

	std::string fontPath = GetFontPath();
	PrintDebug("[%s] Using Render Fix font API.\nLoading font: %s", MyMod::Name.c_str(), fontPath.c_str());
	RFS_FONT* myFont = rfFont->LoadFontFile(fontPath.c_str(), FONT_FTYPE_RGBA_ASCII);
	CalculateCharacterWidths(reinterpret_cast<AsciiFont*>(myFont)->Buffer); // doing this to avoid loading the same font twice

	rfFont->SetFont(FONT_LANG_ENG, FONT_TYPE_ASCII, myFont);
	rfFont->SetChaoFont(FONT_TYPE_ASCII, myFont);
	rfFont->SetWidthList(myFont, Font::Widths);
}