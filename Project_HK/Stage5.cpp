#include "Stage5.h"

#include "Data.h"

Stage5::Stage5()
{
}
Stage5::~Stage5()
{
}

void Stage5::Precondition()
{
	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];

	if (hero["location"].GetString() == "forest")
	{
		hero["location"].SetString("forest");

		Data::SaveData();
	}
}

void Stage5::Progress()
{
	printf("마을을 나서 숲을 걸어가던 용사는\n"); getchar();

	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];
	rapidjson::Value &equipment = bag["equipment"];

	auto find_weapon = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (!find_weapon("shield"))
	{
		printf("상점 주인의 호의를 거절한 탓인지\n방패가 없어서 수없이 날아오는 화살을 맞고 죽었다.\n"); getchar();
		printf("시간을 되돌릴 수만 있다면, 그때 방패를 받았을 것이다.\n"); getchar();
		printf("End\n"); getchar();
	}
	else
	{
		printf("자신의 손에 방금 전 상점의 방패가 들려있다는 것을 눈치챘다.\n"); getchar();
		printf("그 순간!!!\n"); getchar();
		printf("용사는 수없이 날아오는 화살을 맞고 죽었다.\n"); getchar();
		printf("분명 '방패를 들고 온 기억이 없었다'고 의문심을 품으며...\n"); getchar();
		printf("End\n"); getchar();
	}

	Data::ShowData();
}

void Stage5::Clear()
{
}