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
	printf("상점 주인의 호의를 거절한 탓인지\n방패가 없어서 수없이 날아오는 화살을 맞고 죽었다.\n"); getchar();
	printf("시간을 되돌릴 수만 있다면, 그때 방패를 받았을 것이다.\n"); getchar();
	printf("End\n"); getchar();

	Data::ShowData();
}

void Stage5::Clear()
{
}