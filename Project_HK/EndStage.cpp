#include "EndStage.h"

#include "Data.h"
#include "Input.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

void EndStage::Precondition()
{
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

	hero["���"].SetString("castle");

	Data::SaveData();
}