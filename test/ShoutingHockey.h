/*******************************************************************
* @file		SH.h
* @brief	Mainclass.h
* @author	yshimada
* @data		20191215
*******************************************************************/

#pragma once

#include "RemTask.h"

class CLoadScript;

//! �X�N���[���T�C�Y
#define SCREEN_WIDTH	864
#define SCREEN_HEIGHT	864
//! �X�N���[���̉����͍���������݂���̂ł����������
#define SCREEN_WIDTH_ANDUI	1158
//! �ꉞ�F
#define SCREEN_COLOR	32

//! �΂߈ړ��̂��߂̕ϊ��v�Z���l
#define PI        3.14159265f
#define PI_HARF	  PI * 0.5f
#define RadToDeg  57.29577951f
#define DegToRad  0.017453293f

//! �t�F�[�h���o�p
#define FADEBG "res\\BlackBox.png"
#define FADE_SIZE_X 1920
#define FADE_SIZE_Y 1080
#define FADE_SIZE_XY 36

//------------------------�^�C�g�����----------------------
//! �^�C�g��	864x864
#define TITLEBG	"res\\TitleBG.png"
#define TITLE_SIZE_X  864
#define TITLE_SIZE_Y  864

//! Text,yaji
#define TITLE_TEXT01 "res\\START.png"
#define TITLE_TEXT02 "res\\EXIT.png"
#define TEXT_POS_Y_0 550
#define TEXT_POS_Y_1 700
#define TEXT01_SIZE_X 396
#define TEXT01_SIZE_Y 119
#define TEXT02_SIZE_X 293
#define TEXT02_SIZE_Y 116
#define TEXT_HARFHARF_Y 28.5

#define TITLE_YAJI "res\\yaji.png"
#define YAJI_SIZE_X 59
#define YAJI_SIZE_Y 67


//------------------------�Q�[�����--------------------------

//! �Q�[���w�i	908x864
//! ���T�C�h�݂̂͂����摜�T�C�Y�@22
enum BGPhase {
	Run,
	End
};

#define BGSTAGEFLOOR	"res\\Game_BG_Chip.png"
#define BGSTAGE1_SIZE_X  864
#define BGSTAGE1_SIZE_Y  864
#define RLWALL_AND_PLAYER 56
#define TBWALL_AND_PLAYER 55
#define BG_PATTERN 3

//! Arrow
#define ARROW_CHIP "res\\arrow.png"
#define ARROW_SIZE_X 93
#define ARROW_SIZE_Y 96
#define ARROW_SIZE_HARF 48
#define ARROW_PATTERN 3

//! �o���p�[	230x13
#define BUMPER	"res\\Bumper.png"
#define BUMPER_SIZE_X  246
#define BUMPER_SIZE_Y  36
#define BUMPER_PATTERN 3

//! �v���C���[
#define PLAYER_CHIP	"res\\Player.png"
#define PLAYER_PATTERN 5
#define PLAYER_SIZE 55
#define PLAYER_SIZE_HARF 27.5

//! �����O
#define PORTAL "res\\PortalChip.png"
#define PORTAL_SIZE 136
#define PORTAL_SIZE_HARF 68
// �����蔻��p
#define PORTAL_SIZE_HARFCOLLI 50
#define PORTAL_PATTERN 10
#define PORTAL_PATTERN_X 5
#define PORTAL_PATTERN_Y 2

//! �G�l�~�[
#define ZENEMY_CHIP01	"res\\ZEnemy1.png"
#define ZENEMY_CHIP02	"res\\ZEnemy2.png"
#define ZENEMY_CHIP03	"res\\ZEnemy3.png"
#define ZENEMY_CHIP04	"res\\ZEnemy4.png"
#define ZENEMY_PATTERN 4
#define ZENEMY_CHIP_SIZE_X 53
#define ZENEMY_CHIP_SIZE_Y 65
#define ZENEMY_CHIP_HARF_Y 32.5
#define ZENEMY_CHIP_HARF_X 26.5

//! �o���b�g
#define BULLET_CHIP	"res\\Bullet.png"
#define BULLET_PATTERN 8
#define BULLET_CHIP_SIZE_X 8
#define BULLET_CHIP_SIZE_Y 8
#define BULLET_CHIP_SIZE_HARF 4
#define BULLET_SE "Res\\SE_Bullet.wav"

//! ���[�^�[UI
#define METAR_CHIP "res\\MeterChip.png"
#define METAR_PATTERN 5
#define METAR_CHIP_SIZE_X 199
#define METAR_CHIP_SIZE_Y 253

//! ���[���e�L�X�gUI
#define RULE "res\\Rule.png"
#define RULE_SIZE 294


//! �G�t�F�N�g
#define ECRASH_CHIP	"Res\\ZEnemyExpl.png"
#define ECRASH_PATTERN 6
#define ECRASH_CHIP_SIZE 64
#define PCRASH_CHIP	"Res\\CharaEffect.png"
#define PCRASH_PATTERN 5
#define PCRASH_CHIP_SIZE 72
#define PORTAL_EFFECT_CHIP "Res\\RingEffect.png"
#define PORTAL_EFFECT_PATTERN 7
#define PORTAL_EFFECT_SIZE 72


