#ifndef _STAGE_1_H_
#define _STAGE_1_H_

#include "IStage.h"

class Stage1 : public IStage
{
public:
	Stage1();
	~Stage1();

	bool Precondition() override;
	void Ready() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif