#pragma once

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

	// 現在のモード番号
	unsigned int uiMode;
	// 前回のモード番号(画面遷移時用)
	unsigned int uiBeforeMode;

	// 共通フォントハンドルID受取用変数(あとで消すかも)
	int iDbgFontHandle;

protected:
public:


private:

protected:
public:

	CMode();
	~CMode();

	// 場面遷移用関数
	void ChangeModeNum(unsigned int Num);

	// 現在の場面の番号を返す
	unsigned int GetModeNum();

	// メイン関数にフォントを設定してもらう
	void SetFont(int iFont);

	// メインモード処理
	void MapMode();
	void BattleMode();
	void Run();



};