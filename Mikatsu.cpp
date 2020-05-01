#include "Character.h"


CMikatsu::CMikatsu() : CCharacter()
{
	this->stCharaName[0] = "二条";
	this->stCharaName[0] = "ミカツ";

	this->stKanaCharaName[0] = "ニジョウ";
	this->stKanaCharaName[0] = "ミカツ";

	CMikatsu::SetCharaImage();

}

CMikatsu::~CMikatsu()
{



}

// 画像セット

bool CMikatsu::SetCharaImage()
{

	return CCharacter::SetCharaImage("image/Character/Mikatsu/Splitted Image 4-1.png");

}

// 画像描画
bool CMikatsu::DrawCharaImage()
{

	return CCharacter::DrawCharaImage();
}



