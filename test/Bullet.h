/*******************************************************************
* @file		Bullet.h
* @brief	�G�̃V���b�g�p.h
* @author	yshimada
* @data		20200106
*******************************************************************/

#pragma once
//-------------------------------------------------------------
#include "Mover.h"

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define BULLET_ANIM_SPEED 5


//=============================================================
// �e�N���X
//=============================================================
class CBullet : public CMover {
protected:
	// �ړ��͈�
	static const int MinX = RLWALL_AND_PLAYER, MaxX = SCREEN_WIDTH - MinX;
	static const int MinY = TBWALL_AND_PLAYER, MaxY = SCREEN_WIDTH - MinY;

public:
	int Count;
	int nDefCount;
	int nAtack;

	// �R���X�g���N�^
	CBullet(float x, float y, int Def, int Atack)
		: CMover(SH->BulletList, x, y, BULLET_CHIP_SIZE_HARF), Count(0), nDefCount(Def), nAtack(Atack) {};

	void* operator new(size_t t) {
		return operator_new(t, SH->BulletList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->BulletList);
	}

};

//=============================================================
// �ʏ�e�N���X
//=============================================================
class CDirBullet : public CBullet {
private:
	//// �ǔ͈�
	//static const int MinX = RLWALL_AND_PLAYER, MaxX = SCREEN_WIDTH - MinX;
	//static const int MinY = TBWALL_AND_PLAYER, MaxY = SCREEN_WIDTH - MinY;

public:
	// ���x�A�����x
	float vx, vy, AX, AY;

	// �R���X�g���N�^
	CDirBullet(float x, float y, float dir, float spd, float accel, int Def, int Atack);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

//=============================================================
// �z�[�~���O�e�N���X
//=============================================================
class CHoomBullet : public CBullet
{
private:
	float vx, vy;
	int Timer;
	float rad;

public:
	CHoomBullet(float x, float y, float dir, float spd, int Def, int Atack);

};