/*******************************************************************
* @file		Effect.cpp
* @brief	�G�t�F�N�g.cpp
* @author	yshimada
* @data		20200107
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Effect.h"

/*****************************************
* @brief �v���C���[�̃N���b�V���p�R���X�g���N�^
*****************************************/
CPlayerCrash::CPlayerCrash(float x, float y)
	: CEffect(x, y), Time(0), Count(0)
{
	//PlaySoundMem(SH->SHCrash, DX_PLAYTYPE_BACK);
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CPlayerCrash::Move() {

	Time++;
	Count++;

	if (Time >= 60) {
		// �V�������@�𕜊�������
		//new CRevivalMyShip(X, Y);
		//! �Q�[���I�[�o�[��Flag��؂�ւ���
		SH->Count = -1;

		// ����������
		return false;
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CPlayerCrash::Draw() {
	DrawGraphF(X - (PCRASH_CHIP_SIZE / 2), Y - (PCRASH_CHIP_SIZE / 2),
		SH->GHPCrash[(Count / CRASH_ANIM_SPEED) % PCRASH_PATTERN],
		TRUE
	);
}

/*****************************************
* @brief �G�l�~�[�̃N���b�V���p�R���X�g���N�^
*****************************************/
CEnemyCrash::CEnemyCrash(float x, float y)
	: CEffect(x, y), Time(0), Count(0)
{
	//PlaySoundMem(SH->SHCrash, DX_PLAYTYPE_BACK);
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CEnemyCrash::Move() {

	Time++;
	Count++;

	if (Time >= 30) {
		// ����������
		return false;
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CEnemyCrash::Draw() {
	DrawGraphF(X - (ECRASH_CHIP_SIZE / 2), Y - (ECRASH_CHIP_SIZE / 2),
		SH->GHECrash[(Count / CRASH_ANIM_SPEED) % ECRASH_PATTERN],
		TRUE
	);
}


/*****************************************
* @brief �|�[�^���ω��p�R���X�g���N�^
*****************************************/
CPortalEffect::CPortalEffect(float x, float y)
	: CEffect(x, y), Time(0), Count(0)
{
	//PlaySoundMem(SH->SHCrash, DX_PLAYTYPE_BACK);
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CPortalEffect::Move() {

	Time++;
	Count++;

	if (Time >= 30) {
		// ����������
		return false;
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CPortalEffect::Draw() {
	DrawGraphF(X - (PORTAL_EFFECT_SIZE / 2), Y - (PORTAL_EFFECT_SIZE / 2),
		SH->GHPortalEffect[(Count / CRASH_ANIM_SPEED) % PORTAL_EFFECT_PATTERN],
		TRUE
	);
}