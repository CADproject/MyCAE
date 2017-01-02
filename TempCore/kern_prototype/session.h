#pragma once
#include "headers.h"
#include "document.h"
using namespace std;

//������ ������ Session ���������� � ������������ ����������
//��� �������� ������ - �������������� ��������� (Document) � ������ ������
//������ �� ����� ���������� � ����������� �� ��������������

class Session
{
private:
	static unsigned counter;
	map<DOCID, Document*> _session;
	
public:
	Session() {}
	~Session() {}

	//���������������� �������� � ������� ������
	DOCID registerDocument(Document* pdoc)
	{
		counter++;
		_session[counter] = pdoc;
		return counter;
	}

	//������� �������� �� ������� ������
	void removeDocument(DOCID doc) { _session.erase(doc); }

	//�������� �������� �� ��������������
	Document* getDocument(DOCID doc)
	{
		auto iter = _session.find(doc);

		if(iter == _session.end())
			return nullptr;
		else
			return iter->second;
	}
};