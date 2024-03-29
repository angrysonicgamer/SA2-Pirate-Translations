#include "pch.h"
#include "../../Include/Mod Loader Common/IniFile.hpp"


std::string TranslationType;

std::string GetTranslationType()
{
	return TranslationType;
}


void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	TranslationType = config.getString("Options", "TranslationType", "Kudos");
}