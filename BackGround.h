#pragma once
#include"dxlib.h"
#include<string>

// 画面のX方向の最大マス数
#define BG_X_MAX 20

// 画面のY方向の最大マス数
#define BG_Y_MAX 15

enum BG
{
	NOTHING,
	GROUND,
	RIVER
};

// 背景クラスの親クラス
// このクラスを継承して実際に描写する背景を作ってね
class CBackGround
{
private:

protected:

	// マップチップ画像のハンドルIDを格納する変数
	// [Y][X]で作成した方が都合がいい

	// 一番下のレイヤ
	// どのマップもここだけは埋めること。
	int iMapchips_Bottom[BG_Y_MAX][BG_X_MAX] = { 0 };

	// 下から2番目のレイヤ
	// できるだけこのレイヤが真ん中になるように(=レイヤを増やさないように)作る。
	int iMapchips_Middle[BG_Y_MAX][BG_X_MAX] = { 0 };

	// 下から3番目のレイヤ
	// これが一番上になるように作る。
	// 万一レイヤがもっと必要な場合は継承先のクラスで格納用変数を実装すること。
	int iMapchips_Top[BG_Y_MAX][BG_X_MAX] = { 0 };

public:

private:

protected:

public:
	// コンストラクタ
	CBackGround();
	// デストラクタ
	~CBackGround();

	// 引数付きコンストラクタ
	CBackGround(unsigned int uiBG);

	// マップチップをセットする関数
	// コンストラクタで呼び出すようにする
	virtual void SetMapChips(unsigned int uiBG);

	// マップ描画関数
	virtual void DrawBackGround();


};
