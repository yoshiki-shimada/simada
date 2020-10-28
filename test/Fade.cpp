/*******************************************************************
* @file		Fade.cpp
* @brief	�t�F�[�h�p.cpp
* @author	yshimada
* @data		20191220
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Selector.h"
#include "Fade.h"

/*
* @brief ���ʂ̃t�F�[�h�R���X�g���N�^
*/
CNFade::CNFade(FadePhase m_Phase) : CMover(SH->NFadeList, 0, 0), m_ePhase(m_Phase), nAlphaCount(0)
{
	if (m_ePhase == FADEIN)
		nAlpha = 0;
	else
		nAlpha = 255;
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CNFade::Move() {
	if (m_ePhase == FADEIN) {
		if (nAlpha >= 255) {
			SH->bSceneFlag = false;
			// �����悤�ɂ���
			SH->bMoveFlag = false;
			return false;
		}

		nAlphaCount++;
		if (nAlphaCount > 2) {
			nAlpha += 5;
			nAlphaCount = 0;
		}
	}
	else
	{
		if (nAlpha <= 0) {
			SH->bSceneFlag = true;
			return false;
		}

		nAlphaCount++;
		if (nAlphaCount > 2) {
			nAlpha -= 5;
			nAlphaCount = 0;
			// �����Ȃ��悤�ɂ���
			SH->bMoveFlag = true;
		}
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CNFade::Draw() {
	// ���ߏ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, nAlpha);
	// �`�揈��
	DrawGraphF(0, 0,
		SH->GHNFade,
		TRUE
	);
	//// ���߂��폜
	//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}


///*
//* @brief �����ς�����t�F�[�h
//*/
//CSFade::CSFade(int x, int y, int ID)
//	: CMover(SH -> SFadeList, 0, 0), X(x), Y(y), nID(ID)
//{
//}
//
//bool CSFade::Move() {
//
//	if (nID > CS->nAlphaID) {
//		return false;
//	}
//
//	return true;
//}
//
//void CSFade::Draw() {
//	// �`�揈��
//	// ������
//	DrawGraphF(FADE_SIZE_XY * X, FADE_SIZE_XY * Y,
//		SH->GHSFade,
//		TRUE
//	);
//
//}