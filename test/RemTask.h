/*******************************************************************
* @file		RemTask.h
* @brief	�^�X�N�V�X�e��.h
* @author	yshimada
* @data		20191215
*******************************************************************/

#pragma once
//-------------------------------------------------------------
//! class
class CRemTask;
class CRemTaskList;
class CRemTaskIter;

/*****************************************
* @brief	�^�X�N�N���X
*****************************************/
class CRemTask {
	friend CRemTaskList;
	friend CRemTaskIter;

	// �^�X�N���X�g�ւ̃|�C���^
	CRemTaskList* TaskList;

	// �O��̃^�X�N�ւ̃|�C���^
	CRemTask* Prev, * Next;

	// �^�X�N���X�g���w�肵�Ȃ�new, delete�𖳌��ɂ���
	void* operator new(size_t t) {}
	void operator delete(void* p) {}

protected:
	// new, delete�̏����F
	// �K�؂�new, delete���Z�q���T�u�N���X�Œ�`����
	static void* operator_new(size_t t, CRemTaskList* task_list);
	static void operator_delete(void* p, CRemTaskList* task_list);

public:
	CRemTask(CRemTaskList* task_list);
	virtual ~CRemTask();
};

/*****************************************
* @brief	�^�X�N���X�g�N���X
*****************************************/
class CRemTaskList {
	friend CRemTask;
	friend CRemTaskIter;

	// �A�N�e�B�u�^�X�N���X�g�A�t���[�^�X�N���X�g
	CRemTask* ActiveTask, * FreeTask;

	// �^�X�N�̍ő�T�C�Y�A�^�X�N�̍ő吔�A�t���[�^�X�N�̐�
	int MaxTaskSize, MaxNumTask, NumFreeTask;

public:
	// �R���X�g���N�^
	CRemTaskList(int max_task_size, int max_num_task);

	// �^�X�N�̐�
	int GetNumFreeTask() { return NumFreeTask; }
	int GetNumActiveTask() { return (MaxNumTask - NumFreeTask); }

	// �S�^�X�N�̏���
	void DeleteTask();
};

/*****************************************
* @brief	�^�X�N�C�e���[�^�[
*****************************************/
class CRemTaskIter {

protected:
	CRemTaskList* TaskList;
	CRemTask* Task;

public:
	// �R���X�g���N�^
	inline CRemTaskIter(CRemTaskList* task_list)
		: TaskList(task_list), Task(task_list->ActiveTask)
	{}

	// ���̗v�f������Ƃ�true
	inline bool HasNext() {
		return (Task->Next != TaskList->ActiveTask);
	}

	// ���̗v�f��Ԃ�
	inline CRemTask* Next() {
		return (Task = Task->Next);
	}

	// ���O�ɕԂ����v�f���폜����
	inline void Remove() {
		Task = Task->Prev;
		delete Task->Next;
	}
};