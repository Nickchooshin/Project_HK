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
	rapidjson::Value &hero = document["���"];

	printf("------------------------------\n");
	printf("- ��� -\n");
	printf("Level : %d\n", hero["����"]);
	printf("�̵� ���� : %s\n", hero["�̵� ����"].GetBool() ? "����" : "�Ұ���");
	if (hero.HasMember("���"))
	{
		printf("���� ��ġ : %s\n", hero["���"].GetString());
	}
	if (hero.HasMember("����"))
	{
		rapidjson::Value &bag = hero["����"];

		printf("\n");

		printf("- ���� -\n");
		printf("��� : %d", bag["���"].GetInt());

		if (bag.HasMember("���"))
		{
			rapidjson::Value &equipment = bag["���"];

			printf("\n");

			printf("��� : ");
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
				printf("����");
			printf("\n");
		}
	}
	Input();
}

void Data::OpenDataFile()
{
#ifdef _WIN32 || _WIN64
	ShellExecute(NULL, L"open", L"notepad", L"���.txt", NULL, SW_SHOW);
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