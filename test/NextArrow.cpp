/*******************************************************************
* @file		NextArrow.cpp
* @brief	���̃X�e�[�W�ɍs�����߂̖��p.cpp
* @author	yshimada
* @data		20200109
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "NextArrow.h"

//bool CNextArrow::Move() {
//	ChipNum++;
//
//	return true;
//}

/*****************************************
* @brief �`��
*****************************************/
void CNextArrow::Draw() {
	ChipNum++;

	DrawGraphF(X - ARROW_SIZE_HARF, 100.0f,
		SH->GHArrow[(ChipNum / ARROW_ANIM_SPEED) % ARROW_PATTERN],
		TRUE
	);
}