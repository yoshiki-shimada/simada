/*******************************************************************
* @file		RemTask.cpp
* @brief	�^�X�N�V�X�e��.cpp
* @author	yshimada
* @data		20191215
*******************************************************************/

#include "RemTask.h"
#include <stdio.h>
#include <assert.h>

/*****************************************
* @brief	�^�X�N�̐����Anew�̏���������
* @param	[in]	t �^�X�N�T�C�Y	Task_list �^�X�N���X�g��
* @return	�^�X�N�̏�Ԃ�Ԃ�
*****************************************/
void* CRemTask::operator_new(size_t t, CRemTaskList* task_list) {

	// �N���X�T�C�Y���ő�T�C�Y�𒴂�����G���[
	assert(t <= (size_t)task_list->MaxTaskSize);

	// �t���[�^�X�N���Ȃ��Ƃ���NULL��Ԃ�
	if (task_list->NumFreeTask <= 0) return NULL;

	// �t���[�^�X�N��1���o��
	CRemTask* task = task_list->FreeTask->Next;
	task_list->FreeTask->Next = task->Next;
	task_list->NumFreeTask--;

	// �R���X�g���N�^��
	return task;
}

/*****************************************
* @brief	�^�X�N�R���X�g���N�^
*****************************************/
CRemTask::CRemTask(CRemTaskList* task_list)
	: TaskList(task_list)
{
	// �^�X�N���A�N�e�B�u�^�X�N���X�g�ɑ}������
	Prev = task_list->ActiveTask->Prev;
	Next = task_list->ActiveTask;
	Prev->Next = Next->Prev = this;
}

/*****************************************
* @brief	�f�X�g���N�^
*****************************************/
CRemTask::~CRemTask() {
	// �^�X�N���A�N�e�B�u�^�X�N���X�g����폜����
	Prev->Next = Next;
	Next->Prev = Prev;
}

/*****************************************
* @brief	�f���[�g����
*****************************************/
void CRemTask::operator_delete(void* p, CRemTaskList* task_list) {
	// �^�X�N
	CRemTask* task = (CRemTask*)p;

	// �^�X�N���t���[�^�X�N���X�g�ɑ}������
	task->Next = task_list->FreeTask->Next;
	task_list->FreeTask->Next = task;
	task_list->NumFreeTask++;

	// �t���[�^�X�N�����ő�^�X�N���𒴂�����G���[
	// �idelete�̏d���Ăяo���Ȃǁj
	assert(task_list->NumFreeTask <= task_list->MaxNumTask);
}

/*****************************************
* @brief	������
*****************************************/
CRemTaskList::CRemTaskList(int max_size, int max_num)
	: MaxTaskSize(max_size), MaxNumTask(max_num), NumFreeTask(max_num)
{
	// �^�X�N�������p�̃}�N��
	#define TASK(INDEX)		((CRemTask*)(buf + max_size * (INDEX)))

	// �^�X�N�p�������̊m��
	char* buf = new char[max_size * (max_num + 2)];

	// �A�N�e�B�u�^�X�N���X�g�̏�����
	ActiveTask = TASK(0);
	ActiveTask->Prev = ActiveTask->Next = ActiveTask;

	// �t���[�^�X�N���X�g�̏�����
	FreeTask = TASK(1);
	for (int i = 1; i < max_num + 1; i++) {
		TASK(i)->Next = TASK(i + 1);
	}
	TASK(max_num + 1)->Next = FreeTask;
}

/*****************************************
* @brief	�S�^�X�N�̍폜
*****************************************/
void CRemTaskList::DeleteTask() {
	for (CRemTaskIter i(this); i.HasNext(); i.Next(), i.Remove());
}