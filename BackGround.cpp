#include"BackGround.h"

// �e�N���X�̃R���X�g���N�^
CBackGround::CBackGround()
{

}

// �e�N���X�̃f�X�g���N�^
CBackGround::~CBackGround()
{

}


// �ړ���ʂ̔w�i1
CBackGround_1::CBackGround_1()
{
	// �}�b�v�`�b�v�ݒ�p�֐������s����
	this->SetMapChips();
}

CBackGround_1::~CBackGround_1()
{

}

void CBackGround_1::SetMapChips()
{
	// �c����ݒ�
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// ������ݒ�
		for (int j = 0; j < BG_X_MAX; j++) {
			this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/Splitted Image 0-4.png");
		}
	}
}

void CBackGround_1::DrawBackGround()
{
	// �c�̌J��Ԃ�
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// ������ݒ�
		for (int j = 0; j < BG_X_MAX; j++) {
			DrawGraph(j * 32, i * 32, this->iMapchips_Bottom[i][j],TRUE);
		}
	}


}

// �ړ���ʂ̔w�i2
CBackGround_2::CBackGround_2()
{
	// �}�b�v�`�b�v�ݒ�p�֐������s����
	this->SetMapChips();
}

CBackGround_2::~CBackGround_2()
{

}

void CBackGround_1::SetMapChips()
{
	// �c����ݒ�
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// ������ݒ�
		for (int j = 0; j < BG_X_MAX; j++) {
			this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/Splitted Image 0-4.png");
		}
	}
}

void CBackGround_1::DrawBackGround()
{
	// �c�̌J��Ԃ�
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// ������ݒ�
		for (int j = 0; j < BG_X_MAX; j++) {
			DrawGraph(j * 32, i * 32, this->iMapchips_Bottom[i][j], TRUE);
		}
	}


}