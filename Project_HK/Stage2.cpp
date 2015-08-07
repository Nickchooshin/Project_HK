#include "Stage2.h"

#include "Data.h"
#include "Input.h"

Stage2::Stage2()
{
}
Stage2::~Stage2()
{
}

void Stage2::Precondition()
{
}

void Stage2::Ready()
{
	rapidjson::Value &hero = Data::document["���"];

	if (!hero.HasMember("���"))
	{
		rapidjson::Value location;
		location = "�� �� ����";

		hero.AddMember("���", location, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage2::Progress()
{
	printf("���� ����ؼ� ���� �ɾ�ٰ�...\n"); Input();

	rapidjson::Value &hero = Data::document["���"];

	if (hero["���"] == "����")
	{
		printf("������ ������ ������ �� �־����ϴ�.\n"); Input();
		printf("Stage2 Clear!!!\n"); Input();

		Clear();
	}
	else if (hero["���"] == "�� �� ����")
	{
		printf("������ �������� ���� ä �������ع��Ƚ��ϴ�.\n"); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("���� �������� �������� �ٸ�, �̻��� ���� ������ ���Ƚ��ϴ�.\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage2::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["����"].SetInt(hero["����"].GetInt() + 1);

	Data::SaveData();
}