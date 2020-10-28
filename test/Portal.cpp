/*******************************************************************
* @file		Portal.cpp
* @brief	�|�[�^���p.cpp
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
* @brief �R���X�g���N�^
*****************************************/
CPortal::CPortal(float x, float y, double dir)
	: CMover(SH->PortalList, x, y, PORTAL_SIZE_HARFCOLLI),
	nCount(0), nRotSpeed(5), nChipNam(0), dPortaldir(dir), dRotdir(PI * 0.25 * 0.25), bSetPortal(false), bRefPortal(false), m_ePortal(NOTREFPORTAL)
{
}

/*****************************************
* @brief �ړ�
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
* @brief �`��
*****************************************/
void CPortal::Draw() {

	int a = 0;
	DrawRotaGraph(X, Y, 1.0, dPortaldir,
		SH->GHPortal[nChipNam], TRUE);
}

/**
* @brief	�|�[�^���̏�ԃ`�F�b�N
*/
void CPortal::CheckRefPortal()
{
	new CPortalEffect(X, Y);
	//! �����O
	switch (m_ePortal) {
	case REFPORTAL:
		m_ePortal = NOTREFPORTAL;
		nChipNam = 0;
		nCount = 0;
		break;

	case NOTREFPORTAL:
		m_ePortal = REFPORTAL;
		//! �����o���p�[�ɐؑ�
		nChipNam = 5;
		nCount = 0;
		break;

	}
}

/**
* @brief	���˃|�[�^���ւ̕ω�
*/
void CPortal::SetHit()
{
	nCount = 0;
	nChipNam = 7;
}

/**
* @brief	�����O�̐����p�֐�
* @param	[in]	Num �X�e�[�W�ԍ�
*/
CSpownPortal::CSpownPortal(int Num)
{
	switch (Num)
	{
	case 0: // �l�p

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.75, PI);
		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.75, PI * 180);
		break;

	case 1: // �O�p

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.75, PI * 90);
		break;
	
	case 2: // �X��

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.25, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.75, PI * 180);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, PI * 90);
		break;

	case 3: // �t�X��

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.75, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.25, PI);
		new CPortal(SCREEN_WIDTH * 0.5, SCREEN_HEIGHT * 0.5, PI * 90);
		break;

	case 4: // ��

		new CPortal(SCREEN_WIDTH * 0.75, SCREEN_HEIGHT * 0.5, PI);
		new CPortal(SCREEN_WIDTH * 0.25, SCREEN_HEIGHT * 0.5, PI);
		break;
	}

}