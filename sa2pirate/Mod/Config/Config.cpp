#include "pch.h"
#include "Config.h"
#include "Mod/Anti-Piracy/CannonsCoreEggman.h"
#include "Include/Mod Loader Common/IniFile.hpp"


std::string Config::TranslationType;
bool Config::RecreateCCEggmanGlitch;


void Config::Read(const char* modPath)
{
	IniFile config(std::string(modPath) + "\\config.ini");

	TranslationType = config.getString("Options", "TranslationType", "Kudos");
	RecreateCCEggmanGlitch = config.getBool("Options", "RecreateCCEggmanGlitch", false);
}


void Config::Init(const char* modPath)
{
	Read(modPath);

	if (RecreateCCEggmanGlitch)
	{
		LoadCCEggmanWithoutFloorCollision(modPath);
	}
}