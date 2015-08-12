#include "EndStage.h"

#include "Data.h"
#include "Input.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

bool EndStage::Precondition()
{
	rapidjson::Value &hero = Data::document["용사"];
	rapidjson::Value &bag = hero["가방"];
	rapidjson::Value &equipment = bag["장비"];
	auto find_equipment = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (hero["이동 여부"] == true &&
		hero["장소"] == "마을" &&
		bag["골드"] == 250 &&
		find_equipment("롱소드") &&
		find_equipment("방패"))
	{
		return true;
	}

	return false;
}

void EndStage::Ready()
{
}

void EndStage::Progress()
{
	printf("마을을 나서 숲을 걸어가던 용사는\n"); Input();
	printf("마왕의 성에 도착했습니다.\n"); Input();
	printf("Game Clear\n"); Input();

	Clear();

	Data::ShowData();
}

void EndStage::Clear()
{
	rapidjson::Value &hero = Data::document["용사"];

	hero["장소"].SetString("성");

	Data::SaveData();
}