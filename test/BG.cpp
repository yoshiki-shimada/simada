/*******************************************************************
* @file		BG.cpp
* @brief	ステージ背景.cpp
* @author	yshimada
* @data		20191216
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "BG.h"
#include "Selector.h"

/*****************************************
* @brief 背景クラス
*****************************************/
// 背景の変更　もしかしたらステージ追加するかも
bool CBGStage1::Move()
{
	if (SH->m_ePhase == Run)
		BGChipNum = 0;
	else if (SH->m_ePhase == End)
		BGChipNum = 1;
	else
		BGChipNum = 2;

	return true;
}

/*****************************************
* @brief	描画
*****************************************/
void CBGStage1::Draw()
{
	// 床
	DrawGraphF((SCREEN_WIDTH - BGSTAGE1_SIZE_X) * 0.5, 0,
		SH->GHStageFloor[BGChipNum],
		TRUE
	);
}
