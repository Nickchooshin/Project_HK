#include "Data.h"

#include <stdio.h>
#include <io.h>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>

rapidjson::Document Data::document;

void Data::LoadData()
{
	_finddata_t fd;
	long handle;
	int result = 1;

	handle = _findfirst("용사.txt", &fd);
	if (handle == -1)
	{
		InitData();
		return;
	}

	char buffer[65536];
	FILE *file = fopen("용사.txt", "r");

	rapidjson::FileReadStream is(file, buffer, sizeof(buffer));
	document.ParseStream(is);
	fclose(file);
}

void Data::SaveData()
{
	FILE *file = fopen("용사.txt", "w");
	char buffer[65536];

	rapidjson::FileWriteStream os(file, buffer, sizeof(buffer));
	rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
	document.Accept(writer);
	fclose(file);
}

void Data::ShowData()
{
	rapidjson::Value &hero = document["용사"];

	printf("------------------------------\n");
	printf("- 용사 -\n");
	printf("Level : %d\n", hero["레벨"]);
	printf("이동 여부 : %s\n", hero["이동 여부"].GetBool() ? "가능" : "불가능");
	if (hero.HasMember("장소"))
	{
		printf("현재 위치 : %s\n", hero["장소"].GetString());
	}
	if (hero.HasMember("가방"))
	{
		rapidjson::Value &bag = hero["가방"];

		printf("\n");

		printf("- 가방 -\n");
		printf("골드 : %d", bag["골드"].GetInt());

		if (bag.HasMember("장비"))
		{
			rapidjson::Value &equipment = bag["장비"];

			printf("\n");

			printf("장비 : ");
			if (equipment.Size())
			{
				for (int i = 0; i < equipment.Size(); i++)
				{
					printf("%s", equipment[i].GetString());

					if (i + 1 < equipment.Size())
						printf(", ");
				}
			}
			else
				printf("없음");
			printf("\n");
		}
	}
	getchar();
}

void Data::InitData()
{
	document.SetObject();

	rapidjson::Value hero;
	hero.SetObject();

	rapidjson::Value level;
	level = 0;

	rapidjson::Value movable;
	movable = false;

	hero.AddMember("레벨", level, document.GetAllocator());
	hero.AddMember("이동 여부", movable, document.GetAllocator());

	document.AddMember("용사", hero, document.GetAllocator());

	SaveData();
}