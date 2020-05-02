#include"Mode.h"
#include"BackGround.h"

// �O���[�o���ϐ�----------------------------------------------------------------

// inputKey()���Ŏg�p
// �L�[�����͂��ꂽ�u�Ԃ��ǂ����𔻒肷�邽�߂̕ϐ�
int key[256]; // 0:���͂���Ă��Ȃ� 1:���͂��ꂽ�u�� 2:���͂���Ă���

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

// extern--------------------------------------------------------------------

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

// CMode�N���X�̃��\�b�h----------------------------------------------------------------

CMode::CMode()
{

}

CMode::~CMode()
{

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
	// �J�ڌ㏉��̌Ăяo���ł����
	 if (uiFirstTime == 0)
	{
		// �������X�C�b�`�I��
		uiFirstTime = 1;
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

	// �̑O�ɁA������ʑJ�ڂ��������Ă����炱���ŕ`��͍s��Ȃ��̂�
	if (uiBeforeMode != uiMode)
	{
		// �������X�C�b�`��������Ԃɐݒ�
		uiFirstTime = 0;

		// ���`�悵�Ă�����̂�������
		ClearDrawScreen();

		// �`��Ɏg�����摜�̓���������J������
		CBG->~CBackGround();

		// �Ăяo�����ɏ�����߂�
		return;
	}

	// ��ʑJ�ڂ��N�����Ă��Ȃ���Έȉ��̏��������{
	// �`��͉�ʉ����̂��̂��珇�ɕ`�ʂ��邱��
	else {

		// ��ʑJ�ڌ�A��x�����e�C���X�^���X�𐶐�
		if (uiFirstTime == 1)
		{
			// �w�i�N���X
			CBG = new CBackGround(GROUND);
		}

		// �w�i�摜��`��
		CBG->DrawBackGround();

		// FOR DBG
		DrawStringToHandle(0, 0, "���C����ʂł�\n", 0xFFFFFF, iDefaultfontHandle);
	}

	// ������菈�����I��������
	if (uiFirstTime == 1)
	{
		// 2�ɐݒ肷��
		uiFirstTime = 2;
	}

}

void CMode::BattleMode()
{
	// �J�ڌ㏉��̌Ăяo���ł����
	if (uiFirstTime == 0)
	{
		// �������X�C�b�`�I��
		uiFirstTime = 1;
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

	// �`��-------------------------------------------------------------

	// �̑O�ɁA������ʑJ�ڂ��������Ă����炱���ŕ`��͍s��Ȃ��̂�
	if (uiBeforeMode != uiMode)
	{
		// �������X�C�b�`��������Ԃɐݒ�
		uiFirstTime = 0;

		// ���`�悵�Ă�����̂�������
		ClearDrawScreen();

		// �`��Ɏg�����摜�̓���������J������
		CBG->~CBackGround();

		//�Ăяo�����ɏ�����߂�
		return;
	}

	// ��ʑJ�ڂ��N�����Ă��Ȃ���Έȉ��̏��������{
	// �`��͉�ʉ����̂��̂��珇�ɕ`�ʂ��邱��
	else {

		// ��ʑJ�ڌ�A��x�����e�C���X�^���X�𐶐�
		if (uiFirstTime == 1)
		{
			CBG = new CBackGround(RIVER);
			
			// �p�[�e�B�N���X�쐬
			CTEAM = new CParty();

			// �p�[�e�B�Ƀ����o�[��o�^
			CTEAM->SetMember(0, MIKATSU);
			CTEAM->SetMember(1, SUZUKA);

			//�����o�[�o�^���I�������p�[�e�B�̐l�����Z�o���A�l���i�[
			uiCTEAMMem = CTEAM->GetMemberOfParty();
		}
		// �w�i�`��
		CBG->DrawBackGround();

		// �L�����N�^�[�`��
		// ���C�\�肠��
		for (unsigned int i = 0; i < uiCTEAMMem; i++) {

			CTEAM->GetMember(i).DrawCharaImage();
			CTEAM->GetMember(i).DrawHPBar();
			CTEAM->GetMember(i).DrawTPBar();

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

	// ������菈�����I��������
	if (uiFirstTime == 1)
	{
		// 2�ɐݒ肷��
		uiFirstTime = 2;
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

//// CMapMode�N���X�̃��\�b�h----------------------------------------------------------------
//
//// �R���X�g���N�^
//MapMode::MapMode()
//{
//
//}
//
//// �f�X�g���N�^
//MapMode::MapMode()
//{
//
//}
//
//void MapMode::Run()
//{
//	// �J�ڌ㏉��̌Ăяo���ł����
//	if (uiFirstTime == 0)
//	{
//		// �������X�C�b�`�I��
//		uiFirstTime = 1;
//	}
//
//	// �v�Z-------------------------------------------------------------
//
//	// �����J�n�O�̃��[�h�ԍ����i�[���Ă���
//	uiBeforeMode = uiMode;
//
//	// ��ʑJ�ڏ���
//
//	if (key[KEY_INPUT_SPACE] == 1)
//	{
//		// ��ʂ̔ԍ����X�V
//		uiMode = MODE_BATTLE;
//	}
//
//	// �`��-------------------------------------------------------------
//
//	// �̑O�ɁA������ʑJ�ڂ��������Ă����炱���ŕ`��͍s��Ȃ��̂�
//	if (uiBeforeMode != uiMode)
//	{
//		// �������X�C�b�`��������Ԃɐݒ�
//		uiFirstTime = 0;
//
//		// ���`�悵�Ă�����̂�������
//		ClearDrawScreen();
//
//		// �`��Ɏg�����摜�̓���������J������
//		CBG->~CBackGround();
//
//		// �Ăяo�����ɏ�����߂�
//		return;
//	}
//
//	// ��ʑJ�ڂ��N�����Ă��Ȃ���Έȉ��̏��������{
//	// �`��͉�ʉ����̂��̂��珇�ɕ`�ʂ��邱��
//	else {
//
//		// ��ʑJ�ڌ�A��x�����e�C���X�^���X�𐶐�
//		if (uiFirstTime == 1)
//		{
//			// �w�i�N���X
//			CBG = new CBackGround(GROUND);
//		}
//
//		// �w�i�摜��`��
//		CBG->DrawBackGround();
//
//		// FOR DBG
//		DrawStringToHandle(0, 0, "���C����ʂł�\n", 0xFFFFFF, iDefaultfontHandle);
//	}
//
//	// ������菈�����I��������
//	if (uiFirstTime == 1)
//	{
//		// 2�ɐݒ肷��
//		uiFirstTime = 2;
//	}
//
//}