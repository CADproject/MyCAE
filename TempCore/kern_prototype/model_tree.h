#pragma once
#include "headers.h"
#include "base.h"
#include "features.h"
#include "connect_data.h"
using namespace std;

//���� ������ ������
//�� �������� ������ ����� �������������� ������� ����

class Node
{
private:
	ConnectData _source;		//�������� ������ ��� ����
	FEATID _featureId;			//������������� ����
	ConnectData _result;		//��������� ������ ����
	vector<Node*> _parents;		//������, �� ����� ���� �����
	vector<Node*> _children;	//�������

public:
	Node() { _featureId = ABSTRUCT_FEATURE; }

	Node(const ConnectData& source, FEATID featureId, const ConnectData& result)
	{
		_source = source;
		_featureId = featureId;
		_result = result;
	}
	
	~Node() {}

	//���������� �������� ����� 
	void AddChildren(Node* pNode) { _children.push_back(pNode); }
	
	//������ � ������ �������� �����
	vector<Node*> getChildren(void) { return _children; }

	//���������� ������ �������
	vector<Node*> getParents(void) { return _parents; }

	//���������� id ����������� ����
	vector<OBJID> getResultIDs(void) { return _result.getIDs(); }
	
	Feature* createFeature(void);

	//������ ���� ����������� ����
	//���� ���������� false, �� �������� � ���� ����������� ���� ��������
	bool runFeature(Base& base);
};

//��������� ������ ������			//base ���������� �������� �� ModelTree!!

class ModelTree
{
private:
	static unsigned _counter;	//������� OBJID (��� ���������� �����)
	Base _base;					//���� ������
	Node* _root;				//������ ������ ������
public:
	ModelTree() { _root = new Node(); }
	~ModelTree() {}

	//temp
	Base getBase(void) { return _base; }

	//���������� ������ (��� ���������)
	void runTree(Node* pNode);

	//���������� ����
	void addNode(ConnectData& source, FEATID featureID);

	//�������� ���� (� ��� ���������, ���� ����)
	void deleteNode(Node* pNode);

	//����� ���� �� ����������� ���� � ������ (���������)
	Node* searchNode(Node* startNode, OBJID id);

	//����������� ����� ����������� ������
	void showTree(void)
	{
		//todo
	}
};