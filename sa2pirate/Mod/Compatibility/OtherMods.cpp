#include "pch.h"
#include "OtherMods.h"
#include "Mod/Config/Config.h"
#include "Mod/File Loading/LoadFiles.h"
#include "Mod/Text/ExeText.h"
#include "IniFile.hpp"


HMODULE MenuOverhaul = GetModuleHandle(L"MenuOverhaul"); //Init Menu Overhaul dll
HMODULE CutsceneRevamp = GetModuleHandle(L"CutsceneRevamp"); //Init Cutscene Revamp dll
bool DisablePauseTweaks;


/* Menu Overhaul */

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
	
	if (Config::TranslationType == "Kudos")
	{
		OverwriteText(KudosText);
	}
	else
	{
		OverwriteText(VectorText);
	}
}


void InitOtherMods(const HelperFunctions& helperFunctions)
{
	if (CutsceneRevamp && Config::TranslationType == "Vector")
	{
		LoadCutsceneRevampFiles(helperFunctions);
	}

	if (MenuOverhaul)
	{
		OverwriteTextForMenuOverhaul(helperFunctions);
	}
}