// インクルード-----------------------------------------------------
#include"dxlib.h"
#include"BackGround.h"
#include"Mode.h"

// 定数定義---------------------------------------------------------
#define FONT_SIZE_DEFAULT 18

// グローバル変数---------------------------------------------------
int iDefaultfontHandle = 0;

// プログラムは winmain から
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR IpCmdLine, int nCmdShow)
{
	// 異常チェック------------------------------------------------------------------------

	// Window設定
	// Windowモードorフルスクリーンモードの設定は
	// DxLib_Init()の前に実行すること
	SetWindowSize(640, 480);
	ChangeWindowMode(TRUE);

	// 画面の大きさの変更不可。
	SetWindowSizeChangeEnableFlag(FALSE);

	// 異常があった場合、終了
	if (DxLib_Init() == -1)
	{
		return -1;
	}

	//int k = KEY_INPUT_SPACE;
	//k = KEY_INPUT_SPACE;

	// ここから実現したい処理を開始---------------------------------------------------------

	// 初期設定-----------------------------------------------------------------------------

	// フォントの読み込み
	// .otfファイル名を指定して読み込み
	AddFontResourceEx("ロゴたいぷゴシック.otf", FR_PRIVATE, NULL);
	
	// 読み込んだ.otfファイル内のフォント名、フォントサイズ フォントの太さ、フォントのタイプ
	iDefaultfontHandle = CreateFontToHandle("07ロゴたいぷゴシック7", FONT_SIZE_DEFAULT, 1, DX_FONTTYPE_NORMAL, DX_CHARSET_DEFAULT);

	// 実体の生成
	// 画面クラス
	CMode* Scene = new CMode();

	int a = GetJoypadNum();
	printfDx("%d",a);

	unsigned int uiGameCount = 0;

	// ループ処理
	for (;;)
	{
		// 計算--------------------------------------------------------------------
		// キーの入力状態を走査する
		// 描画--------------------------------------------------------------------

		// まずは描画先を裏画面にする
		SetDrawScreen(DX_SCREEN_BACK);

		Scene->Run();

		// FOR DBG
		// ゲーム開始時からのカウント
		uiGameCount++;

		// 画面を更新する
		// フルスクリーンモードの場合、表画面と裏画面を交換
		// ウィンドウモードの場合、裏画面の内容を表画面にコピー
		ScreenFlip();

		// 特定の場所でループする時はProcessMessage()を呼び出すと安全。
		// ウィンドウの×ボタンを押すと0以外の値を返す。
		// Escまたはウィンドウの×ボタン(またはAlt + F4)で終了。
		if (ProcessMessage() != 0 || CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			break;
		}
	}

	DxLib_End();

	return 0;

}