/*******************************************************************
* @file		Enemy04.h
* @brief	�G4�p.h
* @author	yshimada
* @data		20200107
*******************************************************************/

#pragma once

#include "Mover.h"

/****************
* @brief �G�`��֘A�N���X
****************/
class CEnemy04 : public CMover {

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
	CEnemy04(float x, float y, float r, int vit, int Atack, int score)
		: CMover(SH->Enemy04List, x, y, r), Vit(vit), nAtack(Atack), Score(score)
	{}


	void* operator new(size_t t) {
		return operator_new(t, SH->Enemy04List);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->Enemy04List);
	}

};

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define ZENEMY_ANIM_SPEED 5


//=============================================================
// �u���[�G�N���X
// ���Ԋu�őS�������˒e���΂��Ă���
//=============================================================
class CZakoEnemy4 : public CEnemy04 {
private:
	float fBulletSpeed;
	int nCount;

public:
	float rad;

	// �R���X�g���N�^
	CZakoEnemy4(float x, float y);


	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();

	static CEnemy04* New(float x, float y) { return new CZakoEnemy4(x, y); }
};