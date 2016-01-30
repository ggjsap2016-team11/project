#pragma once
#include "Observer.h"
#include "Subject.h"
#include "DxLib.h"

class Dog : public Subject
{
public:
	Dog(){}
	~Dog()
	{
		Subject::~Subject();
	}

	void hoge()
	{
		Subject::UpdateObserver();
		DrawString(250,240 - 32, "Baw!", GetColor(255, 255, 255));
	}
};

class SmallDog : public Observer
{
public:
	SmallDog(Dog *pDog)
	{
		m_pDog = pDog;
		pDog->AddObserver(this);
	}
	void Update() 
	{
		DrawString(250, 240 , "Can!", GetColor(255, 255, 255));
	}
private:
	Dog *m_pDog;
};