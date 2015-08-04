#include "Stage2.h"

#include "Data.h"

Stage2::Stage2()
{
}
Stage2::~Stage2()
{
}

void Stage2::Precondition()
{
	rapidjson::Value &hero = Data::document["hero"];
	if (!hero.HasMember("location"))
	{
		rapidjson::Value location;
		location = "unknown";

		hero.AddMember("location", location, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage2::Progress()
{
	printf("용사는 계속해서 길을 걸어가다가..."); getchar();

	rapidjson::Value &hero = Data::document["hero"];
	if (hero["location"] == "town")
	{
		printf("무사히 마을에 도착할 수 있었습니다."); getchar();
		printf("Stage2 Clear!!!"); getchar();

		Clear();
	}
	else if (hero["location"] == "unknown")
	{
		printf("마을에 도착하지 못한 채 조난당해버렸습니다."); getchar();
		printf("End"); getchar();
	}
	else
	{
		printf("본래 목적지인 마을과는 다른, 이상한 곳에 도착해 버렸습니다."); getchar();
		printf("End"); getchar();
	}

	Data::ShowData();
}

void Stage2::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];
	hero["level"].SetInt(hero["level"].GetInt() + 1);

	Data::SaveData();
}