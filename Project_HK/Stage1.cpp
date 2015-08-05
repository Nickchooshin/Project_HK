#include "Stage1.h"

#include <stdio.h>

#include "Data.h"

Stage1::Stage1()
{
}
Stage1::~Stage1()
{
}

void Stage1::Precondition()
{
}

void Stage1::Progress()
{
	printf("용사가 나타났습니다.\n"); getchar();

	rapidjson::Value &hero = Data::document["hero"];

	if (hero["movable"].GetBool())
	{
		printf("용사는 마을을 향해 걸어가기 시작했습니다.\n"); getchar();
		printf("Stage1 Clear!!!\n"); getchar();

		Clear();
	}
	else
	{
		printf("하지만, 용사는 걸을 수 없었습니다.\n"); getchar();
		printf("End\n"); getchar();
	}

	Data::ShowData();
}

void Stage1::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];

	hero["level"].SetInt(hero["level"].GetInt() + 1);

	Data::SaveData();
}