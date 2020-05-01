#pragma once
#include "Status.h"

// 持てるスキルの最大数
#define FULLSKILL 8

class CCharacter
{

private:
	// 体力バーの縦幅
	const int iHPBarHeight = 6;
	// TPバーの縦幅
	const int iTPBarHeight = 6;

	// iPartyNumに応じてx-y座標を設定
	const int PositionNum[4][2] =
	{
		// 1番目
		{ 200, 50 },
		// 2番目
		{ 200, 150 },
		// 3番目
		{ 100, 50 },
		// 4番目
		{ 100, 150 },
	};

protected:

	// キャラクター名
	// 0番要素: 姓
	// 1番要素: 名
	std::string stCharaName[2] = { "", "" };

	// キャラクター名(カタカナ)
	// 0番要素: 姓
	// 1番要素: 名
	std::string stKanaCharaName[2] = { "", "" };

	// グラフィックハンドルID
	int iGraphichandle = 0;
	int iGraphicWidth = 0;
	int iGraphicHeight = 0;

	// パーティ内の番号
	int iPartyNum = 0;

	// 画像描画用x座標
	int iPositionX = 0;

	// 画像描画用y座標
	int ipositionY = 0;

	// 技リスト
	Skill sSkill[FULLSKILL];

	// レベル、経験値、HP、攻撃力、防御力、素早さ、TP、CT
	Status sStatus;
public:

private:

protected:

public:
	// コンストラクタ
	CCharacter();
	// デストラクタ
	~CCharacter();
	// 画像セット
	bool SetCharaImage(const char dir[]);

	// 計算処理用関数-----------------------

	// 描画先座標取得用関数 X
	int GetPositionX(int x);
	// 描画先座標取得用関数 Y
	int GetPositionY(int y);

	// 描画処理用関数-----------------------

	// 体力バー描画
	bool DrawHPBar();

	// TPバー描画
	bool DrawTPBar();

	// キャラ画像描画
	bool DrawCharaImage();

};

// 涼花さんクラス--------------------------------------------------------------------------------------
class CSuzuka : public CCharacter
{

private:


protected:

public:


private:

protected:

public:
	// コンストラクタ
	CSuzuka();
	// デストラクタ
	~CSuzuka();
	// 画像セット
	bool SetCharaImage();
	// 画像描画
	bool DrawCharaImage();


};

// ミカツさんクラス--------------------------------------------------------------------------------------

class CMikatsu : public CCharacter
{

private:


protected:

public:


private:

protected:

public:
	// コンストラクタ
	CMikatsu();
	// デストラクタ
	~CMikatsu();
	// 画像セット
	bool SetCharaImage();
	// 画像描画
	bool DrawCharaImage();

};