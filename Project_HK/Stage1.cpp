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

void Stage1::Ready()
{
}

void Stage1::Progress()
{
	printf("��簡 ��Ÿ�����ϴ�.\n"); getchar();

	rapidjson::Value &hero = Data::document["���"];

	if (hero["�̵� ����"].GetBool())
	{
		printf("���� ������ ���� �ɾ�� �����߽��ϴ�.\n"); getchar();
		printf("Stage1 Clear!!!\n"); getchar();

		Clear();
	}
	else
	{
		printf("������, ���� ���� �� �������ϴ�.\n"); getchar();
		printf("End\n"); getchar();
	}

	Data::ShowData();
}

void Stage1::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["����"].SetInt(hero["����"].GetInt() + 1);

	Data::SaveData();
}