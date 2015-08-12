#ifndef _STAGE_2_H_
#define _STAGE_2_H_

#include "IStage.h"

class Stage2 : public IStage
{
public:
	Stage2();
	~Stage2();

	bool Precondition() override;
	void Ready() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif