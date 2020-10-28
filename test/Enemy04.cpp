/*******************************************************************
* @file		Enemy04.cpp
* @brief	�G4�p.cpp
* @author	yshimada
* @data		20200107
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Enemy04.h"
#include "Bullet.h"
#include "Player.h"
#include "Effect.h"
#include <math.h>


/*****************************************
* @brief Enemy04�R���X�g���N�^
*****************************************/
CZakoEnemy4::CZakoEnemy4(float x, float y)
	: CEnemy04(x, y, ZENEMY_CHIP_HARF_Y, 4, 1, 100), nCount(0), rad(0.0f), fBulletSpeed(1)
{
	SH->ECount++;
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CZakoEnemy4::Move() {

	if (nCount % 200 == 0) {
		PlaySoundMem(SH->SHBullet, DX_PLAYTYPE_BACK);
		// �e�̐���
		for (int r = 0; r < 10; r++) {
			rad = (int)rand() % 360;
			new CDirBullet(X, Y, rad, 1.2f, 1.2f, 1, 1);
		}
		nCount = 0;
	}
	nCount++;

	//! ����
	if (Vit <= 0) {
		PlaySoundMem(SH->SHCrash, DX_PLAYTYPE_BACK);
		new CEnemyCrash(X, Y);
		SH->ECount--;
		//! �Q�[���N���A����
		if (SH->ECount <= 0) {
			SH->m_eStagePhase = NextStage;
		}
		return false;
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CZakoEnemy4::Draw() {
	DrawGraphF(X - ZENEMY_CHIP_HARF_X, Y - ZENEMY_CHIP_HARF_Y,
		SH->GHZEnemy04[(nCount / ZENEMY_ANIM_SPEED) % ZENEMY_PATTERN],
		TRUE
	);
}