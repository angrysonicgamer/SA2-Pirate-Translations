#include "pch.h"
#include "MyMod.h"


const std::string MyMod::Name = "SA2 Pirate Translations";
std::string MyMod::Path;
HelperFunctions MyMod::Helper;

void MyMod::Init(const char* modPath, const HelperFunctions& helperFunctions)
{
	Path = modPath;
	Helper = helperFunctions;
}