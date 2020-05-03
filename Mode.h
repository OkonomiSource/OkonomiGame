#pragma once
#include"Party.h"

// 画面モードの番号
enum MODENUM {

	// バトルに入る前のメイン場面(マップを想定)
	MODE_MAP = 1000,

	// バトル中の場面
	MODE_BATTLE = 2000

};

// クラス宣言------------------------------------------------------------------

class CMode;
class CMapMode;
class CBattleMode;

// モードクラス----------------------------------------------------------------
// モード番号に応じて処理を行うサブクラスのインスタンスを獲得し、処理を実行する

class CMode {

private:
protected:
public:


private:
protected:
public:

	// コンストラクタ
	CMode();
	// デストラクタ
	~CMode();

	// 初回のみの描画
	void ModeStartDraw();

	// モード終了処理用関数
	void ModeEnd();

	// メイン処理実行用関数
	// 画面モードに合わせて処理を行う
	void Run();

};

// マップモードクラス----------------------------------------------------------
class CMapMode :public CMode
{
//	変数----------------------------------------------------------------
private:
protected:
public:

//	関数----------------------------------------------------------------
private:
protected:
public:

	// コンストラクタ
	CMapMode();
	// デストラクタ
	~CMapMode();

	// 初回処理の計算
	void ModeStartSet();
	// 初回処理の描画
	void ModeStartDraw();

	// モード終了処理用関数
	void ModeEnd();

	// メイン処理
	void Run();
};

// バトルモードクラス----------------------------------------------------------
class CBattleMode :public CMode
{
	//	変数----------------------------------------------------------------
private:
	// バトルするパーティを格納する変数
	CParty* pCTEAM = NULL;

	// パーティの人数を格納する変数
	unsigned int uiCTEAMMem = 0;

protected:
public:

	//	関数----------------------------------------------------------------
private:
protected:
public:

	// コンストラクタ
	CBattleMode();
	// デストラクタ
	~CBattleMode();

	// 初回処理の計算
	void ModeStartSet();
	// 初回処理の描画
	void ModeStartDraw();

	// モード終了処理用関数
	void ModeEnd();

	// メイン処理
	void Run();

};