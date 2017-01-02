#pragma once
#include "headers.h"
#include "model_tree.h"
#include "base.h"
#include "undo_redo.h"
using namespace std;

//�������� ���������� ����������
//�������� � ���� ����������, ������� ������� � ����

class Document
{
private:
	static DOCID _id;		//������������� ��������� (��� ������� ������)
	ModelTree _tree;		//��������� ������ ������
	Buffer _buffer;			//��������� ������� ��� ������ �� �����
	UndoRedo _undoredo;		//������ undo/redo

public:
	Document() { _tree.getBase().attachObserver(&_buffer); }
	~Document() {}

	//API ��������� ����

	void addNodeToModelTree(ConnectData& source, FEATID featureID);

	void selectLayers(vector<unsigned>& layersToShow);

	void changeThickness(OBJID id, THICKNESS newThickness);

	void changeColor(OBJID id, COLOR newColor);

	void undo(void);

	void redo(void);

	void changeCacheUndoRedo(unsigned cache);

	PointStruct getPointCoords(OBJID id);
};