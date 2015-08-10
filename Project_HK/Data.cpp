#include "Data.h"

#include <stdio.h>
#include <io.h>
#include <rapidjson/document.h>
#include <rapidjson/prettywriter.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/filewritestream.h>

#include "Input.h"

#ifdef _WIN32 || _WIN64
#include <Windows.h>
//#elif __linux__ 
//#elif TARGET_OS_MAC
#endif

rapidjson::Document Data::document;

void PrintValue(rapidjson::Value &value);

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
	printf("------------------------------");
	PrintValue(document);

	Input();
}

void Data::OpenDataFile()
{
#ifdef _WIN32 || _WIN64
	ShellExecute(nullptr, L"open", L"notepad", L"용사.txt", nullptr, SW_SHOW);
#else
	//_popen("notepad 용사.txt", "w");
	system("notepad 용사.txt");
#endif
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

void PrintValue(rapidjson::Value &value)
{
	rapidjson::Type type = value.GetType();

	if (type == rapidjson::Type::kNumberType)
	{
		printf("%d\n", value.GetInt());
	}
	else if (type == rapidjson::Type::kStringType)
	{
		printf("%s\n", value.GetString());
	}
	else if (type == rapidjson::Type::kTrueType)
	{
		printf("가능\n");
	}
	else if (type == rapidjson::Type::kFalseType)
	{
		printf("불가능\n");
	}
	else if (type == rapidjson::Type::kArrayType)
	{
		for (int i = 0; i < value.Size(); i++)
		{
			PrintValue(value[i]);
			printf(", ");
		}
		printf("\n");
	}
	else if (type == rapidjson::Type::kObjectType)
	{
		for (auto iter = value.MemberBegin(); iter != value.MemberEnd(); iter++)
		{
			rapidjson::Value &member = iter->value;
			std::string name = iter->name.GetString();

			if (member.GetType() == rapidjson::Type::kObjectType || member.GetType() == rapidjson::Type::kArrayType)
				printf("\n- %s -\n", name.c_str());
			else
				printf("%s : ", name.c_str());
			PrintValue(member);
		}
	}
	else
	{
		printf("Null\n");
	}
}