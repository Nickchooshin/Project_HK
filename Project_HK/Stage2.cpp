#include "Stage2.h"

#include "Data.h"
#include "Input.h"

Stage2::Stage2()
{
}
Stage2::~Stage2()
{
}

bool Stage2::Precondition()
{
	rapidjson::Value &hero = Data::document["용사"];

	if (hero["이동 여부"] == true)
		return true;

	return false;
}

void Stage2::Ready()
{
	rapidjson::Value &hero = Data::document["용사"];

	if (!hero.HasMember("장소"))
	{
		rapidjson::Value location;
		location = "알 수 없음";

		hero.AddMember("장소", location, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage2::Progress()
{
	printf("용사는 계속해서 길을 걸어가다가...\n"); Input();

	rapidjson::Value &hero = Data::document["용사"];

	if (hero["장소"] == "마을")
	{
		printf("무사히 마을에 도착할 수 있었습니다.\n"); Input();
		printf("Stage2 Clear!!!\n"); Input();

		Clear();
	}
	else if (hero["장소"] == "알 수 없음")
	{
		printf("마을에 도착하지 못한 채 조난당해버렸습니다.\n"); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("본래 목적지인 마을과는 다른, 이상한 곳에 도착해 버렸습니다.\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage2::Clear()
{
	rapidjson::Value &hero = Data::document["용사"];

	hero["레벨"].SetInt(hero["레벨"].GetInt() + 1);

	Data::SaveData();
}