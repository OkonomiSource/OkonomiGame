#include"BackGround.h"

// 親クラスのコンストラクタ
CBackGround::CBackGround()
{

}

// 親クラスのデストラクタ
CBackGround::~CBackGround()
{

}


// 移動画面の背景1
CBackGround_1::CBackGround_1()
{
	// マップチップ設定用関数を実行する
	this->SetMapChips();
}

CBackGround_1::~CBackGround_1()
{

}

void CBackGround_1::SetMapChips()
{
	// 縦一列を設定
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// 横一列を設定
		for (int j = 0; j < BG_X_MAX; j++) {
			this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/Splitted Image 0-4.png");
		}
	}
}

void CBackGround_1::DrawBackGround()
{
	// 縦の繰り返し
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// 横一列を設定
		for (int j = 0; j < BG_X_MAX; j++) {
			DrawGraph(j * 32, i * 32, this->iMapchips_Bottom[i][j],TRUE);
		}
	}


}

// 移動画面の背景2
CBackGround_2::CBackGround_2()
{
	// マップチップ設定用関数を実行する
	this->SetMapChips();
}

CBackGround_2::~CBackGround_2()
{

}

void CBackGround_1::SetMapChips()
{
	// 縦一列を設定
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// 横一列を設定
		for (int j = 0; j < BG_X_MAX; j++) {
			this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/Splitted Image 0-4.png");
		}
	}
}

void CBackGround_1::DrawBackGround()
{
	// 縦の繰り返し
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// 横一列を設定
		for (int j = 0; j < BG_X_MAX; j++) {
			DrawGraph(j * 32, i * 32, this->iMapchips_Bottom[i][j], TRUE);
		}
	}


}