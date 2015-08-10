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
	printf("��簡 ��Ÿ�����ϴ�.\n"); Input();

	rapidjson::Value &hero = Data::document["���"];

	if (hero["�̵� ����"] == true)
	{
		printf("���� ������ ���� �ɾ�� �����߽��ϴ�.\n"); Input();
		printf("Stage1 Clear!!!\n"); Input();

		Clear();
	}
	else
	{
		printf("������, ���� ���� �� �������ϴ�.\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
}

void Stage1::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["����"].SetInt(hero["����"].GetInt() + 1);

	Data::SaveData();
}