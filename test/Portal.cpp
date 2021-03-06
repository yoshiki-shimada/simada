/*******************************************************************
* @file		Portal.cpp
* @brief	ポータル用.cpp
* @author	yshimada
* @data		20191217
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Portal.h"
#include "Selector.h"
#include "Effect.h"

#define PI2 PI * 2

/*****************************************
* @brief コンストラクタ
*****************************************/
CPortal::CPortal(float x, float y, double dir)
	: CMover(SH->PortalList, x, y, PORTAL_SIZE_HARFCOLLI),
	nCount(0), nRotSpeed(5), nChipNam(0), dPortaldir(dir), dRotdir(PI * 0.25 * 0.25), bSetPortal(false), bRefPortal(false), m_ePortal(NOTREFPORTAL)
{
}

/*****************************************
* @brief 移動
*****************************************/
bool CPortal::Move() {
	nCount++;

	switch (m_ePortal) {
	case REFPORTAL:
		if ((nChipNam == 5 || nChipNam == 7) && nCount >= 10)
			nChipNam = 6;

		break;

	case NOTREFPORTAL:
		if (nCount >= nRotSpeed) {
			dPortaldir += dRotdir;
			if (dPortaldir > PI2)
				dPortaldir -= PI2;

			nCount = 0;
		}
		break;

	}


	return true;
}

/*****************************************
* @brief 描画
*****************************************/
void CPortal::Draw() {

	int a = 0;
	DrawRotaGraph(X, Y, 1.0, dPortaldir,
		SH->GHPortal[nChipNam], TRUE);
}

/**
* @brief	ポータルの状態チェック
*/
void CPortal::CheckRefPortal()
{
	new CPortalEffect(X, Y);
	//! リング
	switch (m_ePortal) {
	case REFPORTAL:
		m_ePortal = NOTREFPORTAL;
		nChipNam = 0;
		nCount = 0;
		break;

	case NOTREFPORTAL:
		m_ePortal = REFPORTAL;
		//! 透明バンパーに切替
		nChipNam = 5;
		nCount = 0;
		break;

	}
}

/**
* @brief	反射ポータルへの変化
*/
void CPortal::SetHit()
{
	nCount = 0;
	nChipNam = 7;
}

/**
* @brief	リングの生成用関数
* @param	[in]	Num ステージ番号
*/
CSpownPortal::CSpownPortal(int Num)
{
	switch (Num)
	{
	case 0: // 四角

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.75, PI);
		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.75, PI * 180);
		break;

	case 1: // 三角

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.75, PI * 90);
		break;
	
	case 2: // スラ

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.75, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, PI * 90);
		break;

	case 3: // 逆スラ

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.75, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, PI * 90);
		break;

	case 4: // 一

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.5, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.5, PI);
		break;
	}

}