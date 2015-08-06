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
	rapidjson::Value &hero = Data::document["hero"];

	if (!hero.HasMember("location"))
	{
		rapidjson::Value location;
		location = "unknown";

		hero.AddMember("location", location, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage2::Progress()
{
	printf("���� ����ؼ� ���� �ɾ�ٰ�...\n"); getchar();

	rapidjson::Value &hero = Data::document["hero"];

	if (hero["location"] == "town")
	{
		printf("������ ������ ������ �� �־����ϴ�.\n"); getchar();
		printf("Stage2 Clear!!!\n"); getchar();

		Clear();
	}
	else if (hero["location"] == "unknown")
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
	rapidjson::Value &hero = Data::document["hero"];

	hero["level"].SetInt(hero["level"].GetInt() + 1);

	Data::SaveData();
}