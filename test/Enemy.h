/*******************************************************************
* @file		Enemy.h
* @brief	�G�p.h
* @author	yshimada
* @data		20191221
*******************************************************************/

#pragma once

#include "Mover.h"

/****************
* @brief �G�`��֘A�N���X
****************/
class CEnemy : public CMover {

protected:
	// �^�C�}�[
	//int Time;

public:
	// �ϋv�́A�X�R�A
	int Vit;
	float Vx, Vy;
	int Score;
	int nAtack;
	bool NockBackFlag;

	// �R���X�g���N�^
	CEnemy(float x, float y, float r, int vit, int Atack, int score)
		: CMover(SH->Enemy01List, x, y, r), Vit(vit), nAtack(Atack), Score(score), NockBackFlag(false)
	{}

	void* operator new(size_t t) {
		return operator_new(t, SH->Enemy01List);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->Enemy01List);
	}

};

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define ZENEMY_ANIM_SPEED 5
#define SARTH_COUNT 20

//=============================================================
// �u���[�G�N���X
// �Ԃ����Ă���
// �m�b�N�o�b�N���ăf���[�g
//=============================================================
class CZakoEnemy1 : public CEnemy {
private:
	float vx, vy;
	float Speed;
	int Count;
	int nNocCount;
	float *V1, *V2, Valx, Valy;
	//! �Փˎ��ړ��p
	float fatanZ;
	//! �l��Ԃ�����
	float V3[2];
	float SV0, SV1, SV2;
	float UVal2;
	float kakuSA;
	float Vxs, Vys;

	void Ref(float Ex, float Ey);
	float *Disperse(float Pvx, float Pvy, float PVal);

public:
	float rad;

	// �R���X�g���N�^
	CZakoEnemy1(float x, float y);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();

	static CEnemy* New(float x, float y) { return new CZakoEnemy1(x, y); }
};
