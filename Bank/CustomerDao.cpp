#include "stdafx.h"
#include "CustomerDao.h"
#include <fstream>
#define COSTOMER_BUF 200
using namespace std;


CCustomerDao::CCustomerDao(void)
{
}


CCustomerDao::~CCustomerDao(void)
{
}
BOOL CCustomerDao:: Save(CCustomer * Cus)//�ļ���д��
{
	char t_buf[COSTOMER_BUF] = {'0'};//���ڴ洢�ö����������Ϣ��һ�У�

	BOOL flag = FALSE;
	char * c_id = Cus->Get_id();//��ȡ�����ʺ�
	char * c_name = Cus->Get_name();//��ȡ��������
	int c_sex = Cus->Get_sex();//��ȡ�����Ա�
	char * c_shenfen = Cus->Get_num();//��ȡ�������֤
	char * c_tel = Cus->Get_tel();//��ȡ����绰
	char * c_address = Cus->Get_address();//��ȡ�����ַ
		
	//��ȡ���������

	char a_time[15] = {'0'};//
	strftime(a_time,sizeof(a_time),"%Y��%m��%d��",&(Cus->Get_data()));


	sprintf(t_buf,"%s##%s##%d##%s##%s##%s##%s",c_id,c_name,c_sex,c_shenfen,c_tel,c_address,a_time);
	char * p = t_buf;

	//���ļ�
	ofstream outfile ;
	outfile.open("Customer.txt",ios::app);//��׷�ӷ�ʽ��
	//д���ļ�
	if (outfile.write(t_buf,sizeof(t_buf)))
	{
		outfile.write("\r\n",2);
		flag = TRUE;
	}

	//��ջ���
	outfile.flush();
	//�ر��ļ�
	outfile.close();
	return flag;
}