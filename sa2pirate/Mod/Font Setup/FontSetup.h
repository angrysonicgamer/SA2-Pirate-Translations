#pragma once

// Structs based on my own font stuff research

enum FontTypes
{
	Kanji,
	AsciiS,
	AsciiE,
};

struct FontColor
{
	Uint8 B;
	Uint8 G;
	Uint8 R;
	Uint8 Alpha;
};

struct FontCharacter
{
	FontColor Color[24][24];
};

struct ChaoFontInfo
{
	const char* Filename;
	FontCharacter* Buffer;
	Uint8* WidthsSetup;
};

struct AsciiFont
{
	Uint8* WidthsSetup;
	FontCharacter* Buffer;
	FontTypes Type;
};

struct KanjiFont
{
	Uint8* WidthsSetup;
	FontCharacter* Buffer;
	FontTypes Type;
	Uint8 ShiftMin, ShiftMax;
	short Null;
};

struct LanguageFontsData
{
	int Null;
	AsciiFont Ascii;
	KanjiFont Kanji;
};

DataArray(LanguageFontsData, FontsPerLanguage, 0xB5D658, 6);
DataArray(ChaoFontInfo, ChaoFontsList, 0x12E9BC4, 3);
const int LatinFontCharCount = 224;


class Font
{
public:
	static FontCharacter* Buffer;
	static uint8_t* Widths;
	static bool UseRenderFixAPI;

	static void Init();
	static void Init_RF(RFAPI_CORE* pApi);

private:
	static void LoadFont(const std::string& fontPath);
	static void CalculateCharacterWidths(FontCharacter* fontBuffer);
};