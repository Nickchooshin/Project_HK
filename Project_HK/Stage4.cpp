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
	rapidjson::Value &hero = Data::document["용사"];
	rapidjson::Value &bag = hero["가방"];

	if (!bag.HasMember("장비"))
	{
		rapidjson::Value equipment;
		equipment.SetArray();

		bag.AddMember("장비", equipment, Data::document.GetAllocator());

		Data::SaveData();
	}
}

void Stage4::Progress()
{
	printf("용사는 상점에 들어가, 50골드 짜리 롱소드를 구입하려 했습니다.\n"); Input();

	rapidjson::Value &hero = Data::document["용사"];
	rapidjson::Value &bag = hero["가방"];
	rapidjson::Value &equipment = bag["장비"];

	int money = bag["골드"].GetInt();
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
			printf("하지만, 상점 주인은 물건을 팔려 하지 않았습니다.\n"); Input();
			printf("End\n"); Input();
		}
		else if (money < 300)
		{
			printf("하지만, 상점 주인은 용사를 기절시키고 돈을 훔쳐갔습니다.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("하지만, 용사는 상점에서 %d골드를 훔쳤고\n마을 경비병들에 의해 감옥에 갇히게 되었습니다.\n", bag["골드"].GetInt() - 300); Input();
			printf("End\n"); Input();
		}
	}
	else if (find_weapon("롱소드"))
	{
		if (money == 250)
		{
			printf("용사는 롱소드를 구입하였고, 남은 소지금은 250골드가 되었습니다\n"); Input();

			if (equipment.Size() == 1)
			{
				printf("주인장이 서비스로 방패도 주려고 했지만, 용사는 거절하고 길을 나섰습니다.\n"); Input();
				printf("Stage4 Clear!!\n"); Input();

				Clear();
			}
			else if (equipment.Size() == 2 && find_weapon("방패"))
			{
				printf("주인장에게 서비스로 방패도 선물받은 용사는 길을 나섰습니다.\n"); Input();
				printf("Stage4 Clear!!\n"); Input();

				stageJump = true;
				Clear();
			}
			else
			{
				printf("하지만, 다른 물건을 몰래 훔치려다가 상점 주인에게 들켰습니다.\n"); Input();
				printf("End\n"); Input();
			}
		}
		else if (money > 250)
		{
			printf("하지만, 용사는 제 값을 치르지 않고 롱소드를 들고 어디론가 사라졌습니다.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("멍청한 용사는 자신이 속는줄도 모르고 더 비싼값을 주고\n롱소드를 구매했습니다.\n"); Input();
			printf("End\n"); Input();
		}
	}
	else if (find_weapon("방패"))
	{
		printf("아니, 이 용사는 왜 주인장이 선물로 주려던 방패를 손에 쥐고 있는걸까요???\n"); Input();
		printf("Easter Egg\n"); Input();
	}
	else
	{
		if (money >= 300)
		{
			printf("한참을 둘러보던 용사는, 엉뚱한 물건을 훔치고 달아나 버렸습니다.\n"); Input();
			printf("End\n"); Input();
		}
		else
		{
			printf("한참을 둘러보던 용사는, 결국 엉뚱한 물건을 구매해 버리고 말았습니다.\n"); Input();
			printf("End\n"); Input();
		}
	}

	Data::ShowData();
	Data::OpenDataFile();
}

void Stage4::Clear()
{
	rapidjson::Value &hero = Data::document["용사"];

	if (stageJump)
		hero["레벨"].SetInt(hero["레벨"].GetInt() + 2);
	else
		hero["레벨"].SetInt(hero["레벨"].GetInt() + 1);
	hero["장소"].SetString("마을");

	Data::SaveData();
}