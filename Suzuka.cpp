#include "Character.h"


CSuzuka::CSuzuka() : CCharacter()
{
	this->stCharaName[0] = "�����{";
	this->stCharaName[0] = "����";

	this->stKanaCharaName[0] = "�q�i�~��";
	this->stKanaCharaName[0] = "�X�Y�J";

	iPartyNum = 1;

	CSuzuka::SetCharaImage();

}

CSuzuka::~CSuzuka()
{



}

// �摜�Z�b�g

bool CSuzuka::SetCharaImage()
{

	return CCharacter::SetCharaImage("image/Character/Suzuka/Splitted Image 4-1.png");

}

// �摜�`��
bool CSuzuka::DrawCharaImage()
{

	return CCharacter::DrawCharaImage();
}



