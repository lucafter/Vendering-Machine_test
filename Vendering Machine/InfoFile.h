#pragma once

#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include <afx.h>

#define _F_LOGIN "./login.ini"
#define _F_STOCK "./stock.txt"
#define _F_FEEDBACK "./feedback.txt"


using namespace std;

struct msg
{
	int id;			//��Ʒid
	string name;	//��Ʒ��
	int price;		//��Ʒ�۸�
	int num;		//��Ʒ����
};

class CInfoFile
{
public:
	CInfoFile();
	~CInfoFile();

	//��ȡ��¼��Ϣ
	void ReadLogin(CString &pwd);

	//�޸�����
	void WritePwd(char* pwd);

	//��ȡ��Ʒ����
	void ReadDocline();

	//��Ʒд���ļ�
	void WriteDocline();

	//�������Ʒ
	void Addline(CString name, int num, int price);

	list<msg> ls;	//�洢��Ʒ����
	int num;			//������¼��Ʒ����
};


