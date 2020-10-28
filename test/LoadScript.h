/*******************************************************************
* @file		LloadScript.h
* @brief	�}�b�v�����p.h
* @author	yshimada
* @data		20200109
*******************************************************************/

#pragma once

#include <vector>
#include <string>
#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Enemy.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "Portal.h"
#include "Bumper.h"

using namespace std;

/*
* @brief �R�}���h�N���X
*/
class CCommand {
public:
	// �������z��
	virtual void Run() = 0;

};

/*
* @brief �X�N���v�g�N���X
*/
class CLoadScript
{
	// �R�}���h��ێ�����z��
	vector<CCommand*> Command;

	// ���s�R�}���h�ԍ�
	int nCommandIndex;

public:
	// �R���X�g���N�^
	CLoadScript(string file);

	// ���s�J�n�A���s�̐ݒ�
	void Init();
	void Run();


};


// Blue�G�����p�֐��ւ̃|�C���^
typedef CEnemy* (*NEW_ENEMY_FUNC01)(float x, float y);

/*
* @brief Blue�G�����R�}���h�N���X
*/
class CEnemyCommand01 : public CCommand {

	NEW_ENEMY_FUNC01 Func;
	float X, Y;

public:
	CEnemyCommand01(NEW_ENEMY_FUNC01 func, float x, float y)
		: Func(func), X(x), Y(y)
	{}
	virtual void Run() { Func(X, Y); }

};

// Green�G�����p�֐��ւ̃|�C���^
typedef CEnemy02* (*NEW_ENEMY_FUNC02)(float x, float y);

/*
* @brief Green�G�����R�}���h�N���X
*/
class CEnemyCommand02 : public CCommand {

	NEW_ENEMY_FUNC02 Func;
	float X, Y;

public:
	CEnemyCommand02(NEW_ENEMY_FUNC02 func, float x, float y)
		: Func(func), X(x), Y(y)
	{}
	virtual void Run() { Func(X, Y); }

};

// Yellow�G�����p�֐��ւ̃|�C���^
typedef CEnemy03* (*NEW_ENEMY_FUNC03)(float x, float y);

/*
* @brief Yellow�G�����R�}���h�N���X
*/
class CEnemyCommand03 : public CCommand {

	NEW_ENEMY_FUNC03 Func;
	float X, Y;

public:
	CEnemyCommand03(NEW_ENEMY_FUNC03 func, float x, float y)
		: Func(func), X(x), Y(y)
	{}
	virtual void Run() { Func(X, Y); }

};

// Red�G�����p�֐��ւ̃|�C���^
typedef CEnemy04* (*NEW_ENEMY_FUNC04)(float x, float y);

/*
* @brief Red�G�����R�}���h�N���X
*/
class CEnemyCommand04 : public CCommand {

	NEW_ENEMY_FUNC04 Func;
	float X, Y;

public:
	CEnemyCommand04(NEW_ENEMY_FUNC04 func, float x, float y)
		: Func(func), X(x), Y(y)
	{}
	virtual void Run() { Func(X, Y); }

};

typedef CPortal* (*NEW_PORTAL_FUNC)(float x, float y, float dir);

class CPortalCommand :public CCommand {
	NEW_PORTAL_FUNC Func;
	float X, Y, DIR;

public:
	CPortalCommand(NEW_PORTAL_FUNC func, float x, float y, float dir)
		: Func(func), X(x), Y(y), DIR(dir)
	{}
	virtual void Run() { Func(X, Y, DIR); }

};

typedef CBumper* (*NEW_BUMPER_FUNC)(float x, float y, float rad);

class CBumperCommand :public CCommand {
	NEW_BUMPER_FUNC Func;
	float X, Y, RAD;

public:
	CBumperCommand(NEW_BUMPER_FUNC func, float x, float y, float rad)
		: Func(func), X(x), Y(y), RAD(rad)
	{}
	virtual void Run() { Func(X, Y, RAD); }

};