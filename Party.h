#pragma once
#include"Character.h"

// パーティクラス
class CParty
{
private:

	// パーティ
	// 各要素にキャラクターが入る
	// 最大人数はMAX_PARTY_MEM まで。
	CCharacter aCMember[MAX_PARTY_MEM] = {};

	// パーティの人数
	unsigned int MemberOfParty = 0;

protected:
public:

private:
protected:
public:

	CParty();
	~CParty();

	// パーティのメンバーを設定
	bool SetMember(unsigned int iNum, unsigned int iChara);

	// パーティのメンバーを取得
	CCharacter GetMember(unsigned int iNum);

	// パーティの人数を取得
	unsigned int GetMemberOfParty();
};