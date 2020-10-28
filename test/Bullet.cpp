/*******************************************************************
* @file		Bullet.cpp
* @brief	�G�̃V���b�g�p.cpp
* @author	yshimada
* @data		20200106
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Bullet.h"
#include <math.h>


/*****************************************
* @brief �R���X�g���N�^
*****************************************/
CDirBullet::CDirBullet(float x, float y, float dir, float spd, float accel, int Def, int Atack)
	: CBullet(x, y, Def, Atack)
{
	// ���x
	vx = cosf(dir) * spd;
	vy = sinf(dir) * spd;

	// �����x
	AX = accel;
	AY = accel;
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CDirBullet::Move() {

	// ���W�̍X�V
	X += vx;
	Y += vy;

	//// ���x�̍X�V
	//vx += AX;
	//vy += AY;

	// �����蔻��
	//! �ǂł̔��˔���
	if (X < MinX && vx < 0) {
		vx = -vx;
		nDefCount--;
	}
	if (Y < MinY && vy < 0) {
		vy = -vy;
		nDefCount--;
	}
	if (X > MaxX && vx > 0) {
		vx = -vx;
		nDefCount--;
	}
	if (Y > MaxY && vy > 0) {
		vy = -vy;
		nDefCount--;
	}
	Count++;

	if (nDefCount <= 0)
		return false;


	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CDirBullet::Draw() {
	DrawGraphF(X - BULLET_CHIP_SIZE_HARF, Y - BULLET_CHIP_SIZE_HARF,
		SH->GHBullet[(Count / BULLET_ANIM_SPEED) % BULLET_PATTERN],
		TRUE
	);
}

