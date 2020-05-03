#pragma once
#include"Party.h"

// ��ʃ��[�h�̔ԍ�
enum MODENUM {

	// �o�g���ɓ���O�̃��C�����(�}�b�v��z��)
	MODE_MAP = 1000,

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

	// ����݂̂̕`��
	void ModeStartDraw();

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

	// ���񏈗��̌v�Z
	void ModeStartSet();
	// ���񏈗��̕`��
	void ModeStartDraw();

	// ���[�h�I�������p�֐�
	void ModeEnd();

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

	// ���񏈗��̌v�Z
	void ModeStartSet();
	// ���񏈗��̕`��
	void ModeStartDraw();

	// ���[�h�I�������p�֐�
	void ModeEnd();

	// ���C������
	void Run();

};