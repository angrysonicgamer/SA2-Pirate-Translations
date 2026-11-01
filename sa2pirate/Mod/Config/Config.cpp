#include "pch.h"
#include "Config.h"
#include "Mod/Global/MyMod.h"
#include "Mod/Anti-Piracy/CannonsCoreEggman.h"
#include "IniFile.hpp"


std::string Config::TranslationType;
bool Config::RecreateCCEggmanGlitch;


void Config::Read()
{
	IniFile config(MyMod::Path + "\\config.ini");

	TranslationType = config.getString("Options", "IncludeDir0", "Kudos");
	RecreateCCEggmanGlitch = config.getBool("Options", "RecreateCCEggmanGlitch", false);
}


void Config::Init()
{
	Read();

	if (RecreateCCEggmanGlitch)
	{
		LoadCCEggmanWithoutFloorCollision();
	}
}