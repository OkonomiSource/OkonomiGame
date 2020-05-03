#include "Character.h"
#include "dxlib.h"

void CCharacter::SetCharacterDefaultInfo()
{
	sStatus.uiLv = 1;

	// �o���l
	sStatus.uiEXP = 0;

	// �ő�HP
	sStatus.uiMAXHP = 20;

	// HP
	sStatus.uiHP = 20;

	// �U����
	sStatus.uiATK = 1;

	// �h���
	sStatus.uiDEF = 1;

	// �ő�CT
	sStatus.uiMAXCT = 100;

	// CT
	sStatus.uiCT = 0;

	// �ő�TP
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


// �R���X�g���N�^
CCharacter::CCharacter(){
	
	this->SetCharacterDefaultInfo();
}

//�@�f�X�g���N�^
CCharacter::~CCharacter()
{

}

// �ʂ̃L��������ݒ�
bool CCharacter::SetCharacterInfo(unsigned int uiChara)
{
	bool blResult = TRUE;

	SetCharacterDefaultInfo();

	switch (uiChara)
	{
	case MIKATSU:
		this->stCharaName[0] = "���";
		this->stCharaName[1] = "�~�J�c";

		this->stKanaCharaName[0] = "�j�W���E";
		this->stKanaCharaName[1] = "�~�J�c";

		SetCharaImage("image/Character/Mikatsu/Splitted Image 4-1.png");

		SetPartyNum(0);

		break;
	case SUZUKA:
		this->stCharaName[0] = "�����{";
		this->stCharaName[1] = "����";

		this->stKanaCharaName[0] = "�q�i�~��";
		this->stKanaCharaName[1] = "�X�Y�J";

		SetCharaImage("image/Character/Suzuka/Splitted Image 4-1.png");
		
		SetPartyNum(1);
		
		break;
	default:
		blResult = FALSE;
		break;
	}

	return blResult;
}

// �摜�Z�b�g
bool CCharacter::SetCharaImage(const char dir[])
{

	// �n���h��ID�����ݒ��Ԃł����
	if (iGraphichandle == 0)
	{
		// �n���h��ID��ݒ�
		iGraphichandle = LoadGraph(dir);

		// LoadGraph�ŃG���[���N������
		if (iGraphichandle == -1)
		{
			OutputDebugString("Error: CCharacter::SetCharaImage LoadGraph()");
			return FALSE;
		}

		// �G���[���Ȃ����
		else
		{
			// �O���t�B�b�N�T�C�Y���擾
			GetGraphSize(iGraphichandle, &iGraphicWidth, &iGraphicHeight);
			return TRUE;
		}
	}

	// �n���h��ID���ݒ肳��Ă���̂ɌĂяo���ꂽ��
	else
	{
		OutputDebugString("Error: CCharacter::SetCharaImage Handle ID already set.");
		return FALSE;
	}
}

void CCharacter::SetPartyNum(unsigned int Num)
{
	// �p�[�e�B�̍ő�l���܂ł̔ԍ��ł����
	if (Num < MAX_PARTY_MEM)
	{
		// ���̒l���p�[�e�B���ԍ��ɐݒ�
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

// �`�����W�擾�p�֐� X
// x:�|�W�V�����ԍ� 
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

// �`�����W�擾�p�֐� Y
// y:�|�W�V�����ԍ�
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
	// �߂�l�p�ϐ�
	// TRUE:�@�G���[�Ȃ�
	// FALSE: �G���[����
	bool blResult = FALSE;

	// �̗̓o�[����̍��W
	// x���W = �L�����摜�̍��㒸�_��x���W
	// y���W = �L�����摜�̍��㒸�_��y���W + �L�����摜�̍��� + �␳�l
	int ix1 = GetPositionX(uiPartyNum);
	int iy1 = GetPositionY(uiPartyNum) + iGraphicHeight;

	// �̗̓o�[�E���̍��W
	// x���W = ix1 + �L�����摜�̉���
	// y���W = iy1 + �̗̓o�[�̏c��
	int ix2 = ix1 + iGraphicWidth;
	int iy2 = iy1 + iHPBarHeight;

	// FOR DBG
	sStatus.uiHP = 15;

	// ����A�c��HP���ő�HP�𒴂��Ă�����ő�HP�ɒ���
	if (sStatus.uiHP > sStatus.uiMAXHP)
	{
		sStatus.uiHP = sStatus.uiMAXHP;
	}

	// �c��HP�̊��� = �c��HP * �ő�HP 
	double dRestHP = static_cast<double>(sStatus.uiHP) / static_cast<double>(sStatus.uiMAXHP);

	// �c���̗̓o�[�̐F���v�Z
	// �f�t�H���g�͗�
	int iHPBarColor = 0x00FF00;

	// 1/4���ォ�����ȉ��Ȃ物�F
	if (dRestHP <= 0.50 && 0.25 < dRestHP)
	{
		iHPBarColor = 0xFFFF00;
	}

	// 1/4�ȉ��Ȃ��
	else if (dRestHP <= 0.25)
	{
		iHPBarColor = 0xFF0000;
	}

	// �c���̗͕`��p��x���W= ix1 + (�L�����摜�̉��� * �c��HP�̊���)
	int irestx2 = ix1 + int(iGraphicWidth * dRestHP);

	// �ȉ��A�`����ォ��d�˂Ă���

	// �̗͌���������\��(�Â���)
	if (DrawBox(ix1, iy1, ix2, iy2, 0x660000, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// �c���̗͂�\��
	if (DrawBox(ix1, iy1, irestx2, iy2, iHPBarColor, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// HP�o�[�̘g��\��
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
	// �߂�l�p�ϐ�
	// TRUE:�@�G���[�Ȃ�
	// FALSE: �G���[����
	bool blResult = FALSE;

	// TP�o�[����̍��W
	// x���W = �L�����摜�̍��㒸�_��x���W
	// y���W = �L�����摜�̍��㒸�_��y���W + �L�����摜�̍��� + HP�o�[�̏c��
	int ix1 = GetPositionX(uiPartyNum);
	int iy1 = GetPositionY(uiPartyNum) + iGraphicHeight + iHPBarHeight;

	// �̗̓o�[�E���̍��W
	// x���W = ix1 + �L�����摜�̉���
	// y���W = iy1 + �̗̓o�[�̏c��
	int ix2 = ix1 + iGraphicWidth;
	int iy2 = iy1 + iTPBarHeight;

	// FOR DBG
	sStatus.uiTP = 2;

	// ����A����TP���ő�TP�𒴂��Ă�����ő�TP�ɒ���
	if (sStatus.uiTP > sStatus.uiMAXTP) {
		sStatus.uiTP = sStatus.uiMAXTP;
	}

	// TP�o�[�̐F���v�Z
	// �f�t�H���g�͗�
	int iTPBarColor = 0x00FF00;

	// TP�ʂɉ����ĐF��ύX
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
	// �c��TP�`��p��x���W= ix1 + (�L�����摜�̉��� * �c��HP�̊���)
	int irestx2 = ix1 + int(iGraphicWidth * dRestTP);

	// �ȉ��A�`����ォ��d�˂Ă���

	// �̗͌���������\��(�Â���)
	if (DrawBox(ix1, iy1, ix2, iy2, 0x660000, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// �c��TP��\��
	if (DrawBox(ix1, iy1, irestx2, iy2, iTPBarColor, TRUE) != 0)
	{
		blResult = FALSE;
	}
	else
	{
		blResult = TRUE;
	}

	// TP�o�[�̘g��\��
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



