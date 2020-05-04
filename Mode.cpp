#include"Mode.h"
#include"BackGround.h"

// �O���[�o���ϐ�----------------------------------------------------------------

// inputKey()���Ŏg�p
// �L�[�����͂��ꂽ�u�Ԃ��ǂ����𔻒肷�邽�߂̕ϐ�
int key[256] = {}; // 0:���͂���Ă��Ȃ� 1:���͂��ꂽ�u�� 2:���͂���Ă���

// static�ϐ�--------------------------------------------------------------------

// �T�u�N���X�̃C���X�^���X���i�[����ϐ�
// �}�b�v���[�h�̃C���X�^���X
static CMapMode *pCMapMode = NULL;

// ���j���[���[�h�̃C���X�^���X
static CMenuMode *pCMenuMode = NULL;

// �o�g�����[�h�̃C���X�^���X
static CBattleMode *pCBattleMode = NULL;

// ���݂̉�ʃ��[�h�ԍ�
// enum MODENUM{}���Őݒ肵�Ă���萔���g�p���邱��
// ������Ԃ̓}�b�v��ʂƂ���
static unsigned int uiMode = MODE_MAP;

// �O��̉�ʃ��[�h�ԍ�
// ���[�h�ؑւ����������ǂ��������邽�߂̕ϐ�
static unsigned int uiBeforeMode = MODE_MAP;

// �w�i�N���X�i�[�p�ϐ�
// ���̕ϐ��Ɋi�[����Ă���w�i�N���X�̒��g��`�ʂ���
static CBackGround* CBG = NULL;

// ���[�h�؂�ւ������L��
// 0:	�������
// 1:	����
// 2:	����ȍ~
static unsigned int uiFirstTime = 0;

// extern------------------------------------------------------------------------

// �f�t�H���g�t�H���g�̃n���h��ID
// main.cpp�̃O���[�o���̈�Œ�`
extern int iDefaultfontHandle;

// �O���[�o���֐�----------------------------------------------------------------

// �L�[���������ꂽ�u�Ԃ��������������Ƃ��̂��߂̊֐�
// ���C���֐��Ŏ��O��1��Ăяo���A
// Key[KEY_INPUT_�Z�Z�Z] == 1 �̂Ƃ����������s�����悤�ɂ����
// �L�[�������ꂽ�u�Ԃ������������s���邱�ƂɂȂ�
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

// CMode�N���X�̃��\�b�h-------------------------------------------------------------------------------------------------------

CMode::CMode()
{

}

CMode::~CMode()
{

}

void CMode::KeyControl()
{

}

void CMode::ModeEnd()
{
	// �������X�C�b�`��������Ԃɐݒ�
	uiFirstTime = 0;

	// �`��Ɏg�����摜�̓���������J������
	CBG->~CBackGround();
}

// Run�֐�
// ���[�h�̏�Ԃɉ����������֐����Ăяo��
// ���C���֐��ɂ͂��ꂾ���u���ē����悤�ɂ�����
// �L�[���͂̊m�F�̓��C���֐��ōs��

void CMode::Run()
{
	// �O�񏈗��ŕ`�悵�����̂�����
	ClearDrawScreen();

	// �L�[�{�[�h�̓��͂��m�F���Ă���e���[�h���̏����Ɉڂ�B
	inputKey();

	switch (uiMode)
	{
	case MODE_MAP:
		if (pCMapMode == NULL)
		{
			pCMapMode = new CMapMode();
		}
		pCMapMode->Run();
		break;

	case MODE_MENU:
		if (pCMenuMode == NULL)
		{
			pCMenuMode = new CMenuMode();
		}
		pCMenuMode->Run();
		break;


	case MODE_BATTLE:
		if (pCBattleMode == NULL)
		{
			pCBattleMode = new CBattleMode();
		}
		pCBattleMode->Run();
		break;

	default:
		OutputDebugString("Error occured:	CMode::Run(): Unacceptable Mode Number.");
		break;

	}

	return;
}

// CMapMode�N���X�̃��\�b�h----------------------------------------------------------------

// �R���X�g���N�^
CMapMode::CMapMode()
{

}

// �f�X�g���N�^
CMapMode::~CMapMode()
{

}

