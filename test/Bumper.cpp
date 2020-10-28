/*******************************************************************
* @file		Bumper.cpp
* @brief	�o���p�[�p.cpp
* @author	yshimada
* @data		20191222
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Bumper.h"
#include "Selector.h"

/*****************************************
* @brief �o���p�[�N���X
*****************************************/
CBumper::CBumper(float x, float y, float rad) : CMover(SH->BumperList, x, y, BUMPER_HARF_X, BUMPER_HARF_Y), fRad(rad), nCount(0)
{
}

/*****************************************
* @brief �ړ��N���X
*****************************************/
bool CBumper::Move()
{
	nCount++;

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CBumper::Draw()
{
	// �o���p�[
	DrawRotaGraph(X, Y, 1.0, fRad,
		SH->GHBumper[(nCount / BUMPER_ANIM_SPEED) % BUMPER_PATTERN],
		TRUE);
}

/**
* @brief	�o���p�[�����֐�
* @param	[in]	Num �X�e�[�W�ԍ�
*/
CSpownBumper::CSpownBumper(int Num)
{
	switch (Num)
	{
	case 0:
		//new CBumper(SCREEN_WIDTH * 0.5, BUMPER_POS - BUMPER_SIZE_Y, PI);
		//new CBumper(SCREEN_WIDTH * 0.5, (SCREEN_HEIGHT - BUMPER_POS) + BUMPER_SIZE_Y, PI);
		new CBumper(BUMPER_POS - BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, -PI_HARF);
		new CBumper((SCREEN_WIDTH - BUMPER_POS) + BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, PI_HARF);
		break;

	case 1:
		//new CBumper(SCREEN_WIDTH * 0.5, BUMPER_POS - BUMPER_SIZE_Y, PI);
		//new CBumper(SCREEN_WIDTH * 0.5, (SCREEN_HEIGHT - BUMPER_POS) + BUMPER_SIZE_Y, PI);
		new CBumper(BUMPER_POS - BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, -PI_HARF);
		new CBumper((SCREEN_WIDTH - BUMPER_POS) + BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, PI_HARF);
		break;

	case 2:
		//new CBumper(SCREEN_WIDTH * 0.5, BUMPER_POS - BUMPER_SIZE_Y, PI);
		//new CBumper(SCREEN_WIDTH * 0.5, (SCREEN_HEIGHT - BUMPER_POS) + BUMPER_SIZE_Y, PI);
		new CBumper(BUMPER_POS - BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, -PI_HARF);
		new CBumper((SCREEN_WIDTH - BUMPER_POS) + BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, PI_HARF);
		break;

	case 3:
		//new CBumper(SCREEN_WIDTH * 0.5, BUMPER_POS - BUMPER_SIZE_Y, PI);
		//new CBumper(SCREEN_WIDTH * 0.5, (SCREEN_HEIGHT - BUMPER_POS) + BUMPER_SIZE_Y, PI);
		new CBumper(BUMPER_POS - BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, -PI_HARF);
		new CBumper((SCREEN_WIDTH - BUMPER_POS) + BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, PI_HARF);
		break;

	case 4:
		//new CBumper(SCREEN_WIDTH * 0.5, BUMPER_POS - BUMPER_SIZE_Y, PI);
		//new CBumper(SCREEN_WIDTH * 0.5, (SCREEN_HEIGHT - BUMPER_POS) + BUMPER_SIZE_Y, PI);
		new CBumper(BUMPER_POS - BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, -PI_HARF);
		new CBumper((SCREEN_WIDTH - BUMPER_POS) + BUMPER_SIZE_Y, SCREEN_HEIGHT * 0.5, PI_HARF);
		break;

	}

}