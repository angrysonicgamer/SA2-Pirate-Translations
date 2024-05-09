#include "pch.h"
#include "Mod/Config/Config.h"
#include "ExeText.h"
#include "ExeText_Kudos.h"
#include "ExeText_Vector.h"


void WriteAdvertise(const std::vector<const char*>& advertise)
{
	int size = advertise.size();

	for (int i = 0; i < size; i++)
	{
		if (strlen(advertise[i]) != 0)
		{
			AdvertiseGamepad[i] = advertise[i];
			AdvertiseKeyboard[i] = advertise[i];
		}
	}
}

void WritePauseMenu(const std::vector<const char*>& pauseMenu)
{
	int size = pauseMenu.size();

	for (int i = 0; i < size; i++)
	{
		if (strlen(pauseMenu[i]) != 0)
		{
			PauseMenu[i] = pauseMenu[i];
		}
	}
}

void WriteRemainingText()
{
	WriteData((const char**)0x173A95C, "NOW SAVING"); //"Saving..."
	
	WriteData((const wchar_t**)0x401648, L"Вы действительно хотите выйти из игры?\nВесь несохранённый прогресс будет утерян."); //exit prompt
	WriteData((const wchar_t**)0x174F59C, L"Да");
	WriteData((const wchar_t**)0x174F55C, L"Нет");
	WriteData((wchar_t*)0x89DD14, L"SONIC ADVENTURE 2: Предупреждение"); //exit message box title
}


void InitExeText()
{
	if (Config::TranslationType == "Kudos")
	{
		WriteAdvertise(AdvertiseKudos);
		WritePauseMenu(PauseMenuKudos);
	}
	else
	{
		WriteAdvertise(AdvertiseVector);
		WritePauseMenu(PauseMenuVector);
	}
	
	WriteRemainingText();
}