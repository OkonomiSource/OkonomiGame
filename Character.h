#pragma once
#include "Status.h"

// ���Ă�X�L���̍ő吔
#define FULLSKILL 8

class CCharacter
{

private:
	// �̗̓o�[�̏c��
	const int iHPBarHeight = 6;
	// TP�o�[�̏c��
	const int iTPBarHeight = 6;

	// iPartyNum�ɉ�����x-y���W��ݒ�
	const int PositionNum[4][2] =
	{
		// 1�Ԗ�
		{ 200, 50 },
		// 2�Ԗ�
		{ 200, 150 },
		// 3�Ԗ�
		{ 100, 50 },
		// 4�Ԗ�
		{ 100, 150 },
	};

protected:

	// �L�����N�^�[��
	// 0�ԗv�f: ��
	// 1�ԗv�f: ��
	std::string stCharaName[2] = { "", "" };

	// �L�����N�^�[��(�J�^�J�i)
	// 0�ԗv�f: ��
	// 1�ԗv�f: ��
	std::string stKanaCharaName[2] = { "", "" };

	// �O���t�B�b�N�n���h��ID
	int iGraphichandle = 0;
	int iGraphicWidth = 0;
	int iGraphicHeight = 0;

	// �p�[�e�B���̔ԍ�
	int iPartyNum = 0;

	// �摜�`��px���W
	int iPositionX = 0;

	// �摜�`��py���W
	int ipositionY = 0;

	// �Z���X�g
	Skill sSkill[FULLSKILL];

	// ���x���A�o���l�AHP�A�U���́A�h��́A�f�����ATP�ACT
	Status sStatus;
public:

private:

protected:

public:
	// �R���X�g���N�^
	CCharacter();
	// �f�X�g���N�^
	~CCharacter();
	// �摜�Z�b�g
	bool SetCharaImage(const char dir[]);

	// �v�Z�����p�֐�-----------------------

	// �`�����W�擾�p�֐� X
	int GetPositionX(int x);
	// �`�����W�擾�p�֐� Y
	int GetPositionY(int y);

	// �`�揈���p�֐�-----------------------

	// �̗̓o�[�`��
	bool DrawHPBar();

	// TP�o�[�`��
	bool DrawTPBar();

	// �L�����摜�`��
	bool DrawCharaImage();

};

// ���Ԃ���N���X--------------------------------------------------------------------------------------
class CSuzuka : public CCharacter
{

private:


protected:

public:


private:

protected:

public:
	// �R���X�g���N�^
	CSuzuka();
	// �f�X�g���N�^
	~CSuzuka();
	// �摜�Z�b�g
	bool SetCharaImage();
	// �摜�`��
	bool DrawCharaImage();


};

// �~�J�c����N���X--------------------------------------------------------------------------------------

class CMikatsu : public CCharacter
{

private:


protected:

public:


private:

protected:

public:
	// �R���X�g���N�^
	CMikatsu();
	// �f�X�g���N�^
	~CMikatsu();
	// �摜�Z�b�g
	bool SetCharaImage();
	// �摜�`��
	bool DrawCharaImage();

};