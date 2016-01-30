#pragma once
class Subject;

class Observer
{
public:
	virtual ~Observer() {}
	virtual void Update(void) = 0;

	void SetObject(Subject* pSubject)
	{
		m_pSubject = pSubject;
	}

protected:
	Subject *m_pSubject;
};