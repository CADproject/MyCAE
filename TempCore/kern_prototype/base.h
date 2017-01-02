#pragma once
#include "headers.h"
#include "geometry.h"
using namespace std;

//���������� ������ ���� (������-���������)
//������� ����� ��� ���� ���������� ������
//(��, �������������� ��������, ��, ��������, ����������� � �.�.)

class genericObject
{
private:
	unsigned _layer;		//����� ���� ��������
	COLOR _color;			//���� ��������������� ��������
	THICKNESS _thickness;	//������� ��������������� ��������
	Geometry* _geometry;	//�������� ������

public:
	genericObject() {}
	genericObject(Geometry* geometry) { _geometry = geometry; }
	~genericObject() {}

	unsigned getLayer(void) { return _layer; }
	Geometry* getGeometry(void) { return _geometry; }

	void setColor(COLOR newColor) { _color = newColor; }
	void setThickness(THICKNESS newThickness) { _thickness = newThickness; }

	void show(void) { _geometry->show(); }
};

//������������� ���� ����� ����� ������ � �������
//����� ��� ���������� � ���������� ������������� ���������

class Buffer
{
private:
	vector<genericObject*> _buffer;		//���������� ������� ������
	vector<unsigned> _layers;			//������������ �� ������ ����
public:
	Buffer() { _layers.push_back(0); }
	~Buffer() {}

	void setLayers(vector<unsigned>& layersToShow) { _layers = layersToShow; }

	//���������� ������� (�� ��������)
	void update(vector<genericObject*>& uptodate);
	
	//���������� �� ����� � ����� �� �����
	void toScreen(void);
};

//���� ������ �������� �������������� ���� ������������ �� ������ ������ ��������

class Base
{
private:
	map<OBJID, genericObject*> _base;	//���� ������
	Buffer* _observer;					//��������� ����
public:
	Base() {}
	~Base() {}

	//������������ ����������
	void attachObserver(Buffer* observer) { _observer = observer; }

	//������������ ������ ����������� �������
	void attachToBase(pair<Geometry*, OBJID>& newPair);

	//��������� ������ �� ����
	void detachObject(OBJID id);

	//�������� ����
	void clearBase(void);
	
	//��������� ��������� �� ���������� ������ ����
	genericObject* getGenericObject(OBJID id);

	//�������� generic'�
	vector<genericObject*> getGenericObjects(void);

	//����������� ����������
	void notify(void);
};