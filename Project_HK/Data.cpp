#include "Data.h"

#include <stdio.h>
#include "../rapidjson/include/rapidjson/document.h"
#include "../rapidjson/include/rapidjson/prettywriter.h"
#include "../rapidjson/include/rapidjson/stringbuffer.h"
#include "../rapidjson/include/rapidjson/filereadstream.h"
#include "../rapidjson/include/rapidjson/filewritestream.h"

#include "Input.h"

#if defined(_WIN32) || defined(_WIN64)
#include <io.h>
#include <Windows.h>
#elif defined(__linux__)
#include <dirent.h>
//#elif TARGET_OS_MAC
#endif

rapidjson::Document Data::document;

void PrintValue(rapidjson::Value &value);

void Data::LoadData()
{
#if defined(_WIN32) || defined(_WIN64)
	_finddata_t fd;
	long handle;
	int result = 1;

	handle = _findfirst("용사.txt", &fd);
	if (handle == -1)
	{
		InitData();
		return;
	}
#elif defined(__linux__)
	dirent **namelist;
	int n;

	n = scandir(".", &namelist, 0, alphasort);

	if (n < 0)
	{
		InitData();
		return;
	}

	int i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(namelist[i]->d_name, "용사.txt") == 0)
		{
			free(namelist[n]);
			break;
		}
		free(namelist[n]);
	}
	free(namelist);

	if (i == n)
	{
		InitData();
		return;
	}
#endif

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
#if defined(_WIN32) || defined(_WIN64)
	ShellExecute(nullptr, L"open", L"notepad", L"용사.txt", nullptr, SW_SHOW);
#else
	//_popen("vi 용사.txt", "w");
	system("vi 용사.txt");
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
		printf("%d", value.GetInt());
	}
	else if (type == rapidjson::Type::kStringType)
	{
		printf("%s", value.GetString());
	}
	else if (type == rapidjson::Type::kTrueType)
	{
		printf("가능");
	}
	else if (type == rapidjson::Type::kFalseType)
	{
		printf("불가능");
	}
	else if (type == rapidjson::Type::kArrayType)
	{
		for (int i = 0; i < value.Size(); i++)
		{
			PrintValue(value[i]);
			if (i < value.Size() - 1)
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
			{
				printf("\n- %s -\n", name.c_str());
				PrintValue(member);
			}
			else
			{
				printf("%s : ", name.c_str());
				PrintValue(member);
				printf("\n");
			}
		}
	}
	else
	{
		printf("Null");
	}
}
