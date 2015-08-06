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

	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];
	rapidjson::Value &equipment = bag["equipment"];

	auto find_weapon = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (!find_weapon("shield"))
	{
		printf("���� ������ ȣ�Ǹ� ������ ſ����\n���а� ��� ������ ���ƿ��� ȭ���� �°� �׾���.\n"); getchar();
		printf("�ð��� �ǵ��� ���� �ִٸ�, �׶� ���и� �޾��� ���̴�.\n"); getchar();
		printf("End\n"); getchar();
	}
	else
	{
		printf("�ڽ��� �տ� ��� �� ������ ���а� ����ִٴ� ���� ��ġë��.\n"); getchar();
		printf("�� ����!!!\n"); getchar();
		printf("���� ������ ���ƿ��� ȭ���� �°� �׾���.\n"); getchar();
		printf("�и� '���и� ��� �� ����� ������'�� �ǹ����� ǰ����...\n"); getchar();
		printf("End\n"); getchar();
	}

	Data::ShowData();
}

void Stage5::Clear()
{
}