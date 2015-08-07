#include "EndStage.h"

#include "Data.h"
#include "Input.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

void EndStage::Precondition()
{
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

	hero["장소"].SetString("castle");

	Data::SaveData();
}