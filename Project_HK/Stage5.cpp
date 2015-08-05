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
	printf("������ ���� ���� �ɾ�� ����\n"); getchar();
	printf("���� ������ ȣ�Ǹ� ������ ſ����\n���а� ��� ������ ���ƿ��� ȭ���� �°� �׾���.\n"); getchar();
	printf("�ð��� �ǵ��� ���� �ִٸ�, �׶� ���и� �޾��� ���̴�.\n"); getchar();
	printf("End\n"); getchar();

	Data::ShowData();
}

void Stage5::Clear()
{
}