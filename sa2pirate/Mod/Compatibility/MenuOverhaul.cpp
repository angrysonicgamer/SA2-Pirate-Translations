#include "pch.h"
#include "../Config/Config.h"
#include "../Text/ExeText.h"
#include "../../Include/Mod Loader Common/IniFile.hpp"


HMODULE MenuOverhaul = GetModuleHandle(L"MenuOverhaul"); //Init Menu Overhaul dll
bool DisablePauseTweaks;

struct TextToOverwrite
{
	const char* Extras;
	const char* Options;
	const char* Exit;
};

TextToOverwrite KudosText{ "\tQKCTPA MEHU", "\t0JVNN         ", "\tYX0D" };
TextToOverwrite VectorText{ "\tJKCTPA MEHG", "\tCMEHA 0UQNN   ", "\aYNTN" };


void ReadMenuOverhaulConfig(const HelperFunctions& helperFunctions)
{
	auto menuOverhaul = helperFunctions.Mods->find_by_dll(MenuOverhaul);
	IniFile menuOverhaulConfig(std::string(menuOverhaul->Folder) + "\\config.ini");

	DisablePauseTweaks = menuOverhaulConfig.getBool("Options", "DisablePauseTweaks", false);	
}

void OverwriteText(const TextToOverwrite& text)
{
	AdvertiseGamepad[2] = text.Extras;
	AdvertiseGamepad[3] = text.Options;
	AdvertiseGamepad[4] = text.Exit;

	AdvertiseKeyboard[2] = text.Extras;
	AdvertiseKeyboard[3] = text.Options;
	AdvertiseKeyboard[4] = text.Exit;

	if (!DisablePauseTweaks)
	{
		PauseMenu[2] = text.Exit;
	}
}

void OverwriteTextForMenuOverhaul(const HelperFunctions& helperFunctions)
{
	if (MenuOverhaul == nullptr) return;

	ReadMenuOverhaulConfig(helperFunctions);
	
	if (GetTranslationType() == "Kudos")
	{
		OverwriteText(KudosText);
	}
	else
	{
		OverwriteText(VectorText);
	}
}