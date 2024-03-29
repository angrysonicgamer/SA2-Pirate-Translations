#include "pch.h"
#include "Mod.h"
#include <string>
#include <vector>
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
	{ '0', 14 }, //�
	{ '1', 8 },
	{ '2', 12 },
	{ '3', 11 },
	{ '4', 13 }, //�
	{ '5', 12 },
	{ '6', 12 }, //�
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
	{ 'A', 14 }, //�
	{ 'B', 12 }, //�
	{ 'C', 14 }, //�
	{ 'D', 14 }, //�
	{ 'E', 13 }, //�
	{ 'F', 12 }, //�
	{ 'G', 15 }, //�
	{ 'H', 15 }, //�
	{ 'I', 11 },
	{ 'J', 14 }, //�
	{ 'K', 12 }, //�
	{ 'L', 12 }, //�
	{ 'M', 19 }, //�
	{ 'N', 17 }, //�
	{ 'O', 18 }, //�
	{ 'P', 11 }, //�
	{ 'Q', 20 }, //�
	{ 'R', 13 }, //�
	{ 'S', 14 }, //�
	{ 'T', 15 }, //�
	{ 'U', 15 }, //�
	{ 'V', 14 }, //�
	{ 'W', 22 }, //�
	{ 'X', 15 }, //�
	{ 'Y', 14 }, //�
	{ 'Z', 15 }, //�
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