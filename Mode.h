#pragma once
#include"Party.h"


enum MODENUM {

	// �o�g���ɓ���O�̃��C�����(�}�b�v��z��)
	MODE_MAP = 1000,

	// �o�g�����̏��
	MODE_BATTLE = 2000

};

// ���[�h�N���X
// �e��ʃ��[�h���Ǘ����A���[�h�ԍ��ɉ��������������s����
class CMode {

private:
	CParty *CTEAM = NULL;
	unsigned int uiCTEAMMem = 0;

protected:
public:


private:

protected:
public:

	CMode();
	~CMode();

	// ���C�����[�h����
	void MapMode();
	void BattleMode();
	void Run();

};

class MapMode :public CMode
{
//	�ϐ�----------------------------------------------------------------
private:
protected:
public:

//	�֐�----------------------------------------------------------------
private:
protected:
public:
	MapMode();
	~MapMode();

	void Run();
};