/*******************************************************************
* @file		Player.h
* @brief	���@�p.h
* @author	yshimada
* @data		20191218
*******************************************************************/

#pragma once

#include "Mover.h"

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define PLAYER_ANIM_SPEED 5
#define PLAYER_SPEED 6

//#define MAX_SHOT_TIME 15

//! �`��֌W�N���X
class CPlayer :public CMover
{
private:
	//float fRad;
	int nSDownCount;
	float fSDown;

protected:

public:
	// �ړ������p
	float vx, vy;
	// �����x
	float Speed;
	// �X�s�[�h�A�b�v
	float faccel;

	// �R���X�g���N�^
	CPlayer(float x, float y, float dir);

	void* operator new(size_t t) {
		return operator_new(t, SH->PlayerList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->PlayerList);
	}

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

//=============================================================
// ���@�N���X�i�ʏ펞�j
// @brief	���˓��̏����Ŏg��
//=============================================================
class CNormalPlayer : public CPlayer
{
private:
	//! �v���C���[�A�G�̈ړ�����
	float PEVal, EPVal;
	//! ���˗p
	float *V1, *V2;
	//! �l��Ԃ�����
	float V3[4];
	float SV0, SV1, SV2;
	float UVal2;
	float kakuSA;
	float Vxs, Vys;
	float SteyVx, SteyVy;
	//! �Փˎ��ړ��p
	float fatanZ;
	// �|�[�^���G���A���A�_���[�W���󂯂�G���A���ɂ��邩�ǂ���
	//int nInPortal;
	// �����蔻��p true�������Ă��Ȃ��@false�������Ă���
	bool bHitportal;
	//! ���ˎ��̃X�s�[�h�����p
	float fUpS;
	int FlagCount;

	// ���x����p�֐�
	float *Disperse(float Pvx, float Pvy, float PVal);

public:
	// player�̍U���l
	int PlayerAP;

	// �R���X�g���N�^
	CNormalPlayer(float x, float y, float dir);

	// �ړ�
	virtual bool Move();
};