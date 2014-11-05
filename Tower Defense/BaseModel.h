#pragma once
#include <list>
#include "IObserver.h"

/*

Base Model for every observable model.
Simply allow to attach, detach and notify observers. 

*/

class BaseModel
{
public:
	BaseModel();
	~BaseModel();
	virtual void Attach(IObserver* o);
	virtual void Detach(IObserver* o);
	virtual void Notify();
private:
	std::list<IObserver*> *observers;
};

