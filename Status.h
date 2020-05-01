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
	// �X�L����
	std::string stSkillName;

	// �З�
	int iPower;

	// ����TP
	int iConTP;

	// �K���R�X�g
	int iCost;

	// ����
	int iTypeA;
	int iTypeB;

	// ������ʂ͊e�X�L���̊֐����ɋL�q����B

}Skill;


typedef struct 
{

	// ���x��
	int uiLv;

	// �o���l
	int uiEXP;

	// �ő�HP
	int uiMAXHP;

	// HP
	int uiHP;

	// �U����
	int uiATK;

	// �h���
	int uiDEF;

	// �ő�CT
	int uiMAXCT;

	// CT
	int uiCT;

	// �ő�TP
	int uiMAXTP;

	// TP
	int uiTP;

}Status;

