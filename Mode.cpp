#include"Mode.h"
#include"BackGround.h"

// グローバル変数----------------------------------------------------------------

// inputKey()内で使用
// キーが入力された瞬間かどうかを判定するための変数
int key[256] = {}; // 0:入力されていない 1:入力された瞬間 2:入力されている

// static変数--------------------------------------------------------------------

// サブクラスのインスタンスを格納する変数
// マップモードのインスタンス
static CMapMode *pCMapMode = NULL;

// メニューモードのインスタンス
static CMenuMode *pCMenuMode = NULL;

// バトルモードのインスタンス
static CBattleMode *pCBattleMode = NULL;

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

// extern------------------------------------------------------------------------

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

// CModeクラスのメソッド-------------------------------------------------------------------------------------------------------

CMode::CMode()
{

}

CMode::~CMode()
{

}

void CMode::KeyControl()
{

}

void CMode::ModeEnd()
{
	// 初回限定スイッチを初期状態に設定
	uiFirstTime = 0;

	// 描画に使った画像はメモリから開放する
	CBG->~CBackGround();
}

// Run関数
// モードの状態に応じた処理関数を呼び出す
// メイン関数にはこれだけ置いて動くようにしたい
// キー入力の確認はメイン関数で行う

void CMode::Run()
{
	// 前回処理で描画したものを消し
	ClearDrawScreen();

	// キーボードの入力を確認してから各モード中の処理に移る。
	inputKey();

	switch (uiMode)
	{
	case MODE_MAP:
		if (pCMapMode == NULL)
		{
			pCMapMode = new CMapMode();
		}
		pCMapMode->Run();
		break;

	case MODE_MENU:
		if (pCMenuMode == NULL)
		{
			pCMenuMode = new CMenuMode();
		}
		pCMenuMode->Run();
		break;


	case MODE_BATTLE:
		if (pCBattleMode == NULL)
		{
			pCBattleMode = new CBattleMode();
		}
		pCBattleMode->Run();
		break;

	default:
		OutputDebugString("Error occured:	CMode::Run(): Unacceptable Mode Number.");
		break;

	}

	return;
}

// CMapModeクラスのメソッド----------------------------------------------------------------

// コンストラクタ
CMapMode::CMapMode()
{

}

// デストラクタ
CMapMode::~CMapMode()
{

}

// キーボード入力に対する処理
// E: メニュー画面モードへの移動
// SPACE: バトル画面モードへの移動
void CMapMode::KeyControl()
{
	// 押されているキーは1つしか読み込まない仕様とする。
	// 優先度の高い処理を追加するときは上に追加すること。

	// スペースキーが押されたら(後で処理は変更すると思う)
	if (key[KEY_INPUT_SPACE] == 1)
	{
		// バトルモードに遷移
		uiMode = MODE_BATTLE;

		// 終了処理を行う。
		ModeEnd();
	}

	// Eキーが押されたら
	else if (key[KEY_INPUT_E] == 1)
	{
		// メニューモードへ移動
		uiMode = MODE_MENU;

		// マップ画面は描画したままにするので、ModeEnd()は呼ばない。
		// 初回の描画をするために初回限定スイッチだけ入れる。
		uiFirstTime = 0;
	}

}

void CMapMode::ModeStartSet()
{
	// 背景クラス
	CBG = new CBackGround(GROUND);
}

void CMapMode::ModeEnd()
{
	// 通常の終了処理を行う
	CMode::ModeEnd();
}

void CMapMode::Draw()
{
	// 背景画像を描画
	CBG->DrawBackGround();

	// FOR DBG
	DrawStringToHandle(0, 0, "メイン画面です\n", 0xFFFFFF, iDefaultfontHandle);

}

// メイン処理-----------------------------------------------------------
// マップ画面の描写を行う
// できること:
// ・マップを切り替えて移動する
// ・メニュー画面を呼び出す
// ・表示されているマップからミッションを選択する
void CMapMode::Run()
{
	// 計算-------------------------------------------------------------

	// キーボードの入力を処理-------------------------------------------

	KeyControl();

	// もしモードを切り替えるのであれば
	// この関数内での処理はここまで。
	// 必要に応じてKeyControl()内でModeEnd()を行うこと。
	if (uiMode != MODE_MAP)
	{
		// 呼び出し元に処理を戻す
		return;
	}

	// 遷移後最初の呼び出しならば、
	else if (uiFirstTime == 0)
	{
		// 初回呼び出し時の設定を行い
		ModeStartSet();
		// 初回フラグをオフに設定する
		uiFirstTime = 1;
	}

	// 通常の描画を行う

	Draw();

}

// CMenuModeクラスのメソッド--------------------------------------------------------------

