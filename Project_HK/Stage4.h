#ifndef _STAGE_4_H_
#define _STAGE_4_H_

#include "IStage.h"

class Stage4 : public IStage
{
private:
	bool stageJump;

public:
	Stage4();
	~Stage4();

	bool Precondition() override;
	void Ready() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif