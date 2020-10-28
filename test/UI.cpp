/*******************************************************************
* @file		UI.cpp
* @brief	UI�p.cpp
* @author	yshimada
* @data		20201210
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "UI.h"

/*****************************************
* @brief �`��
*****************************************/
void CUI::Draw()
{
	// ���[�^�[
	DrawGraphF(SCREEN_WIDTH_ANDUI - METAR_CHIP_SIZE_X - 50, 0,
		SH->GHMetar[SH->Count],
		TRUE
	);
	// ���[���e�L�X�g
	DrawGraphF(SCREEN_WIDTH_ANDUI - RULE_SIZE, 400,
		SH->GHRule,
		TRUE
	);
}