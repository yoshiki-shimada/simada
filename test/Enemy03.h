/*******************************************************************
* @file		Enemy03.h
* @brief	�G3�p.h
* @author	yshimada
* @data		20200107
*******************************************************************/

#pragma once

#include "Mover.h"

/****************
* @brief �G�`��֘A�N���X
****************/
class CEnemy03 : public CMover {

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
	CEnemy03(float x, float y, float r, int vit, int Atack, int score)
		: CMover(SH->Enemy03List, x, y, r), Vit(vit), nAtack(Atack), Score(score)
	{}

	void* operator new(size_t t) {
		return operator_new(t, SH->Enemy03List);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->Enemy03List);
	}


};

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define ZENEMY_ANIM_SPEED 5

//=============================================================
// �u���[�G�N���X
// �X�s�[�h�̂��鋅�����Ԋu�ő_���đł��Ă���A�^���N�Ɠ����悤�Ɉ�x���˕Ԃ鋅
//=============================================================
class CZakoEnemy3 : public CEnemy03 {
private:
	float fBulletSpeed;
	int nCount;

public:
	float rad;

	// �R���X�g���N�^
	CZakoEnemy3(float x, float y);


	
	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();

	static CEnemy03* New(float x, float y) { return new CZakoEnemy3(x, y); }
};

