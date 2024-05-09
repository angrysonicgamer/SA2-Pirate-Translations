﻿#include "pch.h"
#include "Config/Config.h"
#include "Compatibility/OtherMods.h"
#include "Font Setup/FontSetup.h"
#include "File Loading/LoadFiles.h"
#include "Text/ExeText.h"


extern "C"
{
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		Config::Init(modPath);
		InitFont(modPath);
		LoadFiles(helperFunctions);
		InitExeText();
		InitOtherMods(helperFunctions);		
	}	
	
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}
