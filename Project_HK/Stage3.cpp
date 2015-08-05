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
	printf("������ ������ ������ ����, ���� ���� �� ì�ܿ� 300��带\n������ ���� Ȯ���� ���ҽ��ϴ�.\n"); getchar();

	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];

	if (bag["money"].GetInt() == 300)
	{
		printf("���� ������ 300��带 �տ� ���, �������� �����ϴ�.\n"); getchar();
		printf("Stage3 Clear!!!\n"); getchar();

		Clear();
	}
	else if (bag["money"].GetInt() == 0)
	{
		printf("�׷���, ���� �ӿ� ���� �� Ǭ�� �������ϴ�.\n"); getchar();
		printf("End\n"); getchar();
	}
	else if (bag["money"].GetInt() > 300)
	{
		printf("������, ���濡�� �׺��� �� ���� %d��尡 �־����ϴ�.\n", bag["money"].GetInt()); getchar();
		printf("End\n"); getchar();
	}
	else
	{
		printf("������, �������� 300��忡�� ��ġ�� ���ϴ� %d��常 �־����ϴ�.\n", bag["money"].GetInt()); getchar();
		printf("End\n"); getchar();
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