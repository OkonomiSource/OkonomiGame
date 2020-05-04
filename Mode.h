#pragma once
#include"Party.h"

// 画面モードの番号
enum MODENUM {

	// バトルに入る前のメイン場面(マップを想定)
	MODE_MAP = 1000,

	// メニュー画面
	// マップモードから呼び出される。
	MODE_MENU = 1001,

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

	// キーボード入力に対する処理
	void KeyControl();

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

	// キーボード入力に対する処理
	void KeyControl();

	// 初回処理の計算
	void ModeStartSet();

	// モード終了処理用関数
	void ModeEnd();


	// 描画
	// 基本的にRun()の中で呼び出す。
	// Run()の中で切り替わる前のモードのDraw()を呼べば
	// このモードでの描画を上から描ける
	void Draw();

	// メイン処理
	void Run();

};

// メニューモードクラス----------------------------------------------------------
class CMenuMode :public CMode
{
	//	変数----------------------------------------------------------------
private:

	// メニューのカーソル
	// 開始時は0
	int unsigned uiCurSol = 0;

	// メニュー画面の項目数
	#define MENU_LIST_MAX 3

	// メニューテキスト
	// コンストラクタで中身を入れる
	std::string astMenuList[MENU_LIST_MAX] = {};

	// メニューテキストの背景用グラフィックのハンドルID
	// 選択されているテキストとそれ以外のテキストで別にするので2種類用意する。
	int iMenuBackGraphicHandle[2] = {0, 0};

	// iMenuBackGraphicHandle[]の要素を間違えず指定するためのenum
	enum MENUSELECT
	{
		// 選択されていないテキスト用
		NON_SELECTED = 0,
		// 選択中のテキスト用
		SELECTED = 1
	};




protected:
public:

	//	関数----------------------------------------------------------------
private:
protected:
public:

	// コンストラクタ
	CMenuMode();
	// デストラクタ
	~CMenuMode();

	// キーボード入力に対する処理
	void KeyControl();

	// 初回処理の計算
	void ModeStartSet();

	// モード終了処理用関数
	void ModeEnd();

	// 描画
	// 基本的にRun()の中で呼び出す。
	// Run()の中で切り替わる前のモードのDraw()を呼べば
	// このモードでの描画を上から描ける
	void Draw();

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

	// キーボード入力に対する処理
	void KeyControl();

	// 初回処理の計算
	void ModeStartSet();

	// モード終了処理用関数
	void ModeEnd();

	// 描画
	// 基本的にRun()の中で呼び出す。
	// Run()の中で切り替わる前のモードのDraw()を呼べば
	// このモードでの描画を上から描ける
	void Draw();

	// メイン処理
	void Run();

};