#include "pch.h"
#include "CannonsCoreEggman.h"
#include "LandTableInfo.h"
#include "Mod/Global/MyMod.h"


HMODULE DataDLL = **datadllhandle;

void LoadCCEggmanWithoutFloorCollision()
{
	LandTable* CannonsCoreEggman = (LandTable*)GetProcAddress(DataDLL, "objLandTable0035");

	*CannonsCoreEggman = *(new LandTableInfo(MyMod::Path + "\\gd_PC\\Cannon's Core\\cceggman.sa2blvl"))->getlandtable();

	NJS_TEXLIST* texlist_landtx35 = (NJS_TEXLIST*)GetProcAddress(DataDLL, "texlist_landtx35");
	CannonsCoreEggman->TextureList = texlist_landtx35;
	CannonsCoreEggman->TextureName = "landtx35";
}