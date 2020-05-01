#pragma once
#include <string>

enum TypeA {

	A_NON,
	FIRE,
	WIND,
	LAND,
	AQUA

};

enum TypeB {

	B_NON,
	BLADE,
	PUNCH,
	GHOST,
	YOU

};

typedef struct 
{
	// スキル名
	std::string stSkillName;

	// 威力
	int iPower;

	// 消費TP
	int iConTP;

	// 習得コスト
	int iCost;

	// 属性
	int iTypeA;
	int iTypeB;

	// 特殊効果は各スキルの関数内に記述する。

}Skill;


typedef struct 
{

	// レベル
	int uiLv;

	// 経験値
	int uiEXP;

	// 最大HP
	int uiMAXHP;

	// HP
	int uiHP;

	// 攻撃力
	int uiATK;

	// 防御力
	int uiDEF;

	// 最大CT
	int uiMAXCT;

	// CT
	int uiCT;

	// 最大TP
	int uiMAXTP;

	// TP
	int uiTP;

}Status;

