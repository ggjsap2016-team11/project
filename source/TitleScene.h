#pragma once
#include "SceneBase.h"
#include "Config.h"

class TitleScene : public SceneBase
{
public:
	TitleScene(){}
	virtual ~TitleScene(){}
	//! 描画
	virtual void Render();
	//! 更新
	virtual void Update();
	//! シーン切り替え先分岐
	void ChangeScene();

	//! Create関数
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