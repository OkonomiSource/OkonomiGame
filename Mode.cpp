#include"Mode.h"
#include"BackGround.h"

// グローバル変数----------------------------------------------------------------

// inputKey()内で使用
// キーが入力された瞬間かどうかを判定するための変数
int key[256]; // 0:入力されていない 1:入力された瞬間 2:入力されている

// 現在の画面モード番号
// enum MODENUM{}内で設定している定数を使用すること
// 初期状態はマップ画面とする
static unsigned int uiMode = MODE_MAP;

// 前回の画面モード番号
// モード切替があったかどうかを見るための変数
static unsigned int uiBeforeMode = MODE_MAP;

// 背景クラス格納用変数
// この変数に格納されている背景クラスの中身を描写する
static CBackGround* CBG = NULL;

// モード切り替え発生有無
// 0:	初期状態
// 1:	初回
// 2:	初回以降
static unsigned int uiFirstTime = 0;

// extern--------------------------------------------------------------------

// デフォルトフォントのハンドルID
// main.cppのグローバル領域で定義
extern int iDefaultfontHandle;

// グローバル関数----------------------------------------------------------------

// キーが押下された瞬間だけ処理したいときのための関数
// メイン関数で事前に1回呼び出し、
// Key[KEY_INPUT_〇〇〇] == 1 のとき処理が実行されるようにすれば
// キーが押された瞬間だけ処理を実行することになる
void inputKey() {

	// バッファを用意して
	static char buf[256];

	// 全キーの入力状態を格納
	GetHitKeyStateAll(buf);

	// キーの入力状態を1つずつ走査
	for (int i = 0; i < 256; i++)
	{
		// 押下されているキーがあった場合	
		if (buf[i])
		{
			// そのキーの現在の状態が「入力されていない」だったら
			if (key[i] == 0)
			{
				// 「入力された瞬間」に変更
				key[i] = 1;
			}

			// 既に「入力された瞬間」だったら
			else if (key[i] == 1)
			{
				// 「もう押されてますよ」に変更
				key[i] = 2;
			}
		}
		else key[i] = 0;
	}
}

// CModeクラスのメソッド----------------------------------------------------------------

CMode::CMode()
{

}

CMode::~CMode()
{

}

// メイン処理------------------------------------------------------------------------------------------------------------------
// 通常マップ画面

// できること:
// ・マップ上を移動する
// ・メニュー画面を呼び出す
// ・ほかのマップに移動する
// ・ミッションを選択する

void CMode::MapMode()
{
	// 遷移後初回の呼び出しであれば
	 if (uiFirstTime == 0)
	{
		// 初回限定スイッチオン
		uiFirstTime = 1;
	}

	// 計算-------------------------------------------------------------

	// 処理開始前のモード番号を格納しておく
	uiBeforeMode = uiMode;

	// 画面遷移処理

	if (key[KEY_INPUT_SPACE] == 1)
	{
		// 画面の番号を更新
		uiMode = MODE_BATTLE;
	}

	// 描画-------------------------------------------------------------

	// の前に、もし画面遷移が発生していたらここで描画は行わないので
	if (uiBeforeMode != uiMode)
	{
		// 初回限定スイッチを初期状態に設定
		uiFirstTime = 0;

		// 今描画しているものを消して
		ClearDrawScreen();

		// 描画に使った画像はメモリから開放して
		CBG->~CBackGround();

		// 呼び出し元に処理を戻す
		return;
	}

	// 画面遷移が起こっていなければ以下の処理を実施
	// 描画は画面奥側のものから順に描写すること
	else {

		// 画面遷移後、一度だけ各インスタンスを生成
		if (uiFirstTime == 1)
		{
			// 背景クラス
			CBG = new CBackGround(GROUND);
		}

		// 背景画像を描写
		CBG->DrawBackGround();

		// FOR DBG
		DrawStringToHandle(0, 0, "メイン画面です\n", 0xFFFFFF, iDefaultfontHandle);
	}

	// 初回限定処理が終了したら
	if (uiFirstTime == 1)
	{
		// 2に設定する
		uiFirstTime = 2;
	}

}

