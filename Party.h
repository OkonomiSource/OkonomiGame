#pragma once
#include"Character.h"

// �p�[�e�B�N���X
class CParty
{
private:

	// �p�[�e�B
	// �e�v�f�ɃL�����N�^�[������
	// �ő�l����MAX_PARTY_MEM �܂ŁB
	CCharacter aCMember[MAX_PARTY_MEM] = {};

	// �p�[�e�B�̐l��
	unsigned int MemberOfParty = 0;

protected:
public:

private:
protected:
public:

	CParty();
	~CParty();

	// �p�[�e�B�̃����o�[��ݒ�
	bool SetMember(unsigned int iNum, unsigned int iChara);

	// �p�[�e�B�̃����o�[���擾
	CCharacter GetMember(unsigned int iNum);

	// �p�[�e�B�̐l�����擾
	unsigned int GetMemberOfParty();
};