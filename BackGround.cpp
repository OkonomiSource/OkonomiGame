#include"BackGround.h"

// �R���X�g���N�^
CBackGround::CBackGround()
{

}

CBackGround::CBackGround(unsigned int uiBG)
{
	SetMapChips(uiBG);
}

// �f�X�g���N�^
CBackGround::~CBackGround()
{
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		for (int j = 0; j < BG_X_MAX; j++) {
			DeleteGraph(iMapchips_Bottom[i][j]);
		}
	}
}

void CBackGround::SetMapChips(unsigned int uiBG)
{
	switch (uiBG)
	{
	case GROUND:
		// �c����ݒ�
		for (int i = 0; i < BG_Y_MAX; i++)
		{
			// ������ݒ�
			for (int j = 0; j < BG_X_MAX; j++) {
				this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/pipo-map001_at-sabaku/04.png");
			}
		}
		break;
	case RIVER:
		// �c����ݒ�
		for (int i = 0; i < BG_Y_MAX; i++)
		{
			// ������ݒ�
			for (int j = 0; j < BG_X_MAX; j++) {
				this->iMapchips_Bottom[i][j] = LoadGraph("image/Mapchip/640x480/pipo-map001_at-umi/04.png");
			}
		}
		break;

	default:
		break;
	}
}

void CBackGround::DrawBackGround()
{
	for (int i = 0; i < BG_Y_MAX; i++)
	{
		// ������ݒ�
		for (int j = 0; j < BG_X_MAX; j++) {
			DrawGraph(j * 32, i * 32, this->iMapchips_Bottom[i][j], TRUE);
		}
	}


}
