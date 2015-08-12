#ifndef _I_STAGE_H_
#define _I_STAGE_H_

class IStage
{
public:
	IStage()
	{}
	virtual ~IStage()
	{}

	virtual bool Precondition() = 0;
	virtual void Ready() = 0;
	virtual void Progress() = 0;
private:
	virtual void Clear() = 0;
};

#endif