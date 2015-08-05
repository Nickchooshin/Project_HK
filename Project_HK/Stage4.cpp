#include "Stage4.h"

#include "Data.h"

Stage4::Stage4()
	: stageJump(false)
{
}
Stage4::~Stage4()
{
}

void Stage4::Precondition()
{
	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];

	if (!bag.HasMember("weapon"))
	{
		rapidjson::Value weapon;
		weapon.SetArray();

		bag.AddMember("weapon", weapon, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage4::Progress()
{
	printf("���� ������ ��, 50��� ¥�� �ռҵ带 �����Ϸ� �߽��ϴ�.\n"); getchar();

	rapidjson::Value &hero = Data::document["hero"];
	rapidjson::Value &bag = hero["bag"];
	rapidjson::Value &weapon = bag["weapon"];

	int money = bag["money"].GetInt();
	auto find_weapon = [&weapon](std::string name)->bool
	{
		for (int i = 0; i < weapon.Size(); i++)
		{
			if (weapon[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (weapon.Size() == 0)
	{
		if (money == 300)
		{
			printf("������, ���� ������ ������ �ȷ� ���� �ʾҽ��ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
		else if (money < 300)
		{
			printf("������, ���� ������ ��縦 ������Ű�� ���� ���İ����ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("������, ���� �������� %d��带 ���ư�\n���� ��񺴵鿡 ���� ������ ������ �Ǿ����ϴ�.\n", bag["money"].GetInt() - 300); getchar();
			printf("End\n"); getchar();
		}
	}
	else if (find_weapon("long sword"))
	{
		if (money == 250)
		{
			printf("���� �ռҵ带 �����Ͽ���, ���� �������� 250��尡 �Ǿ����ϴ�\n"); getchar();

			if (weapon.Size() == 1)
			{
				printf("�������� ���񽺷� ���е� �ַ��� ������, ���� �����ϰ� ���� �������ϴ�.\n"); getchar();
				printf("Stage4 Clear!!\n"); getchar();

				Clear();
			}
			else if (weapon.Size() == 2 && find_weapon("shield"))
			{
				printf("�����忡�� ���񽺷� ���е� �������� ���� ���� �������ϴ�.\n"); getchar();
				printf("Stage4 Clear!!\n"); getchar();

				stageJump = true;
				Clear();
			}
			else
			{
				printf("������, �ٸ� ������ ���� ��ġ���ٰ� ���� ���ο��� ���׽��ϴ�.\n"); getchar();
				printf("End\n"); getchar();
			}
		}
		else if (money > 250)
		{
			printf("������, ���� �� ���� ġ���� �ʰ� �ռҵ带 ��� ���а� ��������ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("��û�� ���� �ڽ��� �Ӵ��ٵ� �𸣰� �� ��Ѱ��� �ְ�\n�ռҵ带 �����߽��ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
	}
	else if (find_weapon("shield"))
	{
		printf("�ƴ�, �� ���� �� �������� ������ �ַ��� ���и� �տ� ��� �ִ°ɱ��???\n"); getchar();
		printf("Easter Egg\n"); getchar();
	}
	else
	{
		if (money >= 300)
		{
			printf("������ �ѷ����� ����, ������ ������ ��ġ�� �޾Ƴ� ���Ƚ��ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("������ �ѷ����� ����, �ᱹ ������ ������ ������ ������ ���ҽ��ϴ�.\n"); getchar();
			printf("End\n"); getchar();
		}
	}

	Data::ShowData();
}

void Stage4::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];

	if (stageJump)
		hero["level"].SetInt(hero["level"].GetInt() + 2);
	else
		hero["level"].SetInt(hero["level"].GetInt() + 1);
	hero["location"].SetString("town");

	Data::SaveData();
}