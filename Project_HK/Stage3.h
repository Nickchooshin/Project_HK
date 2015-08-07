#ifndef _STAGE_3_H_
#define _STAGE_3_H_

#include "IStage.h"

class Stage3 : public IStage
{
public:
	Stage3();
	~Stage3();

	void Precondition() override;
	void Ready() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif