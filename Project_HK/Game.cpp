#include "Game.h"

#include "Data.h"
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
		m_stage->Precondition();
		m_stage->Progress();
	}
}

void Game::LoadStage()
{
	int level = Data::document["hero"]["level"].GetInt();

	switch (level)
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

	case 5 :
		m_stage = new EndStage;
		break;

	default:
		printf("�߸��� Stage�� �����߰ų�, ���� �������� ���� Stage �Դϴ�.\n"); getchar();
		break;
	}
}