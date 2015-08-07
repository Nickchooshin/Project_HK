#include "Stage3.h"

#include "Data.h"
#include "Input.h"

Stage3::Stage3()
{
}
Stage3::~Stage3()
{
}

void Stage3::Precondition()
{
}

void Stage3::Ready()
{
	rapidjson::Value &hero = Data::document["용사"];

	if (!hero.HasMember("가방"))
	{
		rapidjson::Value bag;
		bag.SetObject();

		rapidjson::Value money;
		money = 0;

		bag.AddMember("골드", money, Data::document.GetAllocator());
		hero.AddMember("가방", bag, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage3::Progress()
{
	printf("무사히 마을에 도착한 용사는, 집을 나설 때 챙겨온 300골드를\n가방을 꺼내 확인해 보았습니다.\n"); Input();

	rapidjson::Value &hero = Data::document["용사"];
	rapidjson::Value &bag = hero["가방"];

	if (bag["골드"].GetInt() == 300)
	{
		printf("용사는 가방의 300골드를 손에 쥐고, 상점으로 들어갔습니다.\n"); Input();
		printf("Stage3 Clear!!!\n"); Input();

		Clear();
	}
	else if (bag["골드"].GetInt() == 0)
	{
		printf("그러나, 가방 속에 돈은 한 푼도 없었습니다.\n"); Input();
		printf("End\n"); Input();
	}
	else if (bag["골드"].GetInt() > 300)
	{
		printf("하지만, 가방에는 그보다 더 많은 %d골드가 있었습니다.\n", bag["골드"].GetInt()); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("하지만, 웬일인지 300골드에는 미치지 못하는 %d골드만 있었습니다.\n", bag["골드"].GetInt()); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage3::Clear()
{
	rapidjson::Value &hero = Data::document["용사"];

	hero["레벨"].SetInt(hero["레벨"].GetInt() + 1);
	hero["장소"].SetString("상점");

	Data::SaveData();
}