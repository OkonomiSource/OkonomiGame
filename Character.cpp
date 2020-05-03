#include "Character.h"
#include "dxlib.h"

void CCharacter::SetCharacterDefaultInfo()
{
	sStatus.uiLv = 1;

	// 経験値
	sStatus.uiEXP = 0;

	// 最大HP
	sStatus.uiMAXHP = 20;

	// HP
	sStatus.uiHP = 20;

	// 攻撃力
	sStatus.uiATK = 1;

	// 防御力
	sStatus.uiDEF = 1;

	// 最大CT
	sStatus.uiMAXCT = 100;

	// CT
	sStatus.uiCT = 0;

	// 最大TP
	sStatus.uiMAXTP = 3;

	// TP
	sStatus.uiTP = 1;

	for (int i = 0; i < FULLSKILL; i++)
	{

		sSkill[i].stSkillName = "";
		sSkill[i].iPower = 0;
		sSkill[i].iConTP = 0;
		sSkill[i].iCost = 0;
		sSkill[i].iTypeA = A_NON;
		sSkill[i].iTypeB = B_NON;

	}
}


// コンストラクタ
CCharacter::CCharacter(){
	
	this->SetCharacterDefaultInfo();
}

//　デストラクタ
CCharacter::~CCharacter()
{

}

// 個別のキャラ情報を設定
bool CCharacter::SetCharacterInfo(unsigned int uiChara)
{
	bool blResult = TRUE;

	SetCharacterDefaultInfo();

	switch (uiChara)
	{
	case MIKATSU:
		this->stCharaName[0] = "二条";
		this->stCharaName[1] = "ミカツ";

		this->stKanaCharaName[0] = "ニジョウ";
		this->stKanaCharaName[1] = "ミカツ";

		SetCharaImage("image/Character/Mikatsu/Splitted Image 4-1.png");

		SetPartyNum(0);

		break;
	case SUZUKA:
		this->stCharaName[0] = "日向宮";
		this->stCharaName[1] = "涼花";

		this->stKanaCharaName[0] = "ヒナミヤ";
		this->stKanaCharaName[1] = "スズカ";

		SetCharaImage("image/Character/Suzuka/Splitted Image 4-1.png");
		
		SetPartyNum(1);
		
		break;
	default:
		blResult = FALSE;
		break;
	}

	return blResult;
}

// 画像セット
bool CCharacter::SetCharaImage(const char dir[])
{

	// ハンドルIDが未設定状態であれば
	if (iGraphichandle == 0)
	{
		// ハンドルIDを設定
		iGraphichandle = LoadGraph(dir);

		// LoadGraphでエラーが起きたら
		if (iGraphichandle == -1)
		{
			OutputDebugString("Error: CCharacter::SetCharaImage LoadGraph()");
			return FALSE;
		}

		// エラーがなければ
		else
		{
			// グラフィックサイズを取得
			GetGraphSize(iGraphichandle, &iGraphicWidth, &iGraphicHeight);
			return TRUE;
		}
	}

	// ハンドルIDが設定されているのに呼び出されたら
	else
	{
		OutputDebugString("Error: CCharacter::SetCharaImage Handle ID already set.");
		return FALSE;
	}
}

void CCharacter::SetPartyNum(unsigned int Num)
{
	// パーティの最大人数までの番号であれば
	if (Num < MAX_PARTY_MEM)
	{
		// その値をパーティ内番号に設定
		uiPartyNum = Num;
	}

	else
	{
		return;
	}
}

std::string CCharacter::GetCharaName()
{
	return stCharaName[1];
}

// 描画先座標取得用関数 X
// x:ポジション番号 
int CCharacter::GetPositionX(int x)
{
	switch (x)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		return PositionNum[x][0];
		break;
	default:
		return -1;
		break;
	}

}

// 描画先座標取得用関数 Y
// y:ポジション番号
int CCharacter::GetPositionY(int y)
{
	switch (y)
	{
	case 0:
	case 1:
	case 2:
	case 3:
		return PositionNum[y][1];
		break;
	default:
		return -1;
		break;
	}

}

