#pragma once
#include <list>
class Observer;

class Subject
{
public:
	virtual ~Subject();
	virtual void UpdateObserver(void);
	virtual void AddObserver(Observer* pObserver);

protected:
	std::list<Observer *> m_observers;
};