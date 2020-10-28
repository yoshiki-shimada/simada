/*******************************************************************
* @file		Effect.h
* @brief	�G�t�F�N�g.h
* @author	yshimada
* @data		20200107
*******************************************************************/

#pragma once
//-------------------------------------------------------------
#include "Mover.h"

//=============================================================
// �G�t�F�N�g�N���X
//=============================================================
class CEffect : public CMover {

public:
	// �R���X�g���N�^
	CEffect(float x, float y)
		: CMover(SH->EffectList, x, y)
	{}

	void* operator new(size_t t) {
		return operator_new(t, SH->EffectList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->EffectList);
	}
};

//-------------------------------------------------------------
// �萔
//-------------------------------------------------------------
#define CRASH_ANIM_SPEED 5

//=============================================================
// �����N���X�i���@�j
//=============================================================
class CPlayerCrash : public CEffect {

protected:
	// �^�C�}�[
	int Time;
	int Count;

public:
	// �R���X�g���N�^
	CPlayerCrash(float x, float y);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

//=============================================================
// �����N���X�i�G�j
//=============================================================
class CEnemyCrash : public CEffect {

protected:
	// �^�C�}�[
	int Time;
	int Count;

public:
	// �R���X�g���N�^
	CEnemyCrash(float x, float y);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

//=============================================================
// �|�[�^���ω��N���X
//=============================================================
class CPortalEffect : public CEffect {

protected:
	// �^�C�}�[
	int Time;
	int Count;

public:
	// �R���X�g���N�^
	CPortalEffect(float x, float y);

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};