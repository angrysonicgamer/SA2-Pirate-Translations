#include "pch.h"
#include "Render Fix/renderfix_api.h"
#include "FontSetup.h"
#include "Mod/Config/Config.h"


// Loading font

VoidFunc(UnloadFonts, 0x6B62C0);
VoidFunc(LoadFonts, 0x6B6130);
DataPointer(int*, AsciiSFontBuffer, 0xB5D64C);
DataArray(byte, MainFontSetup, 0x89F3E8, 224);
DataArray(byte, ChaoWorldFontSetup, 0x8A78D0, 224);


const char* ConvertToCStyle(const std::string& text)
{
	return strcpy(new char[text.length()], text.c_str());
}

std::string GetFontPath()
{
	return "\\gd_PC\\" + Config::TranslationType + "\\efmsgfont_ascii24S.bin";
}


void LoadFont(const char* modPath, std::string fontPath)
{
	std::string path = std::string(modPath) + fontPath;
	WriteData((const char**)0xB5D648, ConvertToCStyle("..\\..\\" + path)); // main font
	WriteData((const char**)0x12E9BD0, ConvertToCStyle("..\\..\\" + path)); // chao font
	UnloadFonts();
	LoadFonts();
}


// Automatic character widths calculation

void CalculateCharacterWidths()
{
	const byte extraSpacing = 2;
	
	MainFontSetup[0] = 9; // vanilla width of space
	ChaoWorldFontSetup[0] = 9;

	for (int charNumber = 1; charNumber < 224; charNumber++) // starting from 1 because 0 is space (empty pixels)
	{
		int maxColumn = 0;
		for (int row = 0; row < 24; row++)
		{
			for (int column = 0; column < 24; column++)
			{
				if (AsciiSFontBuffer[charNumber * 24 * 24 + row * 24 + column] != 0)
				{
					if (column > maxColumn)
						maxColumn = column;
				}
			}
		}
		MainFontSetup[charNumber] = maxColumn + 1 + extraSpacing;
		ChaoWorldFontSetup[charNumber] = maxColumn + 1 + extraSpacing;
	}
}


// No Render Fix

void InitFont(const char* modPath)
{
	LoadFont(modPath, GetFontPath());
	CalculateCharacterWidths();
}


// Using Render Fix font API

void InitFont_RF(RFAPI_CORE* pApi, const char* modPath)
{
	std::string fullFontPath = std::string(modPath) + GetFontPath();
	const RFAPI_FONT* rf_font = pApi->pApiFont;
	RFS_FONT* myfont = rf_font->LoadFontFile(fullFontPath.c_str(), FONT_FTYPE_RGBA_ASCII);
	rf_font->SetFont(FONT_LANG_ENG, FONT_TYPE_ASCII, myfont);
	rf_font->SetChaoFont(FONT_TYPE_ASCII, myfont);
}