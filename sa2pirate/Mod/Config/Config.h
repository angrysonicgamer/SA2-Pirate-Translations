#pragma once

class Config
{
public:
	static std::string TranslationType;
	static bool RecreateCCEggmanGlitch;

	static void Read();
	static void Init();
};