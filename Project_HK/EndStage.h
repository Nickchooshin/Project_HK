#ifndef _END_STAGE_H_
#define _END_STAGE_H_

#include "IStage.h"

class EndStage : public IStage
{
public:
	EndStage();
	~EndStage();

	void Precondition() override;
	void Progress() override;
private:
	void Clear() override;
};

#endif