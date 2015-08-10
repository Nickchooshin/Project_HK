#include "Stage1.h"

#include "Data.h"
#include "Input.h"

Stage1::Stage1()
{
}
Stage1::~Stage1()
{
}

void Stage1::Precondition()
{
}

void Stage1::Ready()
{
}

void Stage1::Progress()
{
	printf("용사가 나타났습니다.\n"); Input();

	rapidjson::Value &hero = Data::document["용사"];

	if (hero["이동 여부"] == true)
	{
		printf("용사는 마을을 향해 걸어가기 시작했습니다.\n"); Input();
		printf("Stage1 Clear!!!\n"); Input();

		Clear();
	}
	else
	{
		printf("하지만, 용사는 걸을 수 없었습니다.\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
}

void Stage1::Clear()
{
	rapidjson::Value &hero = Data::document["용사"];

	hero["레벨"].SetInt(hero["레벨"].GetInt() + 1);

	Data::SaveData();
}