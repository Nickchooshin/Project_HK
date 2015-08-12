#include "Stage5.h"

#include "Data.h"
#include "Input.h"

Stage5::Stage5()
{
}
Stage5::~Stage5()
{
}

bool Stage5::Precondition()
{
	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];
	rapidjson::Value &equipment = bag["���"];
	auto find_equipment = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (hero["�̵� ����"] == true &&
		(hero["���"] == "����" || hero["���"] == "��") &&
		bag["���"] == 250 &&
		find_equipment("�ռҵ�"))
	{
		return true;
	}

	return false;
}

void Stage5::Ready()
{
	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];

	if (hero["���"] != "��")
	{
		hero["���"].SetString("��");

		Data::SaveData();
	}
}

void Stage5::Progress()
{
	printf("������ ���� ���� �ɾ�� ����\n"); Input();

	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];
	rapidjson::Value &equipment = bag["���"];

	auto find_equipment = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (!find_equipment("����"))
	{
		printf("���� ������ ȣ�Ǹ� ������ ſ����\n���а� ��� ������ ���ƿ��� ȭ���� �°� �׾���.\n"); Input();
		printf("�ð��� �ǵ��� ���� �ִٸ�, �׶� ���и� �޾��� ���̴�.\n"); Input();
		printf("End\n"); Input();
	}
	else
	{
		printf("�ڽ��� �տ� ��� �� ������ ���а� ����ִٴ� ���� ��ġë��.\n"); Input();
		printf("�� ����!!!\n"); Input();
		printf("���� ������ ���ƿ��� ȭ���� �°� �׾���.\n"); Input();
		printf("�и� '���и� ��� �� ����� ������'�� �ǹ����� ǰ����...\n"); Input();
		printf("End\n"); Input();
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage5::Clear()
{
}