bool CCharacter::DrawHPBar()
{
	// 戻り値用変数
	// TRUE:　エラーなし
	// FALSE: エラーあり
	bool blResult = FALSE;

	// 体力バー左上の座標
	// x座標 = キャラ画像の左上頂点のx座標
	// y座標 = キャラ画像の左上頂点のy座標 + キャラ画像の高さ + 補正値
	int ix1 = GetPositionX(uiPartyNum);
	int iy1 = GetPositionY(uiPartyNum) + iGraphicHeight;

	// 体力バー右下の座標
	// x座標 = ix1 + キャラ画像の横幅
	// y座標 = iy1 + 体力バーの縦幅
	int ix2 = ix1 + iGraphicWidth;
	int iy2 = iy1 + iHPBarHeight;

	// FOR DBG
	sStatus.uiHP = 15;

	// 万一、残存HPが最大HPを超えていたら最大HPに直す
	if (sStatus.uiHP > sStatus.uiMAXHP)
	{
		sStatus.uiHP = sStatus.uiMAXHP;
	}

	// 残存HPの割合 = 残存HP * 最大HP 
	double dRestHP = static_cast<double>(sStatus.uiHP) / static_cast<double>(sStatus.uiMAXHP);

	// 残存体力バーの色を計算
	// デフォルトは緑
	int iHPBarColor = 0x00FF00;

	// 1/4より上かつ半分以下なら黄色
	if (dRestHP <= 0.50 && 0.25 < dRestHP)
	{
		iHPBarColor = 0xFFFF00;
	}

	// 1/4以下なら赤
	else if (dRestHP <= 0.25)
	{
		iHPBarColor = 0xFF0000;
	}

	// 残存体力描画用のx座標= ix1 + (キャラ画像の横幅 * 残存HPの割合)
	int irestx2 = ix1 + int(iGraphicWidth * dRestHP);

	// 以下、描画を上から重ねていく

	// 体力減少部分を表示(暗い赤)
	if (DrawBox(ix1, iy1, ix2, iy2, 0x660000, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// 残存体力を表示
	if (DrawBox(ix1, iy1, irestx2, iy2, iHPBarColor, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// HPバーの枠を表示
	if (DrawBox(ix1, iy1, ix2, iy2, 0xFFFFFF, FALSE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	return blResult;
}

bool CCharacter::DrawTPBar()
{
	// 戻り値用変数
	// TRUE:　エラーなし
	// FALSE: エラーあり
	bool blResult = FALSE;

	// TPバー左上の座標
	// x座標 = キャラ画像の左上頂点のx座標
	// y座標 = キャラ画像の左上頂点のy座標 + キャラ画像の高さ + HPバーの縦幅
	int ix1 = GetPositionX(uiPartyNum);
	int iy1 = GetPositionY(uiPartyNum) + iGraphicHeight + iHPBarHeight;

	// 体力バー右下の座標
	// x座標 = ix1 + キャラ画像の横幅
	// y座標 = iy1 + 体力バーの縦幅
	int ix2 = ix1 + iGraphicWidth;
	int iy2 = iy1 + iTPBarHeight;

	// FOR DBG
	sStatus.uiTP = 2;

	// 万一、現在TPが最大TPを超えていたら最大TPに直す
	if (sStatus.uiTP > sStatus.uiMAXTP) {
		sStatus.uiTP = sStatus.uiMAXTP;
	}

	// TPバーの色を計算
	// デフォルトは緑
	int iTPBarColor = 0x00FF00;

	// TP量に応じて色を変更
	switch (sStatus.uiTP)
	{
	case 1:
		iTPBarColor = 0xFFFFFF;
		break;
	case 2:
		iTPBarColor = 0x88DDDD;
		break;
	case 3:
		iTPBarColor = 0x00FFFF;
		break;
	default:
		break;
	}
	double dRestTP = static_cast<double>(sStatus.uiTP) / static_cast<double>(sStatus.uiMAXTP);
	// 残存TP描画用のx座標= ix1 + (キャラ画像の横幅 * 残存HPの割合)
	int irestx2 = ix1 + int(iGraphicWidth * dRestTP);

	// 以下、描画を上から重ねていく

	// 体力減少部分を表示(暗い赤)
	if (DrawBox(ix1, iy1, ix2, iy2, 0x660000, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// 残存TPを表示
	if (DrawBox(ix1, iy1, irestx2, iy2, iTPBarColor, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// TPバーの枠を表示
	if (DrawBox(ix1, iy1, ix2, iy2, 0xFFFFFF, FALSE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	return blResult;
}


bool CCharacter::DrawCharaImage() {

	if (DrawGraph(GetPositionX(uiPartyNum), GetPositionY(uiPartyNum), iGraphichandle, TRUE) == -1) {

		OutputDebugString("Error: CCharacter::DrawCharaImage DrawGraph()");
		return FALSE;
	}

	else
	{
		return TRUE;
	}

}



