#include "Game.h"

#include "Data.h"
#include "Input.h"

#include "Stage1.h"
#include "Stage2.h"
#include "Stage3.h"
#include "Stage4.h"
#include "Stage5.h"
#include "EndStage.h"

#include <stdio.h>

Game::Game()
	: m_stage(nullptr)
{
}
Game::~Game()
{
	if (m_stage != nullptr)
		delete m_stage;
}

void Game::Run()
{
	Data::LoadData();

	LoadStage();

	if (m_stage)
	{
		if (m_stage->Precondition())
		{
			m_stage->Ready();
			m_stage->Progress();
		}
		else
		{
			printf("���������� ���� ������� Stage�� �����߽��ϴ�.\n");
			Input();
		}
	}
}

void Game::LoadStage()
{
	rapidjson::Value &level = Data::document["���"]["����"];

	if (!level.IsInt())
		return;

	switch (level.GetInt())
	{
	case 0:
		m_stage = new Stage1;
		break;

	case 1:
		m_stage = new Stage2;
		break;

	case 2:
		m_stage = new Stage3;
		break;

	case 3:
		m_stage = new Stage4;
		break;

	case 4:
		m_stage = new Stage5;
		break;

	case 5:
		m_stage = new EndStage;
		break;

	default:
		printf("�߸��� Stage�� �����߰ų�, ���� �������� ���� Stage �Դϴ�.\n"); Input();
		break;
	}
}