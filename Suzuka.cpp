#include "Character.h"


CSuzuka::CSuzuka() : CCharacter()
{
	this->stCharaName[0] = "日向宮";
	this->stCharaName[0] = "涼花";

	this->stKanaCharaName[0] = "ヒナミヤ";
	this->stKanaCharaName[0] = "スズカ";

	iPartyNum = 1;

	CSuzuka::SetCharaImage();

}

CSuzuka::~CSuzuka()
{



}

// 画像セット

bool CSuzuka::SetCharaImage()
{

	return CCharacter::SetCharaImage("image/Character/Suzuka/Splitted Image 4-1.png");

}

// 画像描画
bool CSuzuka::DrawCharaImage()
{

	return CCharacter::DrawCharaImage();
}



