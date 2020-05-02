#include"Party.h"
#include"DxLib.h"

CParty::CParty()
{

}
CParty::~CParty()
{

}

// �����o�[��ݒ肷��
// TRUE:	�ݒ萬��
// FALSE:	�ݒ莸�s
bool CParty::SetMember(unsigned int uiNum ,unsigned int iChara)
{
	// �p�[�e�B�l���͍ő�MAX_PARTY_MEM�̂��߁A
	// �Ⴆ��MAX_PARTY_MEM 4�ł����[0]�`[3]�܂ł����ݒ肵�Ȃ��B
	if (uiNum > MAX_PARTY_MEM - 1)
	{
		return FALSE;
	}

	// �ꏊ�̎w��~�X���Ȃ����
	else
	{
		// �w��̏ꏊ�ɃL��������ݒ肵��
		aCMember[uiNum].SetCharacterInfo(iChara);

		// �L�����Ƀp�[�e�B���ԍ���ݒ�
		aCMember[uiNum].SetPartyNum(uiNum);
	}

	return TRUE;
}

CCharacter CParty::GetMember(unsigned int iNum)
{
	return aCMember[iNum];
}

// �����o�[�̐l����Ԃ�
// �v�Z�������ōs��
unsigned int CParty::GetMemberOfParty()
{
	unsigned int uiResult = MAX_PARTY_MEM;

	for (int i = 0; i < MAX_PARTY_MEM; i++)
	{
		// �����񂪁u""�v�ƈ�v���Ă��遨�����o�[�����Ȃ�
		// compare�֐��͕����񂪈�v���Ă�����0���Ԃ�
		if (aCMember[i].GetCharaName().compare("") == 0)
		{
			uiResult--;
		}
	}

	MemberOfParty = uiResult;
	return MemberOfParty;
}