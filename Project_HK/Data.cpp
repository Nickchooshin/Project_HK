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

	handle = _findfirst("./hero.json", &fd);
	if (handle == -1)
	{
		InitData();
		return;
	}

	char buffer[65536];
	FILE *file = fopen("hero.json", "r");

	rapidjson::FileReadStream is(file, buffer, sizeof(buffer));
	document.ParseStream(is);
	fclose(file);
}

void Data::SaveData()
{
	FILE *file = fopen("hero.json", "w");
	char buffer[65536];

	rapidjson::FileWriteStream os(file, buffer, sizeof(buffer));
	rapidjson::PrettyWriter<rapidjson::FileWriteStream> writer(os);
	document.Accept(writer);
	fclose(file);
}

void Data::ShowData()
{
	rapidjson::Value &hero = document["hero"];

	printf("\n");

	printf("------------------------------\n");
	printf("- 용사 -\n");
	printf("Level : %d\n", hero["level"]);
	printf("이동 여부 : %s\n", hero["movable"].GetBool() ? "가능" : "불가능");
	if (hero.HasMember("location"))
	{
		printf("현재 위치 : %s\n", hero["location"].GetString());
	}
	if (hero.HasMember("bag"))
	{
		rapidjson::Value &bag = hero["bag"];

		printf("\n");

		printf("- 가방 -\n");
		printf("골드 : %d", bag["money"].GetInt());
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

	hero.AddMember("level", level, document.GetAllocator());
	hero.AddMember("movable", movable, document.GetAllocator());

	document.AddMember("hero", hero, document.GetAllocator());

	SaveData();
}