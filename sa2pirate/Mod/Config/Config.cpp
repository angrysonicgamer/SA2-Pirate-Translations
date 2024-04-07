#include "pch.h"
#include "Mod/Anti-Piracy/CannonsCoreEggman.h"
#include "Include/Mod Loader Common/IniFile.hpp"


std::string TranslationType;
bool RecreateCCEggmanGlitch;

std::string GetTranslationType()
{
	return TranslationType;
}


void ReadConfig(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	TranslationType = config.getString("Options", "TranslationType", "Kudos");
	RecreateCCEggmanGlitch = config.getBool("Options", "RecreateCCEggmanGlitch", false);
}


void InitConfig(const char* modPath)
{
	ReadConfig(modPath);

	if (RecreateCCEggmanGlitch)
	{
		LoadCCEggmanWithoutFloorCollision(modPath);
	}
}