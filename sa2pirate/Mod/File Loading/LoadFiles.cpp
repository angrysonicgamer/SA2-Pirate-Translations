#include "pch.h"
#include "../Config/Config.h"


void ReplacePak(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destination = "resource\\gd_PC\\" + file + ".prs";
	std::string source = "resource\\gd_PC\\" + GetTranslationType() + "\\PRS\\" + file + ".pak";

	helperFunctions.ReplaceFile(destination.c_str(), source.c_str());
}

void ReplaceGvr(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destination = "resource\\gd_PC\\" + file + ".gvr";
	std::string source = "resource\\gd_PC\\" + GetTranslationType() + "\\PRS\\" + file + ".pak";

	helperFunctions.ReplaceFile(destination.c_str(), source.c_str());
}

void ReplaceMessageFile(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destinationGamepad = "resource\\gd_PC\\Message\\" + file + ".prs";
	std::string destinationKeyboard = "resource\\gd_PC\\MessageK\\" + file + +".prs";
	std::string source = "resource\\gd_PC\\" + GetTranslationType() + "\\Message\\" + file + ".prs";

	helperFunctions.ReplaceFile(destinationGamepad.c_str(), source.c_str());
	helperFunctions.ReplaceFile(destinationKeyboard.c_str(), source.c_str());
}

void ReplaceEventFile(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destination = "resource\\gd_PC\\event\\" + file + ".prs";
	std::string source = "resource\\gd_PC\\Vector\\event\\" + file + ".prs";

	helperFunctions.ReplaceFile(destination.c_str(), source.c_str());
}

void ReplaceCutsceneRevampPak(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destination = "resource\\gd_PC\\event\\" + file + ".prs";
	std::string source = "resource\\gd_PC\\Vector\\event\\cutscene revamp\\" + file + ".pak";

	helperFunctions.ReplaceFile(destination.c_str(), source.c_str());
}

void ReplaceSOCFile(const std::string& file, const HelperFunctions& helperFunctions)
{
	std::string destination = "resource\\gd_PC\\SOC\\" + file + ".pak";
	std::string source = "resource\\gd_PC\\" + GetTranslationType() + "\\SOC\\" + file + ".pak";

	helperFunctions.ReplaceFile(destination.c_str(), source.c_str());
}

void LoadFileList(const std::vector<const char*> fileList, void(*func)(const std::string& file, const HelperFunctions& helperFunctions), const HelperFunctions& helperFunctions)
{
	for (auto& file : fileList)
	{
		func(file, helperFunctions);
	}
}


std::vector<const char*> CommonPakList
{
	"al_ent_char_e_tex",
	"al_ent_title_e_tex",
	"al_race_adv_tex"
	"al_stg_kinder_ad_tex",
	"alphaTitle_e",
	"bigfoot_title_tex",
	"bossAttack",
	"bossResult",
	"congratulations",
	"console",
	"course",
	"emblemResult",
	"fdog_title_tex",
	"fileSelect_e",
	"game2ptex",
	"hotshot_title_tex",
	"kartRace",
	"missiontex_eg",
	"missiontex_kn",
	"missiontex_ro",
	"missiontex_sh",
	"missiontex_so",
	"missiontex_ta",
	"newMenu",
	"objtex_common",
	"options",
	"pressstart",
	"result",
	"resultCart",
	"segalogo",
	"soundTest_e",
	"SoundTest_e_DLC",
	"staffRoll",
	"stageMap",
	"STG_TITLE03",
	"STG_TITLE04",
	"STG_TITLE05",
	"STG_TITLE06",
	"STG_TITLE07",
	"STG_TITLE08",
	"STG_TITLE09",
	"STG_TITLE10",
	"STG_TITLE11",
	"STG_TITLE12",
	"STG_TITLE13",
	"STG_TITLE14",
	"STG_TITLE16",
	"STG_TITLE17",
	"STG_TITLE18",
	"STG_TITLE21",
	"STG_TITLE22",
	"STG_TITLE23",
	"STG_TITLE24",
	"STG_TITLE25",
	"STG_TITLE26",
	"STG_TITLE27",
	"STG_TITLE28",
	"STG_TITLE30",
	"STG_TITLE31",
	"STG_TITLE32",
	"STG_TITLE36",
	"STG_TITLE40",
	"STG_TITLE43",
	"STG_TITLE44",
	"STG_TITLE70",
	"STG_TITLE71",
	"STG_TITLE90",
	"storyMain",
	"TITLETEX_BOSSBOGY",
	"TITLETEX_BOSSLAST1",
	"TITLETEX_BOSSLAST2",
	"TITLETEX_GOLEM",
	"tutorial",
	"tvSetting",
	"twoPVS",
};

