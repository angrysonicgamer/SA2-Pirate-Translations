#include "pch.h"
#include "Config/Config.h"
#include "Compatibility/MenuOverhaul.h"
#include "Font Setup/FontSetup.h"
#include "File Loading/LoadFiles.h"
#include "Text/ExeText.h"


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
