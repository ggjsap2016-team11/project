#pragma once
template <typename _T>
class Singleton {

protected:
	Singleton() {};
	virtual ~Singleton() {};
	Singleton(const Singleton& r) = delete;
	Singleton& operator=(const Singleton& r) = delete;

public:
	static _T* sharedInstanse() {
		static _T inst;
		return &inst;
	};
};