// �L�[�{�[�h���͂ɑ΂��鏈��
// E: ���j���[��ʃ��[�h�ւ̈ړ�
// SPACE: �o�g����ʃ��[�h�ւ̈ړ�
void CMapMode::KeyControl()
{
	// ������Ă���L�[��1�����ǂݍ��܂Ȃ��d�l�Ƃ���B
	// �D��x�̍���������ǉ�����Ƃ��͏�ɒǉ����邱�ƁB

	// �X�y�[�X�L�[�������ꂽ��(��ŏ����͕ύX����Ǝv��)
	if (key[KEY_INPUT_SPACE] == 1)
	{
		// �o�g�����[�h�ɑJ��
		uiMode = MODE_BATTLE;

		// �I���������s���B
		ModeEnd();
	}

	// E�L�[�������ꂽ��
	else if (key[KEY_INPUT_E] == 1)
	{
		// ���j���[���[�h�ֈړ�
		uiMode = MODE_MENU;

		// �}�b�v��ʂ͕`�悵���܂܂ɂ���̂ŁAModeEnd()�͌Ă΂Ȃ��B
		// ����̕`������邽�߂ɏ������X�C�b�`���������B
		uiFirstTime = 0;
	}

}

void CMapMode::ModeStartSet()
{
	// �w�i�N���X
	CBG = new CBackGround(GROUND);
}

void CMapMode::ModeEnd()
{
	// �ʏ�̏I���������s��
	CMode::ModeEnd();
}

void CMapMode::Draw()
{
	// �w�i�摜��`��
	CBG->DrawBackGround();

	// FOR DBG
	DrawStringToHandle(0, 0, "���C����ʂł�\n", 0xFFFFFF, iDefaultfontHandle);

}

// ���C������-----------------------------------------------------------
// �}�b�v��ʂ̕`�ʂ��s��
// �ł��邱��:
// �E�}�b�v��؂�ւ��Ĉړ�����
// �E���j���[��ʂ��Ăяo��
// �E�\������Ă���}�b�v����~�b�V������I������
void CMapMode::Run()
{
	// �v�Z-------------------------------------------------------------

	// �L�[�{�[�h�̓��͂�����-------------------------------------------

	KeyControl();

	// �������[�h��؂�ւ���̂ł����
	// ���̊֐����ł̏����͂����܂ŁB
	// �K�v�ɉ�����KeyControl()����ModeEnd()���s�����ƁB
	if (uiMode != MODE_MAP)
	{
		// �Ăяo�����ɏ�����߂�
		return;
	}

	// �J�ڌ�ŏ��̌Ăяo���Ȃ�΁A
	else if (uiFirstTime == 0)
	{
		// ����Ăяo�����̐ݒ���s��
		ModeStartSet();
		// ����t���O���I�t�ɐݒ肷��
		uiFirstTime = 1;
	}

	// �ʏ�̕`����s��

	Draw();

}

// CMenuMode�N���X�̃��\�b�h--------------------------------------------------------------

// �R���X�g���N�^
CMenuMode::CMenuMode()
{
	astMenuList[0] = "�Ґ�";
	astMenuList[1] = "�A�C�e��";
	astMenuList[2] = "�Z�[�u";

	iMenuBackGraphicHandle[NON_SELECTED] = LoadGraph("image/Window/button_blue.png");
	iMenuBackGraphicHandle[SELECTED] = LoadGraph("image/Window/button_blue_hakkou.png");
}

// �f�X�g���N�^
CMenuMode::~CMenuMode()
{

}

// �L�[�{�[�h���͂ɑ΂��鏈��
// E: ���j���[��ʃ��[�h�ւ̈ړ�
void CMenuMode::KeyControl()
{
	// ������Ă���L�[��1�����ǂݍ��܂Ȃ��d�l�Ƃ���B
	// �D��x�̍���������ǉ�����Ƃ��͏�ɒǉ����邱�ƁB

	// E�L�[�������ꂽ��
	if (key[KEY_INPUT_E] == 1)
	{
		// �}�b�v���[�h�ֈړ�
		uiMode = MODE_MAP;

		// �}�b�v��ʂ͕`�悵���܂܂ɂ���̂ŁAModeEnd()�͌Ă΂Ȃ��B
		// ����̕`������邽�߂ɏ������X�C�b�`���������B
		uiFirstTime = 0;
	}
}

void CMenuMode::ModeStartSet()
{

}

void CMenuMode::ModeEnd()
{
	// �ʏ�̏I���������s��
	CMode::ModeEnd();
}

void CMenuMode::Draw()
{
	// �w�i��CMapMode�N���X�̕`��ɂȂ�
	pCMapMode->Draw();

	DrawGraph(0, 0, iMenuBackGraphicHandle[NON_SELECTED], TRUE);
	
	DrawStringToHandle(70, 30, "���j���[\n", 0xFFFFFF, iDefaultfontHandle);

}

