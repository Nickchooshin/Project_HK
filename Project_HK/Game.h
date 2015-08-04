#ifndef _GAME_H_
#define _GAME_H_

class IStage;

class Game
{
private:
	IStage *m_stage;

public:
	Game();
	~Game();

	void Run();
private:
	void LoadStage();
};

#endif