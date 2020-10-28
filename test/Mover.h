/*******************************************************************
* @file		Mover.h
* @brief	�����蔻��p.h
* @author	yshimada
* @data		20191215
*******************************************************************/

#pragma once
//-------------------------------------------------------------
#include "RemTask.h"
#include <math.h>

//=============================================================
// �ړ����̃N���X
// �ی^�����蔻��
//=============================================================
class CMover : public CRemTask {

public:
	// ���W
	float X, Y;

	// �����蔻��̔��a
	float R;
	// �����蔻���
	float W, H;

	//! �ۗp�R���X�g���N�^
	//! �R���X�g���N�^�i�����蔻����w�肷��j
	CMover(
		CRemTaskList* task_list,
		float x, float y, float r
	)
		: CRemTask(task_list), X(x), Y(y), R(r)
	{}
	//! �R���X�g���N�^�i�����蔻����w�肵�Ȃ��j
	CMover(CRemTaskList* task_list, float x, float y)
		: CRemTask(task_list), X(x), Y(y), R(0)
	{}

	//! �l�p�p�R���X�g���N�^
	//! �ʓ|�Ȃ̂Ŏw�肵�Ȃ����͍̂��Ȃ�
	CMover(
		CRemTaskList* task_list,
		float x, float y,
		float w, float h
	)
		: CRemTask(task_list), X(x), Y(y), W(w), H(h)
	{}


	// �ړ��A�`��
	virtual bool Move() { return true; }
	virtual void Draw() {}

	// �ǂ̔��菈���s�v�������ǈ�ɂ���ȏ�̓����蔻�肪��������̂Ŏg���
	bool Out(float size) {
		return (
			X < (0 - size) || X >(SCREEN_WIDTH + size) ||
			Y < (0 - size) || Y >(SCREEN_HEIGHT + size)
			);
	}

	//! �ۂ̓����蔻��
	bool CCHit(CMover* m) {
		return(powf(X - m->X, 2) + powf(Y - m->Y, 2) <= powf(R + m->R, 2));
	}
	//! ������WH�̎w�������ꍇ�i�傫�����ς�鎞�ɏ����ׂ��j

	//! �l�p�̓����蔻��
	// wh�w��
	bool CSHit(CMover* m, float w, float h) {
		return (
			(X - w) < (m->X + m->W) && (X + w) > (m->X - m->W) &&
			(Y - h) < (m->Y + m->H) && (Y + h) > (m->Y - m->H)
			);
	}
	//! ������WH�̎w�������,����Ώۂ���]���Ă�����̂����鎞
	bool CSHit(CMover* m, float fRad, float w, float h) {
		//! 90�x��]���Ă���ꍇ
		if (fRad == PI_HARF || fRad == -PI_HARF) {
			return (
				(X - w) < (m->X + m->H) && (X + w) > (m->X - m->H) &&
				(Y - h) < (m->Y + m->W) && (Y + h) > (m->Y - m->W)
				);
		}
		//! �ʏ�p�x
		else {
			return (
				(X - w) < (m->X + m->W) && (X + w) > (m->X - m->W) &&
				(Y - h) < (m->Y + m->H) && (Y + h) > (m->Y - m->H)
				);
		}
	}
};