std::vector<const char*> CharacterIcons
{
	"zanki_amy",
	"zanki_chao",
	"zanki_chaos0",
	"zanki_egg1",
	"zanki_egg2",
	"zanki_knuckle",
	"zanki_metal",
	"zanki_rouge",
	"zanki_shadow",
	"zanki_sonic",
	"zanki_tails",
	"zanki_tical",
};

std::vector<const char*> MessageFiles
{
	"eh0005e",
	"eh0007e",
	"eh0008e",
	"eh0016e",
	"eh0018e",
	"eh0025e",
	"eh0026e",
	"eh0032e",
	"eh0041e",
	"eh0044e",
	"mh0003e",
	"mh0004e",
	"mh0005e",
	"mh0006e",
	"mh0007e",
	"mh0008e",
	"mh0009e",
	"mh0010e",
	"mh0011e",
	"mh0012e",
	"mh0013e",
	"mh0014e",
	"mh0015e",
	"mh0017e", //kudos did not translate mh0016e for some reason
	"mh0018e",
	"mh0019e",
	"mh0021e", //same for mh0020e
	"mh0022e",
	"mh0023e",
	"mh0024e",
	"mh0025e",
	"mh0026e",
	"mh0027e",
	"mh0028e",
	"mh0029e",
	"mh0030e",
	"mh0032e",
	"mh0033e",
	"mh0034e",
	"mh0035e",
	"mh0036e",
	"mh0037e",
	"mh0038e",
	"mh0040e",
	"mh0041e",
	"mh0042e",
	"mh0043e",
	"mh0044e",
	"mh0050e",
	"mh0051e",
	"mh0052e",
	"mh0053e",
	"mh0054e",
	"mh0055e",
	"mh0056e",
	"mh0057e",
	"mh0058e",
	"mh0060e",
	"mh0061e",
	"mh0062e",
	"mh0063e",
	"mh0064e",
	"mh0065e",
	"mh0066e",
	"mh0067e",
	"mh0068e",
	"mhsyse",
	"missione",
	"text_e",
};

//Kudos only
std::vector<const char*> KudosOnlyPakList
{
	"TITLETEX_EGGMAN",
	"TITLETEX_KNUCKLES",
	"TITLETEX_ROUGE",
	"TITLETEX_SHADOW",
	"TITLETEX_SONIC",
	"TITLETEX_TAILS"
};

//Vector only
std::vector<const char*> CutsceneTextFiles
{
	"evmesH1",
	"evmesD1",
	"evmesL1"
};

std::vector<const char*> CutsceneTextureFiles
{
	"e0101texture",
	"e0124texture",
	"e0211texture"
};

std::vector<const char*> VectorOnlyPakList
{
	"boss_pwguage_tex",
	"objtex_stg07",
	"objtex_stg08",
	"objtex_stg11",
	"objtex_stg12",
	"objtex_stg13",
	"objtex_stg14",
	"objtex_stg15p",
	"objtex_stg17",
	"objtex_stg24",
	"objtex_stg39",
	"objtex_stgbbf"
};


void LoadFiles(const HelperFunctions& helperFunctions)
{
	LoadFileList(CommonPakList, ReplacePak, helperFunctions);
	LoadFileList(CharacterIcons, ReplaceGvr, helperFunctions);
	LoadFileList(MessageFiles, ReplaceMessageFile, helperFunctions);

	ReplaceSOCFile("howtoplay1", helperFunctions);
	ReplaceSOCFile("pausemenu", helperFunctions);

	if (GetTranslationType() == "Kudos")
	{
		LoadFileList(KudosOnlyPakList, ReplacePak, helperFunctions);
	}
	else
	{
		LoadFileList(CutsceneTextFiles, ReplaceEventFile, helperFunctions);
		LoadFileList(CutsceneTextureFiles, ReplaceEventFile, helperFunctions);
		LoadFileList(VectorOnlyPakList, ReplacePak, helperFunctions);
		ReplaceMessageFile("mh0016e", helperFunctions);
		ReplaceMessageFile("mh0020e", helperFunctions);

		HMODULE cutsceneRevamp = GetModuleHandle(L"CutsceneRevamp");
		if (cutsceneRevamp == nullptr) return;

		LoadFileList(CutsceneTextureFiles, ReplaceCutsceneRevampPak, helperFunctions);
	}
}