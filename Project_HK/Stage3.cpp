#include "Stage3.h"

#include "Data.h"
#include "Input.h"

Stage3::Stage3()
{
}
Stage3::~Stage3()
{
}

void Stage3::Precondition()
{
}

void Stage3::Ready()
{
	rapidjson::Value &hero = Data::document["���"];

	if (!hero.HasMember("����"))
	{
		rapidjson::Value bag;
		bag.SetObject();

		rapidjson::Value money;
		money = 0;

		bag.AddMember("���", money, Data::document.GetAllocator());
		hero.AddMember("����", bag, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage3::Progress()
{
	printf("������ ������ ������ ����, ���� ���� �� ì�ܿ� 300��带\n������ ���� Ȯ���� ���ҽ��ϴ�.\n"); Input();

	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];

	if (bag["���"].GetInt() == 300)
	{
		printf("���� ������ 300��带 �տ� ���, �������� �����ϴ�.\n"); Input();
		printf("Stage3 Clear!!!\n"); Input();

		Clear();
	}
	else if (bag["���"].GetInt() == 0)
	{
		printf("�׷���, ���� �ӿ� ���� �� Ǭ�� �������ϴ�.\n"); Input();
		printf("End\n"); Input();
	}
	else if (bag["���"].GetInt() > 300)
	{
		printf("������, ���濡�� �׺��� �� ���� %d��尡 �־����ϴ�.\n", bag["���"].GetInt()); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("������, �������� 300��忡�� ��ġ�� ���ϴ� %d��常 �־����ϴ�.\n", bag["���"].GetInt()); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage3::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["����"].SetInt(hero["����"].GetInt() + 1);
	hero["���"].SetString("����");

	Data::SaveData();
}