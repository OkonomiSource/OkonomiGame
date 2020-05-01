#pragma once

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

	// ���݂̃��[�h�ԍ�
	unsigned int uiMode;
	// �O��̃��[�h�ԍ�(��ʑJ�ڎ��p)
	unsigned int uiBeforeMode;

	// ���ʃt�H���g�n���h��ID���p�ϐ�(���Ƃŏ�������)
	int iDbgFontHandle;

protected:
public:


private:

protected:
public:

	CMode();
	~CMode();

	// ��ʑJ�ڗp�֐�
	void ChangeModeNum(unsigned int Num);

	// ���݂̏�ʂ̔ԍ���Ԃ�
	unsigned int GetModeNum();

	// ���C���֐��Ƀt�H���g��ݒ肵�Ă��炤
	void SetFont(int iFont);

	// ���C�����[�h����
	void MapMode();
	void BattleMode();
	void Run();



};