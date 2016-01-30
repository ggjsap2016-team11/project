#pragma once
class SceneBase
{
public:
	SceneBase() {};
	virtual ~SceneBase(){}
	virtual void Update() = 0;
	virtual void Render() = 0;
private:
	SceneBase(const SceneBase&) {}
	SceneBase& operator=(const SceneBase&) {}
};
