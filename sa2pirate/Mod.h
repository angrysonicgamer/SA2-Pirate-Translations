#pragma once

#include <string>

DataArray(const char*, AdvertiseGamepad, 0xC50CB8, 714);
DataArray(const char*, AdvertiseKeyboard, 0xC57120, 714);
DataArray(const char*, PauseMenu, 0x174A828, 22);

std::string GetTranslationType();
void ReadConfig(const char* modPath);
void SetUpFont(const char* modPath);
void LoadFiles(const HelperFunctions& helperFunctions);
void InitExeText();
void OverwriteTextForMenuOverhaul(const HelperFunctions& helperFunctions);