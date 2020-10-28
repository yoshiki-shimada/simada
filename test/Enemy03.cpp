/*******************************************************************
* @file		Enemy03.cpp
* @brief	�G3�p.cpp
* @author	yshimada
* @data		20200107
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Enemy03.h"
#include "Bullet.h"
#include "Player.h"
#include "Effect.h"
#include <math.h>

/*****************************************
* @brief Enemy03�R���X�g���N�^
*****************************************/
CZakoEnemy3::CZakoEnemy3(float x, float y)
	: CEnemy03(x, y, ZENEMY_CHIP_HARF_Y, 3, 1, 100), nCount(0), rad(0), fBulletSpeed(1)
{
	SH->ECount++;
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CZakoEnemy3::Move() {

	if (nCount % 200 == 0) {
		PlaySoundMem(SH->SHBullet, DX_PLAYTYPE_BACK);
		CRemTaskIter i(SH->PlayerList);
		CPlayer *player = (CPlayer*)i.Next();
		rad = atan2(player->Y - Y, player->X - X);
		// �e�̐���
		new CDirBullet(X, Y, rad, 1.2f, 1.0f, 2, 1);
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
void CZakoEnemy3::Draw() {
	DrawGraphF(X - ZENEMY_CHIP_HARF_X, Y - ZENEMY_CHIP_HARF_Y,
		SH->GHZEnemy03[(nCount / ZENEMY_ANIM_SPEED) % ZENEMY_PATTERN],
		TRUE
	);
}

