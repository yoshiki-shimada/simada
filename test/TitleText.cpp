/*******************************************************************
* @file		Title.h
* @brief	TitleClass.cpp
* @author	yshimada
* @data		20200110
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Selector.h"
#include "TitleText.h"

bool CTitleText::Move()
{
	// �L�[�ɂ����̈ړ�����
	if (SH->TitleMenuPos == MENU_FIRST)
		Y = TEXT_POS_Y_0;
	else
		Y = TEXT_POS_Y_1;

	// ���̓���
	if (X <= 0.0f) {
		X = 20.0f;
	}
	X -= 0.5f;

	return true;
}

void CTitleText::Draw()
{
	// �^�C�g���w�i
	DrawGraphF(0, 0,
		SH->GHTitle,
		FALSE
	);
	// �e�L�X�g01
	DrawGraphF(((SCREEN_WIDTH *0.5) - (TEXT01_SIZE_X * 0.5)), TEXT_POS_Y_0,
		SH->GHText01,
		TRUE
	);
	// �e�L�X�g02
	DrawGraphF(((SCREEN_WIDTH *0.5) - (TEXT02_SIZE_X * 0.5)), TEXT_POS_Y_1,
		SH->GHText02,
		TRUE
	);
	// ���
	DrawGraphF(((SCREEN_WIDTH *0.5) - (TEXT01_SIZE_X * 0.5) - YAJI_SIZE_X - 10.0f) + X, Y + TEXT_HARFHARF_Y,
		SH->GHYaji,
		TRUE
	);

}