/*******************************************************************
* @file		Selector.h
* @brief	�V�[���Ǘ��p.h
* @author	yshimada
* @data		20191215
*******************************************************************/

#pragma once
//-------------------------------------------------------
#include "Mover.h"
//-------------------------------------------------------

//#define SCRIPT_LENGTH(array) (sizeof(*SH->Script) / sizeof(SH->Script[0]))

class CSelector : public CMover
{
public:
	// �X�e�[�W�ԍ�
	int nStageNum;

	//�@�R���X�g���N�^
	CSelector() : CMover(SH->SceneList, 0, 0), nStageNum(0) {}

	void* operator new(size_t t) {
		return operator_new(t, SH->SceneList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->SceneList);
	}

};

//-------------------------------------------------------------
// @brief �萔
//-------------------------------------------------------------
enum {
	MENU_FIRST,
	MENU_SECOND,
	MENU_MAX
};

//=============================================================
// @brief �^�C�g���̃N���X
//=============================================================
class CTitle : public CSelector {
private:
	int nCount;
	//bool bFade;
	// �N���b�N�������̔���
	bool bClick;

public:

	// �R���X�g���N�^
	CTitle();

	// �ړ��A�`��
	virtual bool Move();
	//virtual void Draw();
};

//=============================================================
//  @brief �X�e�[�W�N���X
//=============================================================

//�t�F�[�h�̔z��J�E���g�p
#define FADE_MAX 24

class CStage : public CSelector {

protected:
	// �^�C�}�[
	int Time;
	// �t�F�[�h�ɓ����Ă��邩�̔���
	int bFadeFlag;

public:
	// �R���X�g���N�^
	CStage(int Num);

	// �ړ��A�`��
	virtual bool Move();

	//// SFade�pID
	//int nAlphaID;

private:
	// SFade�p�z��
	int nFadeCount[FADE_MAX][FADE_MAX];
	// SFade�pIDNumber
	int nIDCount;

	// CreateSFade�֐�
	//void CreateSFade();
	//void FadeIn();
	//void FadeOut();

	CreateLine m_eLine;
};
extern CStage *CS;


//==============================================================
// @brief Stage�J�ڎ��̏����N���X
// Wait�̓^�X�N��񋤗L
//==============================================================
class CWait : public CMover {
private:
	// �X�e�[�W�ԍ��󂯎��p
	int nNum;
	// WaitTime
	int nCount;

public:
	// �R���X�g���N�^
	CWait(int Num);

	void* operator new(size_t t) {
		return operator_new(t, SH->WaitList);
	}
	void operator delete(void* p) {
		operator_delete(p, SH->WaitList);
	}

	// �ړ�����
	virtual bool Move();

};


//class CCG : CMover {
//public:
//	CCG() : CMover(SH->ClearOverList, 0, 0) {}
//
//	void* operator new(size_t t) {
//		return operator_new(t, SH->ClearOverList);
//	}
//	void operator delete(void* p) {
//		operator_delete(p, SH->ClearOverList);
//	}
//};

//=============================================================
//  @brief �Q�[���I�[�o�[�N���X
//=============================================================
class CGOver : public CSelector {
private:
	// �t�F�[�h�ɓ����Ă��邩�̔���
	int bFadeFlag;

public:
	// ���j���[���ڂ̑I���ʒu
	int MenuPos;

	// �R���X�g���N�^
	CGOver();

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};

//=============================================================
//  @brief �Q�[���N���A�N���X
//=============================================================
class CGCreal : public CSelector {
private:
	// �t�F�[�h�ɓ����Ă��邩�̔���
	int bFadeFlag;

public:
	// ���j���[���ڂ̑I���ʒu
	int MenuPos;

	// �R���X�g���N�^
	CGCreal();

	// �ړ��A�`��
	virtual bool Move();
	virtual void Draw();
};