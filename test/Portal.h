/*******************************************************************
* @file		Portal.h
* @brief	�|�[�^���p.h(�摜�̖��O�̓����O�ɂ��܂���)
* @author	yshimada
* @data		20191217
*******************************************************************/

#pragma once

#include "Mover.h"

enum PortalPattern {
	REFPORTAL,
	NOTREFPORTAL,
	MAXNUM
};

class CPortal : public CMover
{
protected:
	int nCount;
	int nRotSpeed;
	double dRotdir;

public:
	int nChipNam;
	float dPortaldir;
	bool bSetPortal;
	//! true�Ńo���p�[
	bool bRefPortal;

	PortalPattern m_ePortal;

	CPortal(float x, float y, double dir);

	void* operator new(size_t t) {
		return operator_new(t, SH->PortalList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->PortalList);
	}

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();

	void CheckRefPortal();
	void SetHit();

};

class CSpownPortal {
public:
	CSpownPortal(int Num);

	static CPortal* New(float x, float y, float dir) { return new CPortal(x, y, dir); }

};