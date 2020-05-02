#pragma once
#include"Party.h"


enum MODENUM {

	// バトルに入る前のメイン場面(マップを想定)
	MODE_MAP = 1000,

	// バトル中の場面
	MODE_BATTLE = 2000

};

// モードクラス
// 各画面モードを管理し、モード番号に応じた処理を実行する
class CMode {

private:
	CParty *CTEAM = NULL;
	unsigned int uiCTEAMMem = 0;

protected:
public:


private:

protected:
public:

	CMode();
	~CMode();

	// メインモード処理
	void MapMode();
	void BattleMode();
	void Run();

};

class MapMode :public CMode
{
//	変数----------------------------------------------------------------
private:
protected:
public:

//	関数----------------------------------------------------------------
private:
protected:
public:
	MapMode();
	~MapMode();

	void Run();
};