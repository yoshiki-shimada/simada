/*******************************************************************
* @file		Bumper.h
* @brief	�o���p�[�p.h
* @author	yshimada
* @data		20191222
*******************************************************************/

#pragma once
//--------------------------------------------------------------
#include "Mover.h"


#define BUMPER_POS 45
#define BUMPER_HARF_X BUMPER_SIZE_X * 0.5
#define BUMPER_HARF_Y BUMPER_SIZE_Y * 0.5
#define BUMPER_ANIM_SPEED 6

/*************************************************
* @brief �X�e�[�W�N���X
*************************************************/
class CBumper : public CMover
{
private:
	int nCount;

public:
	float fRad;

	CBumper(float x, float y,float dir);

	void* operator new(size_t t) {
		return operator_new(t, SH->BumperList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->BumperList);
	}

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

class CSpownBumper
{
public:
	CSpownBumper(int Num);

	static CBumper* New(float x, float y, float dir) { return new CBumper(x, y, dir); }
};