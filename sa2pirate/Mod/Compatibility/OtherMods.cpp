#include "pch.h"
#include "OtherMods.h"
#include "Mod/Global/MyMod.h"
#include "Mod/Config/Config.h"
#include "Mod/Text/ExeText.h"
#include "IniFile.hpp"


HMODULE MenuOverhaul = GetModuleHandle(L"MenuOverhaul");		//Init Menu Overhaul dll
HMODULE CutsceneRevamp = GetModuleHandle(L"CutsceneRevamp");	//Init Cutscene Revamp dll
HMODULE RenderFix = GetModuleHandle(L"sa2-render-fix");			//Init Render Fix dll
bool DisablePauseTweaks;


// Menu Overhaul

struct TextToOverwrite
{
	const char* Extras;
	const char* Options;
	const char* Exit;
};

TextToOverwrite KudosText{ "\tQKCTPA MEHU", "\t0JVNN         ", "\tYX0D" };
TextToOverwrite VectorText{ "\tJKCTPA MEHG", "\tCMEHA 0UQNN   ", "\aYNTN" };


void ReadMenuOverhaulConfig()
{
	auto menuOverhaul = MyMod::Helper.Mods->find_by_dll(MenuOverhaul);
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

void OverwriteTextForMenuOverhaul()
{
	if (MenuOverhaul == nullptr) return;

	ReadMenuOverhaulConfig();
	
	if (Config::TranslationType == "Kudos")
	{
		OverwriteText(KudosText);
	}
	else
	{
		OverwriteText(VectorText);
	}
}


// Render Fix + Cutscene Revamp texture archive replacement

void ReplaceEventTexArchive(const std::string& folder, const std::string& file)
{
	std::string destination = "resource\\gd_PC\\event\\PRS\\" + file + ".pak";
	std::string source = "resource\\gd_PC\\event\\Vector\\" + folder + "\\" + file + ".pak";

	MyMod::Helper.ReplaceFile(destination.c_str(), source.c_str());
}


void InitOtherMods()
{
	if (CutsceneRevamp && Config::TranslationType == "Vector")
	{
		ReplaceEventTexArchive("cr", "e0101texture");
		ReplaceEventTexArchive("cr", "e0124texture");
		ReplaceEventTexArchive("cr", "e0211texture");
	}

	if (RenderFix && Config::TranslationType == "Vector")
	{
		ReplaceEventTexArchive("rf", "e0101texture");
		ReplaceEventTexArchive("rf", "e0124texture");
		ReplaceEventTexArchive("rf", "e0211texture");
	}

	if (MenuOverhaul)
	{
		OverwriteTextForMenuOverhaul();
	}
}