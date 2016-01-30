#pragma once
#include "SceneBase.h"
#include "Config.h"

class TitleScene : public SceneBase
{
public:
	TitleScene(){}
	virtual ~TitleScene(){}
	//! �`��
	virtual void Render();
	//! �X�V
	virtual void Update();
	//! �V�[���؂�ւ��敪��
	void ChangeScene();

	//! Create�֐�
	static SceneBase* Create() {
		SceneBase* p = new TitleScene;
		return p;
	}

private:
	enum eMenuMode : int {
		kStart = 0,
		kEnd,
		kMode_All
	}m_eMode;
	
};