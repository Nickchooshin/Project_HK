#include "EndStage.h"

#include "Data.h"
#include "Input.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

bool EndStage::Precondition()
{
	rapidjson::Value &hero = Data::document["���"];
	rapidjson::Value &bag = hero["����"];
	rapidjson::Value &equipment = bag["���"];
	auto find_equipment = [&equipment](std::string name)->bool
	{
		for (int i = 0; i < equipment.Size(); i++)
		{
			if (equipment[i].GetString() == name)
				return true;
		}

		return false;
	};

	if (hero["�̵� ����"] == true &&
		hero["���"] == "����" &&
		bag["���"] == 250 &&
		find_equipment("�ռҵ�") &&
		find_equipment("����"))
	{
		return true;
	}

	return false;
}

void EndStage::Ready()
{
}

void EndStage::Progress()
{
	printf("������ ���� ���� �ɾ�� ����\n"); Input();
	printf("������ ���� �����߽��ϴ�.\n"); Input();
	printf("Game Clear\n"); Input();

	Clear();

	Data::ShowData();
}

void EndStage::Clear()
{
	rapidjson::Value &hero = Data::document["���"];

	hero["���"].SetString("��");

	Data::SaveData();
}