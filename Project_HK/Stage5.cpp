#include "Stage5.h"

#include "Data.h"
#include "Input.h"

Stage5::Stage5()
{
}
Stage5::~Stage5()
{
}

bool Stage5::Precondition()
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
		(hero["장소"] == "마을" || hero["장소"] == "숲") &&
		bag["골드"] == 250 &&
		find_equipment("롱소드"))
	{
		return true;
	}

	return false;
}

void Stage5::Ready()
{
	rapidjson::Value &hero = Data::document["용사"];
	rapidjson::Value &bag = hero["가방"];

	if (hero["장소"] != "숲")
	{
		hero["장소"].SetString("숲");

		Data::SaveData();
	}
}

void Stage5::Progress()
{
	printf("마을을 나서 숲을 걸어가던 용사는\n"); Input();

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

	if (!find_equipment("방패"))
	{
		printf("상점 주인의 호의를 거절한 탓인지\n방패가 없어서 수없이 날아오는 화살을 맞고 죽었다.\n"); Input();
		printf("시간을 되돌릴 수만 있다면, 그때 방패를 받았을 것이다.\n"); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("자신의 손에 방금 전 상점의 방패가 들려있다는 것을 눈치챘다.\n"); Input();
		printf("그 순간!!!\n"); Input();
		printf("용사는 수없이 날아오는 화살을 맞고 죽었다.\n"); Input();
		printf("분명 '방패를 들고 온 기억이 없었다'고 의문심을 품으며...\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage5::Clear()
{
}