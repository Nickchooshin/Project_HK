#include "Stage3.h"

#include "Data.h"

Stage3::Stage3()
{
}
Stage3::~Stage3()
{
}

void Stage3::Precondition()
{
	rapidjson::Value &hero = Data::document["hero"];
	if (!hero.HasMember("bag"))
	{
		rapidjson::Value bag;
		bag.SetObject();

		rapidjson::Value money;
		money = 0;

		bag.AddMember("money", money, Data::document.GetAllocator());
		hero.AddMember("bag", bag, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage3::Progress()
{
	printf("무사히 마을에 도착한 용사는, 집을 나설 때 챙겨온 300골드를 가방을 꺼내 확인해 보았습니다."); getchar();

	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];
	if (bag["money"].GetInt() == 300)
	{
		printf("용사는 가방의 300골드를 손에 쥐고, 상점으로 들어갔습니다."); getchar();
		printf("Stage3 Clear!!!"); getchar();

		Clear();
	}
	else if (bag["money"].GetInt() == 0)
	{
		printf("하지만, 가방 속에 돈은 한 푼도 없었습니다."); getchar();
		printf("End"); getchar();
	}
	else if (bag["money"].GetInt() > 300)
	{
		printf("하지만, 가방에는 그보다 더 많은 %d골드가 있었습니다.", bag["money"].GetInt()); getchar();
		printf("End"); getchar();
	}
	else
	{
		printf("하지만, 웬일인지 300골드에는 미치지 못하는 %d골드만 있었습니다.", bag["money"].GetInt()); getchar();
		printf("End"); getchar();
	}

	Data::ShowData();
}

void Stage3::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];
	hero["level"].SetInt(hero["level"].GetInt() + 1);
	hero["location"].SetString("store");

	Data::SaveData();
}