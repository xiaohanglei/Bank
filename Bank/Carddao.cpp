#include "stdafx.h"
#include "Carddao.h"
#include <fstream>
using namespace std;
#define MAX_BUF 200


CCarddao::CCarddao(void)
{

}

CCarddao::~CCarddao(void)
{
}

BOOL CCarddao:: Save(CCard * card)//���ļ�д�뵽��Card.txt���ļ���
{
	BOOL flag = FALSE;
	char p_buf[256] = {'0'};
	//�ж���Customer.txt����û�и��û�
	if (PanDuan(card->Get_id()))
	{

		//���������Ϣȫ����䵽������
		//������ת�����ַ����
		char a_time[15] = {'0'};//
		strftime(a_time,sizeof(a_time),"%Y��%m��%d��",&(card->Get_createdate()));

		sprintf(p_buf,"%s##%s##%s##%lf##%s##%s",card->Get_id(),card->Get_kahao(),card->Get_password(),card->Get_money(),card->Get_bank(),a_time);		
		
		//���ļ�
		ofstream outfile;
		outfile.open("Card.txt",ios::app);//��׷�ӷ�ʽ��
		//д���ļ�
		char * p = p_buf;
		if(outfile.write(p,sizeof(p_buf)))
		{
			outfile.write("\n",1);
			flag = TRUE;
		}
		//��ջ���
		outfile.flush();

		//�ر��ļ�
		outfile.close();
	}
	return flag;
}
BOOL CCarddao:: PanDuan(char * id)//�жϸÿ����û����Ƿ����
{
	//���ļ�
	ifstream fileinfo;
	fileinfo.open("Customer.txt",ios::in);
	if (!fileinfo)
	{
		return FALSE;
	}
	//��ȡ�ļ�



	BOOL flag = FALSE;

	char staffinfo [MAX_BUF] = {'0'};
	char p_customer[21] = {'0'};
	//fileinfo.getline(staffinfo,sizeof(staffinfo));
	
	while(!fileinfo.eof())//��ȡһ����)
	{
		//����
		fileinfo.read(staffinfo,sizeof(staffinfo));//��ȡ
		//p_customer = prasepcustomer(staffinfo);//�����յ���һ���û�����
		strcpy(name,prasepcustomer(staffinfo));//�ͽ������������������浽��Ա����
		//ͨ�����������һ������

		//������������������û������û�����Ľ���ƥ�䣬
		if (strcmp(id,staffinfo)== 0)
		{
			flag = TRUE;
			//
			break;
		}
	}

	//�ر��ļ�
	fileinfo.getline(staffinfo,sizeof(staffinfo));
	fileinfo.close();
	
	return flag;
}

char * CCarddao:: prasepcustomer(char * pstaffinfo)//���ļ��е�һ���ַ����������е� �û���
{
	char * fengefu = "##";//�ָ���
	static char pstr[21] = {'0'};//�û����ص�
	static char p_name[15] = {'0'};
	strcpy(pstr,strtok(pstaffinfo,fengefu));
	pstaffinfo = NULL;
	strcpy(p_name,strtok(pstaffinfo,fengefu));
	return p_name;
}

char * CCarddao:: Get_name()
{
	return name;
}