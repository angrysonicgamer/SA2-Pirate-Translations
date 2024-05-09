#pragma once

class Config
{
public:
	static std::string TranslationType;
	static bool RecreateCCEggmanGlitch;

	static void Read(const char* modPath);
	static void Init(const char* modPath);
};

//std::string GetTranslationType();
//void InitConfig(const char* modPath);