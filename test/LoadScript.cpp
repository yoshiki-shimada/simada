/*******************************************************************
* @file		LloadScript.cpp
* @brief	�}�b�v�����p.cpp
* @author	yshimada
* @data		20200109
*******************************************************************/

#include "LoadScript.h"

/**
* @brief �G�̎�ށA���O
*/
const static char* ENEMY_NAME[] = {
	"ZEnemy01","ZEnemy02","ZEnemy03","ZEnemy04"
};
//const static char* ENEMY_NAME02[] = {
//	"ZEnemy02"
//};
//const static char* ENEMY_NAME03[] = {
//	"ZEnemy03"
//};
//const static char* ENEMY_NAME04[] = {
//	"ZEnemy04"
//};

//const static char* PORTAL_NAME = {
//   "NPortal"/*,"RPortal"*/
//};

/**
* @brief new�֐�
*/
const static NEW_ENEMY_FUNC01 ENEMY_FUNC01 = {
	CZakoEnemy1::New
};
const static NEW_ENEMY_FUNC02 ENEMY_FUNC02 = {
	CZakoEnemy2::New
};
const static NEW_ENEMY_FUNC03 ENEMY_FUNC03 = {
	CZakoEnemy3::New
};
const static NEW_ENEMY_FUNC04 ENEMY_FUNC04 = {
	CZakoEnemy4::New
};

const static NEW_PORTAL_FUNC PORTAL_FUNC = {
	CSpownPortal::New
};

const static NEW_BUMPER_FUNC BUMPER_FUNC = {
	CSpownBumper::New
};

/*
* @brief	�����̃|�W�V�������`�F�b�N
* @param	[in]	s chara�^�z��	pattern �󔒂��ǂ���
* @return	�󔒂̃|�W�V������Ԃ�	������Ȃ��Ƃ���Non position
*/
int Find(string s, string pattern) {
	for (int i = 0, n = s.length(), pl = pattern.length(); i < n; i++) {
		if (s.compare(i, pl, pattern) == 0) return i;
		// �}���`�o�C�g�������ǂ������`�F�b�N
		if (isleadbyte(s[i])) i++;
	}
	// ������Ȃ��Ƃ��̃|�W�V����(Non position)
	return string::npos;
}

/*
* @brief	�w��ʒu����̕�����擾
* @param	[in]	s chara�^�z��	index �����ڂ̕�����	separator �󔒂��ǂ���
* @return	�������Ԃ�
*/
string GetToken(string s, int index, string separator) {
	int sl = separator.length();
	for (int i = 0; i < index; i++) {
		int pos = Find(s, separator);
		if (pos == string::npos) return "";
		// �w�肳�ꂽ�ʒu����w�肳�ꂽ�����܂ł̕�������擾����
		s = s.substr(pos + sl);
	}

	return s.substr(0, Find(s, separator));
}

/*
* @brief	Script�̃��[�h
* @param	[in]	file Script�t�@�C��
*/
CLoadScript::CLoadScript(string file)
	: nCommandIndex(0)
{
	int nFileHandle;
	char String[256] = "";

	bool comment = false;

	// �t�@�C�����J��
	nFileHandle = FileRead_open(file.c_str());

	// �t�@�C���̏I�[������܂ŕ\������
	while (FileRead_eof(nFileHandle) == 0)
	{
		// ��s�ǂݍ���
		FileRead_gets(String, 256, nFileHandle);

		string command = GetToken(String, 0, " "),
			param0 = GetToken(String, 1, " "),
			param1 = GetToken(String, 2, " "),
			param2 = GetToken(String, 3, " "),
			param3 = GetToken(String, 4, " ");

		if (command == "*/") comment = false;
		else if (command == "/*") comment = true;

		if (comment) continue;

		if (command == "enemy") {
			for (int i = 0, in = sizeof(ENEMY_NAME) / sizeof(char*); i < in; i++) {
				if (param0 == ENEMY_NAME[i]) {
					switch (i)
					{
					case 0:
						Command.push_back(new CEnemyCommand01(ENEMY_FUNC01, stof(param1), stof(param2)));
						break;
					case 1:
						Command.push_back(new CEnemyCommand02(ENEMY_FUNC02, stof(param1), stof(param2)));
						break;
					case 2:
						Command.push_back(new CEnemyCommand03(ENEMY_FUNC03, stof(param1), stof(param2)));
						break;
					case 3:
						Command.push_back(new CEnemyCommand04(ENEMY_FUNC04, stof(param1), stof(param2)));
						break;
					}
					//Command.push_back(new CEnemyCommand01(ENEMY_FUNC01, stof(param1), stof(param2)));
				}
			}
			/*for (int i = 0, in = sizeof(ENEMY_NAME02) / sizeof(char*); i < in; i++) {
				if (param0 == ENEMY_NAME02[i]) {
					Command.push_back(new CEnemyCommand02(ENEMY_FUNC02, stof(param1), stof(param2)));
				}
			}
			for (int i = 0, in = sizeof(ENEMY_NAME03) / sizeof(char*); i < in; i++) {
				if (param0 == ENEMY_NAME03[i]) {
					Command.push_back(new CEnemyCommand03(ENEMY_FUNC03, stof(param1), stof(param2)));
				}
			}
			for (int i = 0, in = sizeof(ENEMY_NAME04) / sizeof(char*); i < in; i++) {
				if (param0 == ENEMY_NAME04[i]) {
					Command.push_back(new CEnemyCommand04(ENEMY_FUNC04, stof(param1), stof(param2)));
				}
			}*/
		}
		else if (command == "portal") {
			Command.push_back(new CPortalCommand(PORTAL_FUNC, stof(param0), stof(param1), stof(param2)));
		}
		/*else if (command == "bumper") {
			Command.push_back(new CBumperCommand(BUMPER_FUNC, stof(param0), stof(param1), stof(param2)));
		}*/
	}
}

/*
* @brief	���s�J�n
*/
void CLoadScript::Init() {
	nCommandIndex = 0;
}

/*
* @brief	���s�ݒ�
*/
void CLoadScript::Run() {
	while (nCommandIndex < (int)Command.size()) {
		Command[nCommandIndex]->Run();
		nCommandIndex++;
	}
}