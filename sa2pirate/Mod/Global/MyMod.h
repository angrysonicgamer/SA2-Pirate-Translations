#pragma once

class MyMod
{
public:
	static const std::string Name;
	static std::string Path;
	static HelperFunctions Helper;

	static void Init(const char* modPath, const HelperFunctions& helperFunctions);
};