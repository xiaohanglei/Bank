#pragma once
#include "Card.h"
class CCarddao
{
public:
	CCarddao(void);
	~CCarddao(void);

	BOOL PanDuan(char * id);//�жϸÿ����û����Ƿ����
	BOOL Save(CCard * card);//���ļ�д�뵽��Card.txt���ļ���
	char * prasepcustomer(char * pstaffinfo);//���ļ��е�һ���ַ����������е� �û���
	char * Get_name();

private:
	char name[21];//���ڱ�������
};

