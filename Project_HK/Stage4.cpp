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
	printf("용사는 상점에 들어가, 50골드 짜리 롱소드를 구입하려 했습니다.\n"); getchar();

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
			printf("하지만, 상점 주인은 물건을 팔려 하지 않았습니다.\n"); getchar();
			printf("End\n"); getchar();
		}
		else if (money < 300)
		{
			printf("하지만, 상점 주인은 용사를 기절시키고 돈을 훔쳐갔습니다.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("하지만, 용사는 상점에서 %d골드를 훔쳤고\n마을 경비병들에 의해 감옥에 갇히게 되었습니다.\n", bag["money"].GetInt() - 300); getchar();
			printf("End\n"); getchar();
		}
	}
	else if (find_weapon("long sword"))
	{
		if (money == 250)
		{
			printf("용사는 롱소드를 구입하였고, 남은 소지금은 250골드가 되었습니다\n"); getchar();

			if (weapon.Size() == 1)
			{
				printf("주인장이 서비스로 방패도 주려고 했지만, 용사는 거절하고 길을 나섰습니다.\n"); getchar();
				printf("Stage4 Clear!!\n"); getchar();

				Clear();
			}
			else if (weapon.Size() == 2 && find_weapon("shield"))
			{
				printf("주인장에게 서비스로 방패도 선물받은 용사는 길을 나섰습니다.\n"); getchar();
				printf("Stage4 Clear!!\n"); getchar();

				stageJump = true;
				Clear();
			}
			else
			{
				printf("하지만, 다른 물건을 몰래 훔치려다가 상점 주인에게 들켰습니다.\n"); getchar();
				printf("End\n"); getchar();
			}
		}
		else if (money > 250)
		{
			printf("하지만, 용사는 제 값을 치르지 않고 롱소드를 들고 어디론가 사라졌습니다.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("멍청한 용사는 자신이 속는줄도 모르고 더 비싼값을 주고\n롱소드를 구매했습니다.\n"); getchar();
			printf("End\n"); getchar();
		}
	}
	else if (find_weapon("shield"))
	{
		printf("아니, 이 용사는 왜 주인장이 선물로 주려던 방패를 손에 쥐고 있는걸까요???\n"); getchar();
		printf("Easter Egg\n"); getchar();
	}
	else
	{
		if (money >= 300)
		{
			printf("한참을 둘러보던 용사는, 엉뚱한 물건을 훔치고 달아나 버렸습니다.\n"); getchar();
			printf("End\n"); getchar();
		}
		else
		{
			printf("한참을 둘러보던 용사는, 결국 엉뚱한 물건을 구매해 버리고 말았습니다.\n"); getchar();
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