//-----------------------�N���A���----------------------------
#define CLEARBG "res\\ClearBG.png"

#define CLEAR_ROGO "res\\ClearRogo.png"
#define CLEAR_ROGO_SIZE_X 782
#define CLEAR_ROGO_SIZE_Y 114

#define CLEAR_CHARA "res\\CharaRot.png"

//-----------------------�Q�[���I�[�o�[���---------------------
#define OVER_BG "res\\GameOverBG.png"

//-----------------------�\����---------------------------------
enum FadePhase {
	FADEIN = 0,
	FADEOUT = 1
};

enum CreateLine {
	TOP,
	RIGHT,
	BOTTOM,
	LEFT
};

enum StagePhase {
	RunStage,
	GameOver,
	NextStage,
	StageClear,
	GameClear
};

//--------------------------�T�E���h-----------------------
//! BGM
#define TITLEBG_SE ("res\\STitleBG.mp3")
#define STAGE_SE ("res\\SStageBG.mp3")
#define OVER_SE ("res\\SGameOverBG.mp3")
#define CLEAR_SE ("res\\SClearBG.mp3")

//! SE
#define SHOT_SE ("res\\SShot.wav")
#define BULLET_SE ("res\\SBullet.wav")
#define REF_SE ("res\\SRef.wav")
#define DAMAGE_SE ("res\\SDamage.wav")
#define UP_SE ("res\\SPowerup.wav")
#define NEXTSTAGE_SE ("res\\SNextStage.wav")
#define CLICK_SE ("res\\SClick.wav")
#define CRASH_SE ("res\\SCrash.wav")
#define SDOWN_SE ("res\\SSpeedDown.wav")

/*
* @brief MainClass
*/
class CShoutingHockey
{
public:
	//! �G�̐��𐔂��邽��
	int ECount;
	//! �v���C���[�̃��x��
	//! Move���̊֌W�ł����ɒ�`���܂��B
	int Count;
	//! �L�[���͂���Ă���t���[�����L�^����
	int Key[256] = { 0 };
	//! �ꎞ��~
	bool Pause = false;
	//! �X�e�[�W��̓������~�߂�
	// false�œ���
	bool bMoveFlag;
	//! �^�C��
	int time = 0;
	//! fade���I���������̔���p
	bool bSceneFlag;
	// �X�e�[�W�ړ����̔w�i�p
	BGPhase m_ePhase;
	// ���j���[���ڂ̑I���ʒu
	int TitleMenuPos;

	StagePhase m_eStagePhase;

	//! �O���t�B�b�N�n���h��
	int GHTitle = 0;
	int GHText01 = 0;
	int GHText02 = 0;
	int GHYaji = 0;
	int GHNFade = 0;
	int GHSFade = 0;
	int GHStageFloor[BG_PATTERN] = { 0 };
	int GHBumper[BUMPER_PATTERN] = { 0 };
	int GHPlayer[PLAYER_PATTERN] = { 0 };
	int GHZEnemy01[ZENEMY_PATTERN] = { 0 };
	int GHZEnemy02[ZENEMY_PATTERN] = { 0 };
	int GHZEnemy03[ZENEMY_PATTERN] = { 0 };
	int GHZEnemy04[ZENEMY_PATTERN] = { 0 };
	int GHBullet[BULLET_PATTERN] = { 0 };
	int GHPortal[PORTAL_PATTERN] = { 0 };
	int GHMetar[METAR_PATTERN] = { 0 };
	int GHArrow[ARROW_PATTERN] = { 0 };
	int GHPCrash[PCRASH_PATTERN] = { 0 };
	int GHECrash[ECRASH_PATTERN] = { 0 };
	int GHRule = 0;
	int GHPortalEffect[PORTAL_EFFECT_PATTERN] = { 0 };
	int GHClearBG = 0;
	int GHClearRogo = 0;
	int GHOverBG = 0;

	//! �T�E���h�n���h�� BG�ȊO
	int SHClick;
	int SHCrash;
	int SHRef;
	int SHShot;
	int SHBullet;
	int SHDamage;
	int SHLeverUP;
	int SHNextStage;
	int SHSDown;

	//�@�R���X�g���N�^
	CShoutingHockey();
	//�@�f�X�g���N�^
	~CShoutingHockey();

	//! Run
	void Run();

	//! �ړ�
	virtual void Move();
	//! �`��
	virtual void Draw();

	//! �^�X�N���X�g
	CRemTaskList *SceneList, *WaitList, *NFadeList, /**SFadeList,*/ *BGList,
		*BumperList, *PlayerList, *Enemy01List, *Enemy02List,
		*Enemy03List, *Enemy04List, *BulletList, *PortalList, *UiList,
		*TTextList, *EffectList, *ArrowList/*, *ClearOverList*/;
	void MoveTask(CRemTaskList* list);
	void DrawTask(CRemTaskList* list);

	// �X�N���v�g
	CLoadScript* Script[];
};

extern CShoutingHockey* SH;