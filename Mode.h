#pragma once
#include"Party.h"

// ��ʃ��[�h�̔ԍ�
enum MODENUM {

	// �o�g���ɓ���O�̃��C�����(�}�b�v��z��)
	MODE_MAP = 1000,

	// ���j���[���
	// �}�b�v���[�h����Ăяo�����B
	MODE_MENU = 1001,

	// �o�g�����̏��
	MODE_BATTLE = 2000

};

// �N���X�錾------------------------------------------------------------------

class CMode;
class CMapMode;
class CBattleMode;

// ���[�h�N���X----------------------------------------------------------------
// ���[�h�ԍ��ɉ����ď������s���T�u�N���X�̃C���X�^���X���l�����A���������s����

class CMode {

private:
protected:
public:


private:
protected:
public:

	// �R���X�g���N�^
	CMode();
	// �f�X�g���N�^
	~CMode();

	// �L�[�{�[�h���͂ɑ΂��鏈��
	void KeyControl();

	// ���[�h�I�������p�֐�
	void ModeEnd();

	// ���C���������s�p�֐�
	// ��ʃ��[�h�ɍ��킹�ď������s��
	void Run();

};

// �}�b�v���[�h�N���X----------------------------------------------------------
class CMapMode :public CMode
{
//	�ϐ�----------------------------------------------------------------
private:
protected:
public:

//	�֐�----------------------------------------------------------------
private:
protected:
public:

	// �R���X�g���N�^
	CMapMode();
	// �f�X�g���N�^
	~CMapMode();

	// �L�[�{�[�h���͂ɑ΂��鏈��
	void KeyControl();

	// ���񏈗��̌v�Z
	void ModeStartSet();

	// ���[�h�I�������p�֐�
	void ModeEnd();


	// �`��
	// ��{�I��Run()�̒��ŌĂяo���B
	// Run()�̒��Ő؂�ւ��O�̃��[�h��Draw()���Ăׂ�
	// ���̃��[�h�ł̕`����ォ��`����
	void Draw();

	// ���C������
	void Run();

};

// ���j���[���[�h�N���X----------------------------------------------------------
class CMenuMode :public CMode
{
	//	�ϐ�----------------------------------------------------------------
private:

	// ���j���[�̃J�[�\��
	// �J�n����0
	int unsigned uiCurSol = 0;

	// ���j���[��ʂ̍��ڐ�
	#define MENU_LIST_MAX 3

	// ���j���[�e�L�X�g
	// �R���X�g���N�^�Œ��g������
	std::string astMenuList[MENU_LIST_MAX] = {};

	// ���j���[�e�L�X�g�̔w�i�p�O���t�B�b�N�̃n���h��ID
	// �I������Ă���e�L�X�g�Ƃ���ȊO�̃e�L�X�g�ŕʂɂ���̂�2��ޗp�ӂ���B
	int iMenuBackGraphicHandle[2] = {0, 0};

	// iMenuBackGraphicHandle[]�̗v�f���ԈႦ���w�肷�邽�߂�enum
	enum MENUSELECT
	{
		// �I������Ă��Ȃ��e�L�X�g�p
		NON_SELECTED = 0,
		// �I�𒆂̃e�L�X�g�p
		SELECTED = 1
	};




protected:
public:

	//	�֐�----------------------------------------------------------------
private:
protected:
public:

	// �R���X�g���N�^
	CMenuMode();
	// �f�X�g���N�^
	~CMenuMode();

	// �L�[�{�[�h���͂ɑ΂��鏈��
	void KeyControl();

	// ���񏈗��̌v�Z
	void ModeStartSet();

	// ���[�h�I�������p�֐�
	void ModeEnd();

	// �`��
	// ��{�I��Run()�̒��ŌĂяo���B
	// Run()�̒��Ő؂�ւ��O�̃��[�h��Draw()���Ăׂ�
	// ���̃��[�h�ł̕`����ォ��`����
	void Draw();

	// ���C������
	void Run();


};

// �o�g�����[�h�N���X----------------------------------------------------------
class CBattleMode :public CMode
{
	//	�ϐ�----------------------------------------------------------------
private:
	// �o�g������p�[�e�B���i�[����ϐ�
	CParty* pCTEAM = NULL;

	// �p�[�e�B�̐l�����i�[����ϐ�
	unsigned int uiCTEAMMem = 0;

protected:
public:

	//	�֐�----------------------------------------------------------------
private:
protected:
public:

	// �R���X�g���N�^
	CBattleMode();
	// �f�X�g���N�^
	~CBattleMode();

	// �L�[�{�[�h���͂ɑ΂��鏈��
	void KeyControl();

	// ���񏈗��̌v�Z
	void ModeStartSet();

	// ���[�h�I�������p�֐�
	void ModeEnd();

	// �`��
	// ��{�I��Run()�̒��ŌĂяo���B
	// Run()�̒��Ő؂�ւ��O�̃��[�h��Draw()���Ăׂ�
	// ���̃��[�h�ł̕`����ォ��`����
	void Draw();

	// ���C������
	void Run();

};