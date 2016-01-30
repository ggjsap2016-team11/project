#include "DxLib.h"

#include "Test.h"

namespace Window {
	static const int WIDTH = 640;		//! ����[px]
	static const int HEIGHT = 480;		//! �c��[px]
	static const int COLOR_BIT = 32;	//! �J���[�r�b�g[bit]
};

bool Process() {
	//����ʃf�[�^��\��ʂ֔��f
	if (ScreenFlip() != 0) return false;
	//Windows system���炭�������������
	if (ProcessMessage() != 0) return false;
	//��ʂɕ`���ꂽ���̂���������
	if (ClearDrawScreen() != 0) return false;

	return true;
}


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//�E�B���h�E���[�h�ɂ���
	ChangeWindowMode(true),
		//�E�B���h�E���[�h�̃^�C�g����ύX
		SetWindowTextA("GGJSAP game"),
		//���O�o�͂��s�����̃Z�b�g
		SetOutApplicationLogValidFlag(true), //! ���O�o�͂Ȃ�
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
