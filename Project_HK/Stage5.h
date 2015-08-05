#ifndef _STAGE_5_H_
#define _STAGE_5_H_

#include "IStage.h"

class Stage5 : public IStage
{
public:
	Stage5();
	~Stage5();

	void Precondition() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif