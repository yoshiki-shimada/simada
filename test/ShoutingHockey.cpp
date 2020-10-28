/*******************************************************************
* @file		SH.cpp
* @brief	MainClass.cpp
* @author	yshimada
* @data		20191215
*******************************************************************/

#include "DxLib.h"
#include "ShoutingHockey.h"
#include "Selector.h"
#include "TitleText.h"
#include "BG.h"
#include "Bumper.h"
#include "Portal.h"
#include "Player.h"
#include "Enemy.h"
#include "Enemy02.h"
#include "Enemy03.h"
#include "Enemy04.h"
#include "Bullet.h"
#include "UI.h"
#include "NextArrow.h"
#include "Effect.h"
#include "Fade.h"
#include "LoadScript.h"


CShoutingHockey *SH;

/*
* @brief �R���X�g���N�^
*/
CShoutingHockey::CShoutingHockey() : ECount(0), Count(1), bMoveFlag(false), TitleMenuPos(MENU_FIRST)
{
	SetGraphMode(SCREEN_WIDTH_ANDUI, SCREEN_HEIGHT, SCREEN_COLOR);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	// �^�X�N���X�g�̏�����
	SceneList = new CRemTaskList(sizeof(CStage), 100);
	TTextList = new CRemTaskList(sizeof(CTitleText), 10);
	WaitList = new CRemTaskList(sizeof(CWait), 10);
	BGList = new CRemTaskList(sizeof(CBGStage1), 10);
	BumperList = new CRemTaskList(sizeof(CBumper), 10);
	PortalList = new CRemTaskList(sizeof(CPortal), 100);
	Enemy01List = new CRemTaskList(sizeof(CZakoEnemy1), 100);
	Enemy02List = new CRemTaskList(sizeof(CZakoEnemy2), 100);
	Enemy03List = new CRemTaskList(sizeof(CZakoEnemy3), 100);
	Enemy04List = new CRemTaskList(sizeof(CZakoEnemy4), 100);
	BulletList = new CRemTaskList(sizeof(CDirBullet), 100);
	PlayerList = new CRemTaskList(sizeof(CNormalPlayer), 100);
	EffectList = new CRemTaskList(sizeof(CPlayerCrash), 10);
	UiList = new CRemTaskList(sizeof(CUI), 10);
	ArrowList = new CRemTaskList(sizeof(CNextArrow), 10);
	NFadeList = new CRemTaskList(sizeof(CNFade), 10);
	//SFadeList = new CRemTaskList(sizeof(CSFade), 100);
	//ClearOverList = new CRemTaskList(sizeof(CCG), 10);


	// �O���t�B�b�N�n���h���̏�����
	//! �^�C�g��
	LoadDivGraph(TITLEBG, 1,
		1, 1,
		TITLE_SIZE_X, TITLE_SIZE_Y,
		&GHTitle
	);
	//! text01
	LoadDivGraph(TITLE_TEXT01, 1,
		1, 1,
		TEXT01_SIZE_X, TEXT01_SIZE_Y,
		&GHText01
	);
	//! text01
	LoadDivGraph(TITLE_TEXT02, 1,
		1, 1,
		TEXT02_SIZE_X, TEXT02_SIZE_Y,
		&GHText02
	);
	LoadDivGraph(TITLE_YAJI, 1,
		1, 1,
		YAJI_SIZE_X, YAJI_SIZE_Y,
		&GHYaji
	);
	//------------------------------------------------------
	//! �X�e�[�W�̏�
	LoadDivGraph(BGSTAGEFLOOR, BG_PATTERN,
		BG_PATTERN, 1,
		BGSTAGE1_SIZE_X, BGSTAGE1_SIZE_Y,
		GHStageFloor
	);
	//! �o���p�[
	LoadDivGraph(BUMPER, BUMPER_PATTERN,
		BUMPER_PATTERN, 1,
		BUMPER_SIZE_X, BUMPER_SIZE_Y,
		GHBumper
	);
	//! �|�[�^��
	LoadDivGraph(PORTAL, PORTAL_PATTERN,
		PORTAL_PATTERN_X, PORTAL_PATTERN_Y,
		PORTAL_SIZE, PORTAL_SIZE,
		GHPortal
	);
	//! �v���C���[
	LoadDivGraph(PLAYER_CHIP, PLAYER_PATTERN,
		PLAYER_PATTERN, 1,
		PLAYER_SIZE, PLAYER_SIZE,
		GHPlayer
	);
	//! �G�l�~�[01
	LoadDivGraph(ZENEMY_CHIP01, ZENEMY_PATTERN,
		ZENEMY_PATTERN, 1,
		ZENEMY_CHIP_SIZE_X, ZENEMY_CHIP_SIZE_Y,
		GHZEnemy01
	);
	//! �G�l�~�[02
	LoadDivGraph(ZENEMY_CHIP02, ZENEMY_PATTERN,
		ZENEMY_PATTERN, 1,
		ZENEMY_CHIP_SIZE_X, ZENEMY_CHIP_SIZE_Y,
		GHZEnemy02
	);
	//! �G�l�~�[03
	LoadDivGraph(ZENEMY_CHIP03, ZENEMY_PATTERN,
		ZENEMY_PATTERN, 1,
		ZENEMY_CHIP_SIZE_X, ZENEMY_CHIP_SIZE_Y,
		GHZEnemy03
	);
	//! �G�l�~�[04
	LoadDivGraph(ZENEMY_CHIP04, ZENEMY_PATTERN,
		ZENEMY_PATTERN, 1,
		ZENEMY_CHIP_SIZE_X, ZENEMY_CHIP_SIZE_Y,
		GHZEnemy04
	);
	//! Bullet
	LoadDivGraph(BULLET_CHIP, BULLET_PATTERN,
		BULLET_PATTERN, 1,
		BULLET_CHIP_SIZE_X, BULLET_CHIP_SIZE_Y,
		GHBullet
	);
	//! Metar
	LoadDivGraph(METAR_CHIP, METAR_PATTERN,
		METAR_PATTERN, 1,
		METAR_CHIP_SIZE_X, METAR_CHIP_SIZE_Y,
		GHMetar
	);
	LoadDivGraph(ARROW_CHIP, ARROW_PATTERN,
		ARROW_PATTERN, 1,
		ARROW_SIZE_X, ARROW_SIZE_Y,
		GHArrow
	);
	LoadDivGraph(PCRASH_CHIP, PCRASH_PATTERN,
		PCRASH_PATTERN, 1,
		PCRASH_CHIP_SIZE, PCRASH_CHIP_SIZE,
		GHPCrash
	);
	LoadDivGraph(ECRASH_CHIP, ECRASH_PATTERN,
		ECRASH_PATTERN, 1,
		ECRASH_CHIP_SIZE, ECRASH_CHIP_SIZE,
		GHECrash
	);
	LoadDivGraph(PORTAL_EFFECT_CHIP, PORTAL_EFFECT_PATTERN,
		PORTAL_EFFECT_PATTERN, 1,
		PORTAL_EFFECT_SIZE, PORTAL_EFFECT_SIZE,
		GHPortalEffect
	);
	//RuleText
	LoadDivGraph(RULE, 1,
		1, 1,
		RULE_SIZE, RULE_SIZE,
		&GHRule
	);

	//! �N���A
	//! �^�C�g��
	LoadDivGraph(CLEARBG, 1,
		1, 1,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		&GHClearBG
	);
	//! �^�C�g��
	LoadDivGraph(CLEAR_ROGO, 1,
		1, 1,
		CLEAR_ROGO_SIZE_X, CLEAR_ROGO_SIZE_Y,
		&GHClearRogo
	);

	LoadDivGraph(OVER_BG, 1,
		1, 1,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		&GHOverBG
	);

	//! �m�[�}���t�F�[�h
	LoadDivGraph(FADEBG, 1,
		1, 1,
		FADE_SIZE_X, FADE_SIZE_Y,
		&GHNFade
	);
	//! �X�y�V�����t�F�[�h
	LoadDivGraph(FADEBG, 1,
		1, 1,
		FADE_SIZE_XY, FADE_SIZE_XY,
		&GHSFade
	);

	//! �T�E���h�n���h���̏�����
	SHCrash = LoadSoundMem(CRASH_SE);
	SHClick = LoadSoundMem(CLICK_SE);
	SHRef = LoadSoundMem(REF_SE);
	SHShot = LoadSoundMem(SHOT_SE);
	SHSDown = LoadSoundMem(SDOWN_SE);
	SHBullet = LoadSoundMem(BULLET_SE);
	SHDamage = LoadSoundMem(DAMAGE_SE);
	SHLeverUP = LoadSoundMem(UP_SE);
	SHNextStage = LoadSoundMem(NEXTSTAGE_SE);

	// �X�N���v�g
	//Script[0] = new CLoadScript("Res\\StagePromoScript.txt");
	Script[0] = new CLoadScript("res\\Stage01Script.txt");
	Script[1] = new CLoadScript("res\\Stage02Script.txt");
	Script[2] = new CLoadScript("res\\Stage03Script.txt");
	Script[3] = new CLoadScript("res\\Stage04Script.txt");
	Script[4] = new CLoadScript("res\\Stage05Script.txt");

}

//! �f�X�g���N�^
CShoutingHockey::~CShoutingHockey()
{
	DxLib_End();
}

void CShoutingHockey::Run() {
	while (!ProcessMessage()) {
		ClearDrawScreen();

		//! �L�[�̓��͎��ԏ���
		char cTmpKey[256];
		GetHitKeyStateAll(cTmpKey);
		for (int i = 0; i < 256; i++) {
			if (cTmpKey[i] != 0) {
				Key[i]++;
			}
			else {
				Key[i] = 0;
			}
		}

		// �Q�[���I��
		if (Key[KEY_INPUT_ESCAPE])
			break;

		// �|�[�Y
		if (Key[KEY_INPUT_P] == 1)
			Pause = !Pause;

		SH->Move();
		SH->Draw();

		ScreenFlip();
	}
}

/***************************************************************
* @brief �ړ�
***************************************************************/
void CShoutingHockey::Move() {
	if (Pause)
		return;

	MoveTask(SceneList);
	MoveTask(TTextList);
	MoveTask(WaitList);
	MoveTask(BGList);
	//MoveTask(ArrowList);
	if (!bMoveFlag) {
		MoveTask(BumperList);
		MoveTask(PortalList);
		MoveTask(BulletList);
		MoveTask(PlayerList);
		MoveTask(Enemy01List);
		MoveTask(Enemy02List);
		MoveTask(Enemy03List);
		MoveTask(Enemy04List);
	}
	//MoveTask(ClearOverList);
	MoveTask(EffectList);
	MoveTask(NFadeList);
	//MoveTask(SFadeList);
}

/***************************************************************
* @brief �`��
***************************************************************/
void CShoutingHockey::Draw() {
	DrawTask(SceneList);
	DrawTask(TTextList);
	DrawTask(BGList);
	DrawTask(ArrowList);
	DrawTask(BumperList);
	DrawTask(PortalList);
	DrawTask(BulletList);
	DrawTask(PlayerList);
	DrawTask(Enemy01List);
	DrawTask(Enemy02List);
	DrawTask(Enemy03List);
	DrawTask(Enemy04List);
	DrawTask(UiList);
	//DrawTask(ClearOverList);
	DrawTask(EffectList);
	DrawTask(NFadeList);
	//DrawTask(SFadeList);
}

/****************************************************************
* @brief �^�X�N�̓���
*****************************************************************/
void CShoutingHockey::MoveTask(CRemTaskList* list) {
	for (CRemTaskIter i(list); i.HasNext(); ) {
		CMover* mover = (CMover*)i.Next();
		if (!mover->Move()) i.Remove();
	}
}


/****************************************************************
* �^�X�N�̕`��
*****************************************************************/
void CShoutingHockey::DrawTask(CRemTaskList* list) {
	for (CRemTaskIter i(list); i.HasNext(); ) {
		((CMover*)i.Next())->Draw();
	}
}

/*************************************************************
* ���C�����[�`��
*************************************************************/
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
	// ���C���N���X��new
	SH = new CShoutingHockey();
	// �^�C�g���N���X��new
	new CTitle();
	//! �Q�[���̎��s
	SH->Run();

	delete SH;
	return 0;
}