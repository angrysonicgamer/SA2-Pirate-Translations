#include "pch.h"
#include "Include/IniFile.h"


std::string TranslationType;

void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	TranslationType = config.getString("Options", "TranslationType", "Kudos");
}

std::string GetTranslationType()
{
	return TranslationType;
}