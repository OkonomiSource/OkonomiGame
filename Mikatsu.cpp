#include "Character.h"


CMikatsu::CMikatsu() : CCharacter()
{
	this->stCharaName[0] = "���";
	this->stCharaName[0] = "�~�J�c";

	this->stKanaCharaName[0] = "�j�W���E";
	this->stKanaCharaName[0] = "�~�J�c";

	CMikatsu::SetCharaImage();

}

CMikatsu::~CMikatsu()
{



}

// �摜�Z�b�g

bool CMikatsu::SetCharaImage()
{

	return CCharacter::SetCharaImage("image/Character/Mikatsu/Splitted Image 4-1.png");

}

// �摜�`��
bool CMikatsu::DrawCharaImage()
{

	return CCharacter::DrawCharaImage();
}



