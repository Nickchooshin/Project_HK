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
	printf("���� ������ ��, 50��� ¥�� �ռҵ带 �����Ϸ� �߽��ϴ�.\n"); getchar();

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
			printf("������, ���� �������� %d��带 ���ư�\n���� ��񺴵鿡 ���� ������ ������ �Ǿ����ϴ�.\n", bag["���"].GetInt() - 300); getchar();
			printf("End\n"); getchar();
		}
	}
	else if (find_weapon("�ռҵ�"))
	{
		if (money == 250)
		{
			printf("���� �ռҵ带 �����Ͽ���, ���� �������� 250��尡 �Ǿ����ϴ�\n"); getchar();

			if (equipment.Size() == 1)
			{
				printf("�������� ���񽺷� ���е� �ַ��� ������, ���� �����ϰ� ���� �������ϴ�.\n"); getchar();
				printf("Stage4 Clear!!\n"); getchar();

				Clear();
			}
			else if (equipment.Size() == 2 && find_weapon("����"))
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
	else if (find_weapon("����"))
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