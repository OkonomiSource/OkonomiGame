// �C���N���[�h-----------------------------------------------------
#include"dxlib.h"
#include"BackGround.h"
#include"Mode.h"

// �萔��`---------------------------------------------------------
#define FONT_SIZE_DEFAULT 18

// �O���[�o���ϐ�---------------------------------------------------
int iDefaultfontHandle = 0;

// �v���O������ winmain ����
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	// �ُ�`�F�b�N------------------------------------------------------------------------

	// Window�ݒ�
	// Window���[�hor�t���X�N���[�����[�h�̐ݒ��
	// DxLib_Init()�̑O�Ɏ��s���邱��
	SetWindowSize(640, 480);
	ChangeWindowMode(TRUE);

	// ��ʂ̑傫���̕ύX�s�B
	SetWindowSizeChangeEnableFlag(FALSE);

	// �ُ킪�������ꍇ�A�I��
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//int k = KEY_INPUT_SPACE;
	//k = KEY_INPUT_SPACE;

	// ������������������������J�n---------------------------------------------------------

	// �����ݒ�-----------------------------------------------------------------------------

	// �t�H���g�̓ǂݍ���
	// .otf�t�@�C�������w�肵�ēǂݍ���
	AddFontResourceEx("���S�����ՃS�V�b�N.otf", FR_PRIVATE, NULL);
	
	// �ǂݍ���.otf�t�@�C�����̃t�H���g���A�t�H���g�T�C�Y �t�H���g�̑����A�t�H���g�̃^�C�v
	iDefaultfontHandle = CreateFontToHandle("07���S�����ՃS�V�b�N7", FONT_SIZE_DEFAULT, 1, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT);

	// ���̂̐���
	// ��ʃN���X
	CMode* Scene = new CMode();

	int a = GetJoypadNum();
	printfDx("%d",a);

	unsigned int uiGameCount = 0;

	// ���[�v����
	for (;;)
	{
		// �v�Z--------------------------------------------------------------------
		// �L�[�̓��͏�Ԃ𑖍�����
		// �`��--------------------------------------------------------------------

		// �܂��͕`���𗠉�ʂɂ���
		SetDrawScreen(DX_SCREEN_BACK);

		Scene->Run();

		// FOR DBG
		// �Q�[���J�n������̃J�E���g
		uiGameCount++;

		// ��ʂ��X�V����
		// �t���X�N���[�����[�h�̏ꍇ�A�\��ʂƗ���ʂ�����
		// �E�B���h�E���[�h�̏ꍇ�A����ʂ̓��e��\��ʂɃR�s�[
		ScreenFlip();

		// ����̏ꏊ�Ń��[�v���鎞��ProcessMessage()���Ăяo���ƈ��S�B
		// �E�B���h�E�́~�{�^����������0�ȊO�̒l��Ԃ��B
		// Esc�܂��̓E�B���h�E�́~�{�^��(�܂���Alt + F4)�ŏI���B
		if (ProcessMessage() != 0 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

	DxLib_End();

	return 0;

}