// ���C������-----------------------------------------------------------
// �}�b�v��ʂ̕`�ʂ��s��
// �ł��邱��:
// �E�}�b�v��؂�ւ��Ĉړ�����
// �E���j���[��ʂ��Ăяo��
// �E�\������Ă���}�b�v����~�b�V������I������
void CMenuMode::Run()
{
	// �v�Z-------------------------------------------------------------

	// �L�[�{�[�h�̓��͂�����-------------------------------------------
	KeyControl();

	// �������[�h��؂�ւ���̂ł����
	// ���̊֐����ł̏����͂����܂ŁB
	// �K�v�ɉ�����KeyControl()����ModeEnd()���s�����ƁB
	if (uiMode != MODE_MENU)
	{
		// �Ăяo�����ɏ�����߂�
		return;
	}

	// �J�ڌ�ŏ��̌Ăяo���Ȃ�΁A
	else if (uiFirstTime == 0)
	{
		// ����Ăяo�����̐ݒ���s��
		ModeStartSet();
		// ����t���O���I�t�ɐݒ肷��
		uiFirstTime = 1;
	}

	// �ʏ�̕`����s��
	Draw();

}

// CBattleMode�N���X�̃��\�b�h------------------------------------------------------------

// �R���X�g���N�^
CBattleMode::CBattleMode()
{

}

// �f�X�g���N�^
CBattleMode::~CBattleMode()
{

}

void CBattleMode::ModeStartSet()
{
	// �w�i�N���X�쐬(�Ƃ肠�������`��)
	CBG = new CBackGround(RIVER);

	// �p�[�e�B�N���X�쐬
	pCTEAM = new CParty();

	// �p�[�e�B�Ƀ����o�[��o�^
	pCTEAM->SetMember(0, MIKATSU);
	pCTEAM->SetMember(1, SUZUKA);

	//�����o�[�o�^���I�������p�[�e�B�̐l�����Z�o���A�l���i�[
	uiCTEAMMem = pCTEAM->GetMemberOfParty();
}

void CBattleMode::ModeEnd()
{
	// �ʏ�̏I���������s��
	CMode::ModeEnd();
}

void CBattleMode::Draw()
{
	// �w�i�`��
	CBG->DrawBackGround();

	// �L�����N�^�[�`��
	// ���C�\�肠��
	for (unsigned int i = 0; i < uiCTEAMMem; i++)
	{

		pCTEAM->GetMember(i).DrawCharaImage();
		pCTEAM->GetMember(i).DrawHPBar();
		pCTEAM->GetMember(i).DrawTPBar();

	}

	// ���b�Z�[�W�E�B���h�E�`��
	int iMsgWindowHandle = LoadGraph("image/Window/msgbox_blue.png");
	DrawExtendGraph(0, 350, 641, 481, iMsgWindowHandle, TRUE);

	// ���b�Z�[�W�`��
	for (int i = 0; i < 5; i++)
	{
		DrawStringToHandle(20, 375 + i * 18, "�ɓV�r�I\n", 0xFFFFFF, iDefaultfontHandle);
	}
}

void CBattleMode::Run()
{
	// �v�Z-------------------------------------------------------------

	// �L�[�{�[�h�̓��͂�����-------------------------------------------

	// ��ʑJ�ڏ���
	// �e��ʃ��[�h���ɈقȂ邽�ߊe�T�u�N���X�œƎ��Ɏ���
	// �����X�y�[�X�L�[�������ꂽ��(��ŏ����͕ύX����Ǝv��)
	if (key[KEY_INPUT_SPACE] == 1)
	{
		// ��ʂ̔ԍ����X�V
		uiMode = MODE_MAP;
	}

	// �������[�h��؂�ւ���̂ł���Ή�ʂ�J�ڂ��鏈�����s��
	if (uiMode != MODE_BATTLE)
	{
		// �I������������
		ModeEnd();
		// �Ăяo�����ɏ�����߂�
		return;
	}

	// �J�ڌ�ŏ��̌Ăяo���Ȃ�΁A
	else if (uiFirstTime == 0)
	{
		// ����Ăяo�����̐ݒ���s��
		ModeStartSet();
		// ����t���O���I�t�ɐݒ肷��
		uiFirstTime = 1;
	}

	// �ʏ�̕`����s��
	Draw();
}