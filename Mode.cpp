#include"Mode.h"
#include"dxlib.h"
#include"Character.h"

// グローバル関数----------------------------------------------------------------

// キーが押下された瞬間だけ処理したいときのための関数
// メイン関数で事前に1回呼び出し、
// Key[KEY_INPUT_〇〇〇] == 1 のとき処理が実行されるようにすれば
// キーが押された瞬間だけ処理を実行することになる

int key[256]; // 0:入力されていない 1:入力された瞬間 2:入力されている
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

// クラスのメソッド----------------------------------------------------------------

CMode::CMode()
{
	uiMode = MODE_MAP;
	uiBeforeMode = MODE_MAP;
	iDbgFontHandle = 0;

}

CMode::~CMode()
{

}

// 場面遷移用関数
void CMode::ChangeModeNum(unsigned int Num)
{
	// 引数にされた番号に応じて画面遷移
	// 規定外の番号なら何もせずに終わる(引数不正の警告は出力する)
	switch (Num)
	{
	case MODE_MAP:
		uiMode = MODE_MAP;
		break;

	case MODE_BATTLE:
		uiMode = MODE_BATTLE;
		break;

	default:
		OutputDebugString("Mistake: CMode::ChangeModeNum()\n");
		break;
	}
}

// 現在の場面の番号を返す
unsigned int CMode::GetModeNum()
{
	return uiMode;
}


// メイン関数にフォントを設定してもらう
void CMode::SetFont(int iFont)
{

	iDbgFontHandle = iFont;

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
	// 万一、マップ画面でないのに呼び出されたら
	if (uiMode != MODE_MAP)
	{
		// エラーを出して
		OutputDebugString("Error Occured:	CMode::MapMode()");
		// 処理を呼び出し元に返す
		return;
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

	// もし画面遷移が発生していたら
	if(uiBeforeMode != uiMode)
	{
		// 今描画しているものを消して呼び出し元に処理を戻す
		ClearDrawScreen();
		return;
	}

	// 画面遷移が起こっていなければ以下の処理を実施
	// 描画は画面奥側のものから順に描写すること
	else {

		// 背景画像を描写


		// FOR DBG
		DrawStringToHandle(0, 0, "メイン画面です\n", 0xFFFFFF, iDbgFontHandle);
	}
}

void CMode::BattleMode()
{
	// 万一、バトル画面でないのに呼び出されたら
	if (uiMode != MODE_BATTLE)
	{
		// エラーを出して
		OutputDebugString("Error Occured:	CMode::BattleMode()");
		// 処理を呼び出し元に返す
		return;
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

	// キャラクタークラス作成
	CMikatsu* NIJO = new CMikatsu();
	CSuzuka* HINAMIYA = new CSuzuka();

	// 描画-------------------------------------------------------------
	// もし画面遷移が発生していたら
	if (uiBeforeMode != uiMode)
	{
		// 今描画しているものを消して呼び出し元に処理を戻す
		ClearDrawScreen();
		return;
	}
	// 画面遷移が起こっていなければ以下の処理を実施
	// 描画は画面奥側のものから順に描写すること
	else {

		// キャラクター描画
		NIJO->DrawCharaImage();
		HINAMIYA->DrawCharaImage();

		// HPバー描画
		NIJO->DrawHPBar();
		HINAMIYA->DrawHPBar();

		// TPバー描画
		NIJO->DrawTPBar();
		HINAMIYA->DrawTPBar();

		// メッセージウィンドウ描画
		int iMsgWindowHandle = LoadGraph("image/Window/msgbox_blue.png");
		DrawExtendGraph(0, 350, 641, 481, iMsgWindowHandle, TRUE);

		// メッセージ描画
		for (int i = 0; i < 5; i++)
		{
			DrawStringToHandle(20, 375 + i * 18, "極天脚！\n", 0xFFFFFF, iDbgFontHandle);
		}
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