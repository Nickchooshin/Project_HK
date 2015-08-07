#include "Stage4.h"

#include "Data.h"
#include "Input.h"

Stage4::Stage4()
	: stageJump(false)
{
}
Stage4::~Stage4()
{
}

void Stage4::Precondition()
{
}

void Stage4::Ready()
{
	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];

	if (!bag.HasMember("���"))
	{
		rapidjson::Value equipment;
		equipment.SetArray();

		bag.AddMember("���", equipment, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage4::Progress()
{
	printf("���� ������ ��, 50��� ¥�� �ռҵ带 �����Ϸ� �߽��ϴ�.\n"); Input();

	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];
	rapidjson::Value &equipment = bag["���"];

	int money = bag["���"].GetInt();
	auto find_weapon = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (equipment.Size() == 0)
	{
		if (money == 300)
		{
			printf("������, ���� ������ ������ �ȷ� ���� �ʾҽ��ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
		else if (money < 300)
		{
			printf("������, ���� ������ ��縦 ������Ű�� ���� ���İ����ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("������, ���� �������� %d��带 ���ư�\n���� ��񺴵鿡 ���� ������ ������ �Ǿ����ϴ�.\n", bag["���"].GetInt() - 300); Input();
			printf("End\n"); Input();
		}
	}
	else if (find_weapon("�ռҵ�"))
	{
		if (money == 250)
		{
			printf("���� �ռҵ带 �����Ͽ���, ���� �������� 250��尡 �Ǿ����ϴ�\n"); Input();

			if (equipment.Size() == 1)
			{
				printf("�������� ���񽺷� ���е� �ַ��� ������, ���� �����ϰ� ���� �������ϴ�.\n"); Input();
				printf("Stage4 Clear!!\n"); Input();

				Clear();
			}
			else if (equipment.Size() == 2 && find_weapon("����"))
			{
				printf("�����忡�� ���񽺷� ���е� �������� ���� ���� �������ϴ�.\n"); Input();
				printf("Stage4 Clear!!\n"); Input();

				stageJump = true;
				Clear();
			}
			else
			{
				printf("������, �ٸ� ������ ���� ��ġ���ٰ� ���� ���ο��� ���׽��ϴ�.\n"); Input();
				printf("End\n"); Input();
			}
		}
		else if (money > 250)
		{
			printf("������, ���� �� ���� ġ���� �ʰ� �ռҵ带 ��� ���а� ��������ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("��û�� ���� �ڽ��� �Ӵ��ٵ� �𸣰� �� ��Ѱ��� �ְ�\n�ռҵ带 �����߽��ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
	}
	else if (find_weapon("����"))
	{
		printf("�ƴ�, �� ���� �� �������� ������ �ַ��� ���и� �տ� ��� �ִ°ɱ��???\n"); Input();
		printf("Easter Egg\n"); Input();
	}
	else
	{
		if (money >= 300)
		{
			printf("������ �ѷ����� ����, ������ ������ ��ġ�� �޾Ƴ� ���Ƚ��ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("������ �ѷ����� ����, �ᱹ ������ ������ ������ ������ ���ҽ��ϴ�.\n"); Input();
			printf("End\n"); Input();
		}
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage4::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	if (stageJump)
		hero["����"].SetInt(hero["����"].GetInt() + 2);
	else
		hero["����"].SetInt(hero["����"].GetInt() + 1);
	hero["���"].SetString("����");

	Data::SaveData();
}