/******************************************************************
* @file		Enemy.cpp
* @brief	�G�p.cpp
* @author	yshimada
* @data		20191221
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Enemy.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "Bullet.h"
#include "Player.h"
#include "Effect.h"
#include <math.h>


/*****************************************
* @brief Enemy01�R���X�g���N�^
*****************************************/
CZakoEnemy1::CZakoEnemy1(float x, float y)
	: CEnemy(x, y, ZENEMY_CHIP_HARF_Y, 1, 1, 100), Count(0), vx(0), vy(0), rad(0), Speed(1), nNocCount(0)
{
	SH->ECount++;
}

/*****************************************
* @brief �ړ�
*****************************************/
bool CZakoEnemy1::Move() {
	// �ړ��͈�
	static const int MinX = RLWALL_AND_PLAYER, MaxX = SCREEN_WIDTH - MinX;
	static const int MinY = TBWALL_AND_PLAYER, MaxY = SCREEN_WIDTH - MinY;

	if (Count % SARTH_COUNT == 0 && !NockBackFlag) {
		CRemTaskIter i(SH->PlayerList);
		CPlayer *player = (CPlayer*)i.Next();
		rad = atan2(player->Y - Y, player->X - X);
		vx = cosf(rad) * Speed;
		vy = sinf(rad) * Speed;
		Vx = vx;
		Vy = vy;
	}


	if (NockBackFlag) {
		switch (nNocCount) {
		case 0:
			vx = Vx;
			vy = Vy;
			break;
		case 100:
			NockBackFlag = !NockBackFlag;
			nNocCount = -1;
			break;
		}
		nNocCount++;
	}

	X += vx;
	Y += vy;

	//! �ǂł̔��˔���
	if (X < MinX && vx < 0)
		vx = -vx;
	if (Y < MinY && vy < 0)
		vy = -vy;
	if (X > MaxX && vx > 0)
		vx = -vx;
	if (Y > MaxY && vy > 0)
		vy = -vy;

	Count++;

	//! �A��
	for (CRemTaskIter i(SH->Enemy02List); i.HasNext();) {
		CZakoEnemy2 *Enemy02 = (CZakoEnemy2*)i.Next();
		//! ����������
		if (CCHit(Enemy02) && NockBackFlag) {
			Enemy02->Vit -= nAtack;

			Ref(Enemy02->X, Enemy02->Y);
		}
	}
	for (CRemTaskIter i(SH->Enemy03List); i.HasNext();) {
		CZakoEnemy3 *Enemy03 = (CZakoEnemy3*)i.Next();
		//! ����������
		if (CCHit(Enemy03) && NockBackFlag) {
			Enemy03->Vit -= nAtack;

			Ref(Enemy03->X, Enemy03->Y);
		}
	}
	for (CRemTaskIter i(SH->Enemy04List); i.HasNext();) {
		CZakoEnemy4 *Enemy04 = (CZakoEnemy4*)i.Next();
		//! ����������
		if (CCHit(Enemy04) && NockBackFlag) {
			Enemy04->Vit -= nAtack;

			Ref(Enemy04->X, Enemy04->Y);
		}
	}

	//! ����
	if (Vit <= 0 && !NockBackFlag) {
		PlaySoundMem(SH->SHCrash, DX_PLAYTYPE_BACK);
		new CEnemyCrash(X, Y);
		SH->ECount--;
		//! �Q�[���N���A����
		if (SH->ECount <= 0) {
			SH->m_eStagePhase = NextStage;
		}
		return false;
	}

	return true;
}

/*****************************************
* @brief �`��
*****************************************/
void CZakoEnemy1::Draw() {
	DrawGraphF(X - ZENEMY_CHIP_HARF_X, Y - ZENEMY_CHIP_HARF_Y,
		SH->GHZEnemy01[(Count / ZENEMY_ANIM_SPEED) % ZENEMY_PATTERN],
		TRUE
	);
}

/**
* @brief	�A�������ˑ��x�ύX�֐�
* @param	[in]	Ex,Ey ����̃|�W�V����
*/
void CZakoEnemy1::Ref(float Ex, float Ey)
{
	Valx = atan2(Ey - Y, Ex - X);
	Valy = atan2(Y - Ey, X - Ex);
	V1 = Disperse(vx, vy, Valx);
	V2 = Disperse(0, 0, Valy);

	//! �s��v�Z
	vx = *V1 + *(V2 + 2);
	vy = *(V1 + 1) + *(V2 + 3);

	// �X�s�[�h�������グ��
	float fUpS = atan2(vy, vx);
	vx = cosf(fUpS) * Speed;
	vy = sinf(fUpS) * Speed;

	//! �����蔻��̂Ȃ��Ƃ���܂Ńv���C���[���ړ�
	fatanZ = atan2(Y - Ey, X - Ex);
	X = (2 * PLAYER_SIZE_HARF + 20) * cos(fatanZ) + Ex;
	Y = (2 * PLAYER_SIZE_HARF + 20) * sin(fatanZ) + Ey;
}


/**
* @brief	�A�����p���x����
* @param	[in]	Uxs,Uys x,y�����̑��x	UVal1 �����ՓˑO�i�s����
* @return	����x,y ����x,y �̔z���Ԃ�
*/
float *CZakoEnemy1::Disperse(float Uxs, float Uys, float UVal1)
{
	SV0 = sqrt(Uxs * Uxs + Uys * Uys);//���x(x���x��y���x�̍����u�Ίp���̒����v�j
	UVal2 = atan2(Uys, Uxs);//�����i�s����
	kakuSA = UVal2 - UVal1;//�u�Փˌ㑊�苅�̐i�s�����v�ɑ΂���u�����ՓˑO�i�s�����v�̊p�x�̍�
	SV1 = fabs(SV0 * cos(kakuSA));//�Փˌ�̑��苅�̑��x
	SV2 = fabs(SV0 * sin(kakuSA));//�Փˌ�̎����̑��x
	Vxs = SV1 * cos(UVal1);//�Փˌ�̑��苅��x���x
	Vys = SV1 * sin(UVal1);//�Փˌ�̑��苅��y���x

	if (sin(kakuSA) < 0) {
		Uxs = SV2 * cos(UVal1 - PI / 2);//�Փˌ�̎�����x���x
		Uys = SV2 * sin(UVal1 - PI / 2);//�Փˌ�̎�����y���x
	}
	else {
		Uxs = SV2 * cos(UVal1 + PI / 2);//�Փˌ�̎�����x���x
		Uys = SV2 * sin(UVal1 + PI / 2);//�Փˌ�̎�����y���x
	}

	V3[0] = Uxs;
	V3[1] = Uys;
	V3[2] = Vxs;
	V3[3] = Vys;

	return V3;//�o�́F�Փˌ�̎�����x���x�Ay���x�A���苅��x���x�Ay���x
}