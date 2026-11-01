#include "pch.h"
#include "Render Fix/renderfix_api.h"
#include "Global/MyMod.h"
#include "Config/Config.h"
#include "Compatibility/OtherMods.h"
#include "Font Setup/FontSetup.h"
#include "Text/ExeText.h"


extern "C"
{
	__declspec(dllexport) void RF_Init(RFAPI_CORE* pApi, const char* modPath, const HelperFunctions& helperFunctions)
	{
		if (pApi->version < 1) // doesn't have font loading API
			return;

		Font::UseRenderFixAPI = true;

		MyMod::Init(modPath, helperFunctions);
		Config::Init();
		Font::Init_RF(pApi);
	}
	
	__declspec(dllexport) void Init(const char* modPath, const HelperFunctions& helperFunctions)
	{
		if (!Font::UseRenderFixAPI)
		{
			MyMod::Init(modPath, helperFunctions);
			Config::Init();
			Font::Init();			
		}

		InitExeText();
		InitOtherMods();		
	}	
	
	__declspec(dllexport) ModInfo SA2ModInfo = { ModLoaderVer };
}
