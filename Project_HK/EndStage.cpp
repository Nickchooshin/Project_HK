#include "EndStage.h"

#include "Data.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

void EndStage::Precondition()
{
}

void EndStage::Progress()
{
	printf("마을을 나서 숲을 걸어가던 용사는\n"); getchar();
	printf("마왕의 성에 도착했습니다.\n"); getchar();
	printf("Game Clear\n"); getchar();

	Clear();

	Data::ShowData();
}

void EndStage::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];

	hero["location"].SetString("castle");

	Data::SaveData();
}