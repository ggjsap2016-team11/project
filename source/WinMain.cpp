#include "DxLib.h"

#include "Test.h"

namespace Window {
	static const int WIDTH = 640;		//! 横幅[px]
	static const int HEIGHT = 480;		//! 縦幅[px]
	static const int COLOR_BIT = 32;	//! カラービット[bit]
};

bool Process() {
	//裏画面データを表画面へ反映
	if (ScreenFlip() != 0) return false;
	//Windows systemからくる情報を処理する
	if (ProcessMessage() != 0) return false;
	//画面に描かれたものを消去する
	if (ClearDrawScreen() != 0) return false;

	return true;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//ウィンドウモードにする
	ChangeWindowMode(true),
		//ウィンドウモードのタイトルを変更
		SetWindowTextA("GGJSAP game"),
		//ログ出力を行うかのセット
		SetOutApplicationLogValidFlag(true), //! ログ出力なし
		SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT),
		DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK), SetMouseDispFlag(true);

	Dog *pDog = new Dog();
	SmallDog *pSmallDog = new SmallDog(pDog);

	while (Process()) {
		pDog->hoge();
	}

	DxLib_End();

	return 0;
}
