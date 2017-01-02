#pragma once
#include "headers.h"
#include "model_tree.h"
using namespace std;

//��������� undo/redo ������ ������� ��������� N ������ � ������� ����������
//� ������� ����� ������ ����� ������� ������� �� ���� ������ (� ������������ ��������������)
//��� �� ��������� ������ ������ (������������)

class UndoRedo
{
private:
	deque<Node*> _container;	//��� undo/redo
	size_t _size;				//������ ���� undo/redo
	size_t _counter;			//������� ��������� � ����

public:
	UndoRedo() { _size = 10; _counter = 0; }
	~UndoRedo() {}

	//temp
	ModelTree* getMyTree(void) { return new ModelTree(); }
	//temp
	Base* getMyBase(void) { return new Base(); }

	//������ ������ ����
	void setSize(size_t newSize) { _size = newSize; }

	//������ � ���
	void addEvent(Node* newNode);

	//����� ��������
	void undo(void);

	//�������������� ��������
	void redo(void);
	
	//������� ����
	void clear(void);
};