#include "pch.h"
#include "LandTableInfo.h"


HMODULE DataDLL = **datadllhandle;

void LoadCCEggmanWithoutFloorCollision(const char* modPath)
{
	LandTable* CannonsCoreEggman = (LandTable*)GetProcAddress(DataDLL, "objLandTable0035");

	*CannonsCoreEggman = *(new LandTableInfo(std::string(modPath) + "\\gd_PC\\anti-piracy\\cceggman.sa2blvl"))->getlandtable();

	NJS_TEXLIST* texlist_landtx35 = (NJS_TEXLIST*)GetProcAddress(DataDLL, "texlist_landtx35");
	CannonsCoreEggman->TextureList = texlist_landtx35;
	CannonsCoreEggman->TextureName = "landtx35";
}