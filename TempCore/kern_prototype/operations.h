#pragma once
#include "headers.h"
#include "session.h"
#include "connect_data.h"
using namespace std;

//�������� ��������
//�������� ������� �� ��� ����: 
//	1) ������� ������� � ������� ������, ��� ��� ����������� �������� undo/redo
//		a) ���������������
//		�) ��������� �� ������ �������� (�� ����� ��� ����������)
//	2) ������� �� ������� � ������ ������
//		�) ������� undo/redo
//		�) ������� �������������� ������ ������
//		�) ��������� �������

class Operation
{
public:
	//���������� ������ � �����������
	virtual void operator()(Session& curSes, DOCID doc) = 0;

	//�������� �������������� ������ ��� ���������� � ����
	void messageToKern(Session& curSes, DOCID doc, ConnectData& source, FEATID featureID)
	{
		curSes.getDocument(doc)->addNodeToModelTree(source, featureID);
	}
};

//������ ��� ��������

//�������� �����
class createPointOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������� �����
class createLineOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������� ����������
class createCircleOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������� ����
class createArcOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������� ���������
class createPolyLineOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������������� �����
class setLinePointOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//�������� ��������� ��������� ���������� (�������� �����)
class createMeshOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//������� �����������
class createSupportOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//������� ��������
class createLoadOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//������ ��� ��������

//��������� ���������� ����� ����� �������
class measureDistanceOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//��������� ������� ��������������� ���������
class changeThicknessOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//��������� ����� ��������������� ���������
class changeColorOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};

//����� �����
class undoOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc) { curSes.getDocument(doc)->undo(); }
};

//������ ��������� ��������
class redoOperation: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc) { curSes.getDocument(doc)->redo(); }
};

//��������� ���� undo/redo
class changeCacheUndoRedo: public Operation
{
	public:
	void operator()(Session& curSes, DOCID doc);
};

//����� ����/����� ��� �����������
class selectLayers: public Operation
{
public:
	void operator()(Session& curSes, DOCID doc);
};