#include"Party.h"
#include"DxLib.h"

CParty::CParty()
{

}
CParty::~CParty()
{

}

// メンバーを設定する
// TRUE:	設定成功
// FALSE:	設定失敗
bool CParty::SetMember(unsigned int uiNum ,unsigned int iChara)
{
	// パーティ人数は最大MAX_PARTY_MEMのため、
	// 例えばMAX_PARTY_MEM 4であれば[0]～[3]までしか設定しない。
	if (uiNum > MAX_PARTY_MEM - 1)
	{
		return FALSE;
	}

	// 場所の指定ミスがなければ
	else
	{
		// 指定の場所にキャラ情報を設定して
		aCMember[uiNum].SetCharacterInfo(iChara);

		// キャラにパーティ内番号を設定
		aCMember[uiNum].SetPartyNum(uiNum);
	}

	return TRUE;
}

CCharacter CParty::GetMember(unsigned int iNum)
{
	return aCMember[iNum];
}

// メンバーの人数を返す
// 計算もここで行う
unsigned int CParty::GetMemberOfParty()
{
	unsigned int uiResult = MAX_PARTY_MEM;

	for (int i = 0; i < MAX_PARTY_MEM; i++)
	{
		// 文字列が「""」と一致している→メンバーがいない
		// compare関数は文字列が一致していたら0が返る
		if (aCMember[i].GetCharaName().compare("") == 0)
		{
			uiResult--;
		}
	}

	MemberOfParty = uiResult;
	return MemberOfParty;
}