/*******************************************************************
* @file		Enemy02.h
* @brief	�G2�p.h
* @author	yshimada
* @data		20200107
*******************************************************************/

#pragma once

#include "Mover.h"

/****************
* @brief �G�`��֘A�N���X
****************/
class CEnemy02 : public CMover {

protected:
	// �^�C�}�[
	//int Time;

public:
	// �ϋv�́A�X�R�A
	int Vit;
	float Vx, Vy;
	int Score;
	int nAtack;

	// �R���X�g���N�^
	CEnemy02(float x, float y, float r, int vit, int Atack, int score)
		: CMover(SH->Enemy02List, x, y, r), Vit(vit), nAtack(Atack), Score(score)
	{}


	void* operator new(size_t t) {
		return operator_new(t, SH->Enemy02List);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->Enemy02List);
	}

};

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define ZENEMY_ANIM_SPEED 5

//=============================================================
// �u���[�G�N���X
// ������x�̃X�s�[�h�̋����˂���đł��Ă��钵�˕Ԃ�Ȃ�
//=============================================================
class CZakoEnemy2 : public CEnemy02 {
private:
	float fBulletSpeed;
	int nCount;

public:
	// �e�p�x
	float rad;

	// �R���X�g���N�^
	CZakoEnemy2(float x, float y);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();

	static CEnemy02* New(float x, float y) { return new CZakoEnemy2(x, y); }
};