/*******************************************************************
* @file		NextArrow.h
* @brief	���̃X�e�[�W�ɍs�����߂̖��p.h
* @author	yshimada
* @data		20200109
*******************************************************************/

#pragma once

#include "Mover.h"

#define ARROW_ANIM_SPEED 6

class CNextArrow : public CMover
{
private:
	int ChipNum;

public:
	//! x,y,w,h�͓����蔻��p��
	CNextArrow() : CMover(SH->ArrowList, SCREEN_WIDTH * 0.5, 0, ARROW_SIZE_HARF, ARROW_SIZE_HARF), ChipNum(0) {}

	void* operator new(size_t t) {
		return operator_new(t, SH->ArrowList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->ArrowList);
	}

	// �ړ��A�`��
	//virtual bool Move();
	virtual void Draw();
};

