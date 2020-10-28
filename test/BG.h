/*******************************************************************
* @file		BG.h
* @brief	�X�e�[�W�w�i.h
* @author	yshimada
* @data		20191216
*******************************************************************/

#pragma once
//--------------------------------------------------------------
#include "Mover.h"

/*************************************************
* @brief �X�e�[�W�N���X
*************************************************/
class CBGStage1 : public CMover
{
private:
	int BGChipNum;

protected:

public:
	CBGStage1(int ChipNum) : CMover(SH->BGList, 0, 0), BGChipNum(ChipNum) {}

	void* operator new(size_t t) {
		return operator_new(t, SH->BGList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->BGList);
	}

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};