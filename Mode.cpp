#include"Mode.h"
#include"dxlib.h"
#include"Character.h"

// �O���[�o���֐�----------------------------------------------------------------

// �L�[���������ꂽ�u�Ԃ��������������Ƃ��̂��߂̊֐�
// ���C���֐��Ŏ��O��1��Ăяo���A
// Key[KEY_INPUT_�Z�Z�Z] == 1 �̂Ƃ����������s�����悤�ɂ����
// �L�[�������ꂽ�u�Ԃ������������s���邱�ƂɂȂ�

int key[256]; // 0:���͂���Ă��Ȃ� 1:���͂��ꂽ�u�� 2:���͂���Ă���
void inputKey() {

	// �o�b�t�@��p�ӂ���
	static char buf[256];

	// �S�L�[�̓��͏�Ԃ��i�[
	GetHitKeyStateAll(buf);

	// �L�[�̓��͏�Ԃ�1������
	for (int i = 0; i < 256; i++)
	{
		// ��������Ă���L�[���������ꍇ	
		if (buf[i])
		{
			// ���̃L�[�̌��݂̏�Ԃ��u���͂���Ă��Ȃ��v��������
			if (key[i] == 0)
			{
				// �u���͂��ꂽ�u�ԁv�ɕύX
				key[i] = 1;
			}

			// ���Ɂu���͂��ꂽ�u�ԁv��������
			else if (key[i] == 1)
			{
				// �u����������Ă܂���v�ɕύX
				key[i] = 2;
			}
		}
		else key[i] = 0;
	}
}

// �N���X�̃��\�b�h----------------------------------------------------------------

CMode::CMode()
{
	uiMode = MODE_MAP;
	uiBeforeMode = MODE_MAP;
	iDbgFontHandle = 0;

}

CMode::~CMode()
{

}

// ��ʑJ�ڗp�֐�
void CMode::ChangeModeNum(unsigned int Num)
{
	// �����ɂ��ꂽ�ԍ��ɉ����ĉ�ʑJ��
	// �K��O�̔ԍ��Ȃ牽�������ɏI���(�����s���̌x���͏o�͂���)
	switch (Num)
	{
	case MODE_MAP:
		uiMode = MODE_MAP;
		break;

	case MODE_BATTLE:
		uiMode = MODE_BATTLE;
		break;

	default:
		OutputDebugString("Mistake: CMode::ChangeModeNum()\n");
		break;
	}
}

// ���݂̏�ʂ̔ԍ���Ԃ�
unsigned int CMode::GetModeNum()
{
	return uiMode;
}


// ���C���֐��Ƀt�H���g��ݒ肵�Ă��炤
void CMode::SetFont(int iFont)
{

	iDbgFontHandle = iFont;

}

// ���C������------------------------------------------------------------------------------------------------------------------
// �ʏ�}�b�v���

// �ł��邱��:
// �E�}�b�v����ړ�����
// �E���j���[��ʂ��Ăяo��
// �E�ق��̃}�b�v�Ɉړ�����
// �E�~�b�V������I������

void CMode::MapMode()
{
	// ����A�}�b�v��ʂłȂ��̂ɌĂяo���ꂽ��
	if (uiMode != MODE_MAP)
	{
		// �G���[���o����
		OutputDebugString("Error Occured:	CMode::MapMode()");
		// �������Ăяo�����ɕԂ�
		return;
	}

	// �v�Z-------------------------------------------------------------
	
	// �����J�n�O�̃��[�h�ԍ����i�[���Ă���
	uiBeforeMode = uiMode;

	// ��ʑJ�ڏ���

	if (key[KEY_INPUT_SPACE] == 1)
	{
		// ��ʂ̔ԍ����X�V
		uiMode = MODE_BATTLE;
	}

	// �`��-------------------------------------------------------------

	// ������ʑJ�ڂ��������Ă�����
	if(uiBeforeMode != uiMode)
	{
		// ���`�悵�Ă�����̂������ČĂяo�����ɏ�����߂�
		ClearDrawScreen();
		return;
	}

	// ��ʑJ�ڂ��N�����Ă��Ȃ���Έȉ��̏��������{
	// �`��͉�ʉ����̂��̂��珇�ɕ`�ʂ��邱��
	else {

		// �w�i�摜��`��


		// FOR DBG
		DrawStringToHandle(0, 0, "���C����ʂł�\n", 0xFFFFFF, iDbgFontHandle);
	}
}

void CMode::BattleMode()
{
	// ����A�o�g����ʂłȂ��̂ɌĂяo���ꂽ��
	if (uiMode != MODE_BATTLE)
	{
		// �G���[���o����
		OutputDebugString("Error Occured:	CMode::BattleMode()");
		// �������Ăяo�����ɕԂ�
		return;
	}

	// �v�Z-------------------------------------------------------------

	// �����J�n�O�̃��[�h�ԍ����i�[���Ă���
	uiBeforeMode = uiMode;

	// ��ʑJ�ڏ���
	if (key[KEY_INPUT_SPACE] == 1)
	{
		
		// ��ʂ̔ԍ����X�V
		uiMode = MODE_MAP;
	}

	// �L�����N�^�[�N���X�쐬
	CMikatsu* NIJO = new CMikatsu();
	CSuzuka* HINAMIYA = new CSuzuka();

	// �`��-------------------------------------------------------------
	// ������ʑJ�ڂ��������Ă�����
	if (uiBeforeMode != uiMode)
	{
		// ���`�悵�Ă�����̂������ČĂяo�����ɏ�����߂�
		ClearDrawScreen();
		return;
	}
	// ��ʑJ�ڂ��N�����Ă��Ȃ���Έȉ��̏��������{
	// �`��͉�ʉ����̂��̂��珇�ɕ`�ʂ��邱��
	else {

		// �L�����N�^�[�`��
		NIJO->DrawCharaImage();
		HINAMIYA->DrawCharaImage();

		// HP�o�[�`��
		NIJO->DrawHPBar();
		HINAMIYA->DrawHPBar();

		// TP�o�[�`��
		NIJO->DrawTPBar();
		HINAMIYA->DrawTPBar();

		// ���b�Z�[�W�E�B���h�E�`��
		int iMsgWindowHandle = LoadGraph("image/Window/msgbox_blue.png");
		DrawExtendGraph(0, 350, 641, 481, iMsgWindowHandle, TRUE);

		// ���b�Z�[�W�`��
		for (int i = 0; i < 5; i++)
		{
			DrawStringToHandle(20, 375 + i * 18, "�ɓV�r�I\n", 0xFFFFFF, iDbgFontHandle);
		}
	}

}

// Run�֐�
// ���[�h�̏�Ԃɉ����������֐����Ăяo��
// ���C���֐��ɂ͂��ꂾ���u���ē����悤�ɂ�����
// �L�[���͂̊m�F�̓��C���֐��ōs��
void CMode::Run()
{
	// �L�[�{�[�h�̓��͂��m�F���Ă���e���[�h���̏����Ɉڂ�B
 	inputKey();

	switch (uiMode)
	{
	case MODE_MAP:

		this->MapMode();
		break;

	case MODE_BATTLE:
	
		this->BattleMode();
		break;

	default:
		OutputDebugString("Error occured:	CMode::Run(): Unacceptable Mode Number.");
		break;
	
	}

	return;
}