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

	handle = _findfirst("���.txt", &fd);
	if (handle == -1)
	{
		InitData();
		return;
	}

	char buffer[65536];
	FILE *file = fopen("���.txt", "r");

	rapidjson::FileReadStream is(file, buffer, sizeof(buffer));
	document.ParseStream(is);
	fclose(file);
}

void Data::SaveData()
{
	FILE *file = fopen("���.txt", "w");
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
	ShellExecute(nullptr, L"open", L"notepad", L"���.txt", nullptr, SW_SHOW);
#else
	//_popen("notepad ���.txt", "w");
	system("notepad ���.txt");
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

	hero.AddMember("����", level, document.GetAllocator());
	hero.AddMember("�̵� ����", movable, document.GetAllocator());

	document.AddMember("���", hero, document.GetAllocator());

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
		printf("����\n");
	}
	else if (type == rapidjson::Type::kFalseType)
	{
		printf("�Ұ���\n");
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