// コンストラクタ
CMenuMode::CMenuMode()
{
	astMenuList[0] = "編成";
	astMenuList[1] = "アイテム";
	astMenuList[2] = "セーブ";

	iMenuBackGraphicHandle[NON_SELECTED] = LoadGraph("image/Window/button_blue.png");
	iMenuBackGraphicHandle[SELECTED] = LoadGraph("image/Window/button_blue_hakkou.png");
}

// デストラクタ
CMenuMode::~CMenuMode()
{

}

// キーボード入力に対する処理
// E: メニュー画面モードへの移動
void CMenuMode::KeyControl()
{
	// 押されているキーは1つしか読み込まない仕様とする。
	// 優先度の高い処理を追加するときは上に追加すること。

	// Eキーが押されたら
	if (key[KEY_INPUT_E] == 1)
	{
		// マップモードへ移動
		uiMode = MODE_MAP;

		// マップ画面は描画したままにするので、ModeEnd()は呼ばない。
		// 初回の描画をするために初回限定スイッチだけ入れる。
		uiFirstTime = 0;
	}
}

void CMenuMode::ModeStartSet()
{

}

void CMenuMode::ModeEnd()
{
	// 通常の終了処理を行う
	CMode::ModeEnd();
}

void CMenuMode::Draw()
{
	// 背景はCMapModeクラスの描画になる
	pCMapMode->Draw();

	DrawGraph(0, 0, iMenuBackGraphicHandle[NON_SELECTED], TRUE);
	
	DrawStringToHandle(70, 30, "メニュー\n", 0xFFFFFF, iDefaultfontHandle);

}

// メイン処理-----------------------------------------------------------
// マップ画面の描写を行う
// できること:
// ・マップを切り替えて移動する
// ・メニュー画面を呼び出す
// ・表示されているマップからミッションを選択する
void CMenuMode::Run()
{
	// 計算-------------------------------------------------------------

	// キーボードの入力を処理-------------------------------------------
	KeyControl();

	// もしモードを切り替えるのであれば
	// この関数内での処理はここまで。
	// 必要に応じてKeyControl()内でModeEnd()を行うこと。
	if (uiMode != MODE_MENU)
	{
		// 呼び出し元に処理を戻す
		return;
	}

	// 遷移後最初の呼び出しならば、
	else if (uiFirstTime == 0)
	{
		// 初回呼び出し時の設定を行い
		ModeStartSet();
		// 初回フラグをオフに設定する
		uiFirstTime = 1;
	}

	// 通常の描画を行う
	Draw();

}

// CBattleModeクラスのメソッド------------------------------------------------------------

// コンストラクタ
CBattleMode::CBattleMode()
{

}

// デストラクタ
CBattleMode::~CBattleMode()
{

}

void CBattleMode::ModeStartSet()
{
	// 背景クラス作成(とりあえず川を描く)
	CBG = new CBackGround(RIVER);

	// パーティクラス作成
	pCTEAM = new CParty();

	// パーティにメンバーを登録
	pCTEAM->SetMember(0, MIKATSU);
	pCTEAM->SetMember(1, SUZUKA);

	//メンバー登録が終わったらパーティの人数を算出し、値を格納
	uiCTEAMMem = pCTEAM->GetMemberOfParty();
}

void CBattleMode::ModeEnd()
{
	// 通常の終了処理を行う
	CMode::ModeEnd();
}

void CBattleMode::Draw()
{
	// 背景描画
	CBG->DrawBackGround();

	// キャラクター描画
	// 改修予定あり
	for (unsigned int i = 0; i < uiCTEAMMem; i++)
	{

		pCTEAM->GetMember(i).DrawCharaImage();
		pCTEAM->GetMember(i).DrawHPBar();
		pCTEAM->GetMember(i).DrawTPBar();

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

void CBattleMode::Run()
{
	// 計算-------------------------------------------------------------

	// キーボードの入力を処理-------------------------------------------

	// 画面遷移処理
	// 各画面モード毎に異なるため各サブクラスで独自に実装
	// もしスペースキーが押されたら(後で条件は変更すると思う)
	if (key[KEY_INPUT_SPACE] == 1)
	{
		// 画面の番号を更新
		uiMode = MODE_MAP;
	}

	// もしモードを切り替えるのであれば画面を遷移する処理を行う
	if (uiMode != MODE_BATTLE)
	{
		// 終了処理をして
		ModeEnd();
		// 呼び出し元に処理を戻す
		return;
	}

	// 遷移後最初の呼び出しならば、
	else if (uiFirstTime == 0)
	{
		// 初回呼び出し時の設定を行い
		ModeStartSet();
		// 初回フラグをオフに設定する
		uiFirstTime = 1;
	}

	// 通常の描画を行う
	Draw();
}