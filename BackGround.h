#pragma once
#include"dxlib.h"
#include<string>

// ��ʂ�X�����̍ő�}�X��
#define BG_X_MAX 20

// ��ʂ�Y�����̍ő�}�X��
#define BG_Y_MAX 15

// �w�i�N���X�̐e�N���X
// ���̃N���X���p�����Ď��ۂɕ`�ʂ���w�i������Ă�
class CBackGround
{
private:

protected:

	// �}�b�v�`�b�v�摜�̃n���h��ID���i�[����ϐ�
	// [Y][X]�ō쐬���������s��������

	// ��ԉ��̃��C��
	// �ǂ̃}�b�v�����������͖��߂邱�ƁB
	int iMapchips_Bottom[BG_Y_MAX][BG_X_MAX] = { 0 };

	// ������2�Ԗڂ̃��C��
	// �ł��邾�����̃��C�����^�񒆂ɂȂ�悤��(=���C���𑝂₳�Ȃ��悤��)���B
	int iMapchips_Middle[BG_Y_MAX][BG_X_MAX] = { 0 };

	// ������3�Ԗڂ̃��C��
	// ���ꂪ��ԏ�ɂȂ�悤�ɍ��B
	// ���ꃌ�C���������ƕK�v�ȏꍇ�͌p����̃N���X�Ŋi�[�p�ϐ����������邱�ƁB
	int iMapchips_Top[BG_Y_MAX][BG_X_MAX] = { 0 };

public:

private:

protected:

public:
	CBackGround();
	~CBackGround();

	// �}�b�v�`�b�v���Z�b�g����֐�
	// �R���X�g���N�^�ŌĂяo���悤�ɂ���
	virtual void SetMapChips() = 0;

	// �}�b�v�`��֐�
	virtual void DrawBackGround() = 0;


};

// �ړ���ʂ̔w�i1
class CBackGround_1 :public CBackGround
{
private:

protected:

public:



private:

protected:

public:
	CBackGround_1();
	~CBackGround_1();

	// �}�b�v�`�b�v���Z�b�g����֐�
	// �R���X�g���N�^�ŌĂяo���悤�ɂ���
	 void SetMapChips();

	// �}�b�v�`��֐�
	 void DrawBackGround();

};

// �ړ���ʂ̔w�i2
class CBackGround_2 :public CBackGround
{
private:

protected:

public:



private:

protected:

public:
	CBackGround_2();
	~CBackGround_2();

	// �}�b�v�`�b�v���Z�b�g����֐�
	// �R���X�g���N�^�ŌĂяo���悤�ɂ���
	void SetMapChips();

	// �}�b�v�`��֐�
	void DrawBackGround();

};