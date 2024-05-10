#include "pch.h"
#include "Render Fix/renderfix_api.h"
#include "Config/Config.h"
#include "Compatibility/OtherMods.h"
#include "Font Setup/FontSetup.h"
#include "File Loading/LoadFiles.h"
#include "Text/ExeText.h"


bool UseRenderFixFontLoading;

extern "C"
{
	__declspec(dllexport) void RF_Init(RFAPI_CORE* pApi, const char* modPath, const HelperFunctions& helperFunctions)
	{
		if (pApi->version < 1) // doesn't have font loading API
			return;

		UseRenderFixFontLoading = true;

		Config::Init(modPath);
		InitFont_RF(pApi, modPath);
		PrintDebug("SA2 Pirate Translations: used Render Fix font loading API\n");
	}
	
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		if (!UseRenderFixFontLoading)
		{
			Config::Init(modPath);
			InitFont(modPath);
			PrintDebug("SA2 Pirate Translations: Render Fix font API not found, used my own font loading method\n");
		}		
		LoadFiles(helperFunctions);
		InitExeText();
		InitOtherMods(helperFunctions);		
	}	
	
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}
