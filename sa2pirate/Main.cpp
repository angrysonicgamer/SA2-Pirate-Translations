#include "pch.h"
#include "Mod.h"


extern "C"
{
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		ReadConfig(modPath);
		SetUpFont(modPath);
		LoadFiles(helperFunctions);
		InitExeText();
		OverwriteTextForMenuOverhaul(helperFunctions);		
	}	
	
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}
