#include "Subject.h"
#include "Observer.h"

Subject::~Subject(void)
{
	std::list<Observer *>::iterator it;
	for (it = m_observers.begin(); it != m_observers.end(); it++)
	{
		(*it)->SetObject(NULL);
	}
}

void Subject::UpdateObserver(void)
{
	std::list<Observer *>::iterator it;
	for (it = m_observers.begin(); it != m_observers.end(); it++)
	{
		(*it)->Update();
	}
}

void Subject::AddObserver(Observer* pObserver)
{
	m_observers.push_back(pObserver);
	pObserver->SetObject(this);
}