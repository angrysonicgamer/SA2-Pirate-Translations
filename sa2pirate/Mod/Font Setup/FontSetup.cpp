#include "pch.h"
#include "../Config/Config.h"
#include <fstream>


/* Loading font */

const int FontFileSize = 1016064;
DataPointer(int*, FontDataAddress, 0xB5D64C);
DataArray(byte, MainFontSetup, 0x89F3E8, 224);
DataArray(byte, ChaoWorldFontSetup, 0x8A78D0, 224);


std::string GetFontPath()
{
	return "\\gd_PC\\" + GetTranslationType() + "\\efmsgfont_ascii24S.bin";
}

std::vector<char> ReadFontFile(std::string path)
{
	std::ifstream input(path, std::ios::binary);

	std::vector<char> bytes(
		(std::istreambuf_iterator<char>(input)),
		(std::istreambuf_iterator<char>()));

	input.close();

	return bytes;
}

void LoadMainFont(std::string path)
{
	std::vector<char> fontMemory = ReadFontFile(path);
	std::memcpy(FontDataAddress, fontMemory.data(), FontFileSize);
}


/* Setting up character widths */

struct LetterData
{
	byte LetterCode;
	byte Width;
};


std::vector<LetterData> VanillaDCSetup
{
	{ '!', 3 }, //using chars here to visualize
	{ '"', 9 },
	{ '#', 19 },
	{ '$', 13 },
	{ '%', 17 },
	{ '&', 14 },
	{ '\'', 3 },
	{ '(', 8 },
	{ ')', 8 },
	{ '*', 11 },
	{ '+', 10 },
	{ ',', 4 },
	{ '-', 9 },
	{ '.', 4 },
	{ '/', 11 },
	{ '0', 14 }, //О
	{ '1', 8 },
	{ '2', 12 },
	{ '3', 11 },
	{ '4', 13 }, //Ч
	{ '5', 12 },
	{ '6', 12 }, //Б
	{ '7', 13 },
	{ '8', 12 },
	{ '9', 13 },
	{ ':', 3 },
	{ ';', 4 },
	{ '<', 8 },
	{ '=', 9 },
	{ '>', 8 },
	{ '?', 11 },
	{ '@', 19 },
	{ 'A', 14 }, //А
	{ 'B', 12 }, //В
	{ 'C', 14 }, //С
	{ 'D', 14 }, //Д
	{ 'E', 13 }, //Е
	{ 'F', 12 }, //Ы
	{ 'G', 15 }, //Ш
	{ 'H', 15 }, //Н
	{ 'I', 11 },
	{ 'J', 14 }, //П
	{ 'K', 12 }, //К
	{ 'L', 12 }, //Л
	{ 'M', 19 }, //М
	{ 'N', 17 }, //И
	{ 'O', 18 }, //Ф
	{ 'P', 11 }, //Р
	{ 'Q', 20 }, //Э
	{ 'R', 13 }, //Я
	{ 'S', 14 }, //Ь
	{ 'T', 15 }, //Т
	{ 'U', 15 }, //Ю
	{ 'V', 14 }, //Ц
	{ 'W', 22 }, //Ж
	{ 'X', 15 }, //Х
	{ 'Y', 14 }, //У
	{ 'Z', 15 }, //Г
	{ '[', 7 },
	{ '\\', 10 },
	{ ']', 6 },
	{ '^', 10 },
	{ '_', 16 },
	{ '`', 5 },
	{ 'a', 12 },
	{ 'b', 11 },
	{ 'c', 11 },
	{ 'd', 13 },
	{ 'e', 11 },
	{ 'f', 10 },
	{ 'g', 12 },
	{ 'h', 11 },
	{ 'i', 4 },
	{ 'j', 8 },
	{ 'k', 11 },
	{ 'l', 3 },
	{ 'm', 17 },
	{ 'n', 11 },
	{ 'o', 11 },
	{ 'p', 11 },
	{ 'q', 11 },
	{ 'r', 10 },
	{ 's', 10 },
	{ 't', 10 },
	{ 'u', 11 },
	{ 'v', 11 },
	{ 'w', 15 },
	{ 'x', 12 },
	{ 'y', 12 },
	{ 'z', 11 },
	{ '{', 9 },
	{ '|', 3 },
	{ '}', 9 },
	{ '~', 12 }
};


void WriteFontData()
{
	byte extraSpacing = 2;
	
	for (auto& letter : VanillaDCSetup)
	{
		bool isDigitOrCapital = letter.LetterCode >= '0' && letter.LetterCode <= '9' || letter.LetterCode >= 'A' && letter.LetterCode <= 'Z';
		
		MainFontSetup[letter.LetterCode - ' '] = isDigitOrCapital ? letter.Width + extraSpacing : letter.Width + extraSpacing - 1;
		ChaoWorldFontSetup[letter.LetterCode - ' '] = isDigitOrCapital ? letter.Width + extraSpacing : letter.Width + extraSpacing - 1;
	}
}


void SetUpFont(const char* modPath)
{
	LoadMainFont(modPath + GetFontPath());
	WriteFontData();
}