void CMode::BattleMode()
{
	// 遷移後初回の呼び出しであれば
	if (uiFirstTime == 0)
	{
		// 初回限定スイッチオン
		uiFirstTime = 1;
	}

	// 計算-------------------------------------------------------------

	// 処理開始前のモード番号を格納しておく
	uiBeforeMode = uiMode;

	// 画面遷移処理
	if (key[KEY_INPUT_SPACE] == 1)
	{
		// 画面の番号を更新
		uiMode = MODE_MAP;
	}

	// 描画-------------------------------------------------------------

	// の前に、もし画面遷移が発生していたらここで描画は行わないので
	if (uiBeforeMode != uiMode)
	{
		// 初回限定スイッチを初期状態に設定
		uiFirstTime = 0;

		// 今描画しているものを消して
		ClearDrawScreen();

		// 描画に使った画像はメモリから開放して
		CBG->~CBackGround();

		//呼び出し元に処理を戻す
		return;
	}

	// 画面遷移が起こっていなければ以下の処理を実施
	// 描画は画面奥側のものから順に描写すること
	else {

		// 画面遷移後、一度だけ各インスタンスを生成
		if (uiFirstTime == 1)
		{
			CBG = new CBackGround(RIVER);
			
			// パーティクラス作成
			CTEAM = new CParty();

			// パーティにメンバーを登録
			CTEAM->SetMember(0, MIKATSU);
			CTEAM->SetMember(1, SUZUKA);

			//メンバー登録が終わったらパーティの人数を算出し、値を格納
			uiCTEAMMem = CTEAM->GetMemberOfParty();
		}
		// 背景描画
		CBG->DrawBackGround();

		// キャラクター描画
		// 改修予定あり
		for (unsigned int i = 0; i < uiCTEAMMem; i++) {

			CTEAM->GetMember(i).DrawCharaImage();
			CTEAM->GetMember(i).DrawHPBar();
			CTEAM->GetMember(i).DrawTPBar();

		}

		// メッセージウィンドウ描画
		int iMsgWindowHandle = LoadGraph("image/Window/msgbox_blue.png");
		DrawExtendGraph(0, 350, 641, 481, iMsgWindowHandle, TRUE);

		// メッセージ描画
		for (int i = 0; i < 5; i++)
		{
			DrawStringToHandle(20, 375 + i * 18, "極天脚！\n", 0xFFFFFF, iDefaultfontHandle);
		}
	}

	// 初回限定処理が終了したら
	if (uiFirstTime == 1)
	{
		// 2に設定する
		uiFirstTime = 2;
	}

}

// Run関数
// モードの状態に応じた処理関数を呼び出す
// メイン関数にはこれだけ置いて動くようにしたい
// キー入力の確認はメイン関数で行う
void CMode::Run()
{
	// キーボードの入力を確認してから各モード中の処理に移る。
	inputKey();

	switch (uiMode)
	{
	case MODE_MAP:

		this->MapMode();
		break;

	case MODE_BATTLE:

		this->BattleMode();
		break;

	default:
		OutputDebugString("Error occured:	CMode::Run(): Unacceptable Mode Number.");
		break;

	}

	return;
}

//// CMapModeクラスのメソッド----------------------------------------------------------------
//
//// コンストラクタ
//MapMode::MapMode()
//{
//
//}
//
//// デストラクタ
//MapMode::MapMode()
//{
//
//}
//
//void MapMode::Run()
//{
//	// 遷移後初回の呼び出しであれば
//	if (uiFirstTime == 0)
//	{
//		// 初回限定スイッチオン
//		uiFirstTime = 1;
//	}
//
//	// 計算-------------------------------------------------------------
//
//	// 処理開始前のモード番号を格納しておく
//	uiBeforeMode = uiMode;
//
//	// 画面遷移処理
//
//	if (key[KEY_INPUT_SPACE] == 1)
//	{
//		// 画面の番号を更新
//		uiMode = MODE_BATTLE;
//	}
//
//	// 描画-------------------------------------------------------------
//
//	// の前に、もし画面遷移が発生していたらここで描画は行わないので
//	if (uiBeforeMode != uiMode)
//	{
//		// 初回限定スイッチを初期状態に設定
//		uiFirstTime = 0;
//
//		// 今描画しているものを消して
//		ClearDrawScreen();
//
//		// 描画に使った画像はメモリから開放して
//		CBG->~CBackGround();
//
//		// 呼び出し元に処理を戻す
//		return;
//	}
//
//	// 画面遷移が起こっていなければ以下の処理を実施
//	// 描画は画面奥側のものから順に描写すること
//	else {
//
//		// 画面遷移後、一度だけ各インスタンスを生成
//		if (uiFirstTime == 1)
//		{
//			// 背景クラス
//			CBG = new CBackGround(GROUND);
//		}
//
//		// 背景画像を描写
//		CBG->DrawBackGround();
//
//		// FOR DBG
//		DrawStringToHandle(0, 0, "メイン画面です\n", 0xFFFFFF, iDefaultfontHandle);
//	}
//
//	// 初回限定処理が終了したら
//	if (uiFirstTime == 1)
//	{
//		// 2に設定する
//		uiFirstTime = 2;
//	}
//
//}