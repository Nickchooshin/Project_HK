#include "Stage2.h"

#include "Data.h"

Stage2::Stage2()
{
}
Stage2::~Stage2()
{
}

void Stage2::Precondition()
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
	printf("���� ����ؼ� ���� �ɾ�ٰ�...\n"); getchar();

	rapidjson::Value &hero = Data::document["���"];

	if (hero["���"] == "����")
	{
		printf("������ ������ ������ �� �־����ϴ�.\n"); getchar();
		printf("Stage2 Clear!!!\n"); getchar();

		Clear();
	}
	else if (hero["���"] == "�� �� ����")
	{
		printf("������ �������� ���� ä �������ع��Ƚ��ϴ�.\n"); getchar();
		printf("End\n"); getchar();
	}
	else
	{
		printf("���� �������� �������� �ٸ�, �̻��� ���� ������ ���Ƚ��ϴ�.\n"); getchar();
		printf("End\n"); getchar();
	}

	Data::ShowData();
}

void Stage2::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["����"].SetInt(hero["����"].GetInt() + 1);

	Data::SaveData();
}