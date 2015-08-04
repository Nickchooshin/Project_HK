#ifndef _STAGE_2_H_
#define _STAGE_2_H_

#include "IStage.h"

class Stage2 : public IStage
{
public:
	Stage2();
	~Stage2();

	void Precondition() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif