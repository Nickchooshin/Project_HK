#include "EndStage.h"

#include "Data.h"

EndStage::EndStage()
{
}
EndStage::~EndStage()
{
}

void EndStage::Precondition()
{
}

void EndStage::Progress()
{
	printf("������ ���� ���� �ɾ�� ����\n"); getchar();
	printf("������ ���� �����߽��ϴ�.\n"); getchar();
	printf("Game Clear\n"); getchar();

	Clear();

	Data::ShowData();
}

void EndStage::Clear()
{
	rapidjson::Value &hero = Data::document["hero"];

	hero["location"].SetString("castle");

	Data::SaveData();
}