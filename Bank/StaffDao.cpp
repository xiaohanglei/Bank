#include "stdafx.h"
#include "StaffDao.h"
#include <fstream>
using namespace std;
#define MAX_BUF 100

CStaffDao::CStaffDao(void)
{
	p_staff = NULL;
}


CStaffDao::~CStaffDao(void)
{
	delete p_staff;
}
BOOL CStaffDao::login(const char * l_id , const char * l_password)//��֤���й����û��������룡
{
	//���ļ�
	ifstream fileinfo;
	fileinfo.open("Staff.txt",ios::in);
	if (!fileinfo)
	{
		return FALSE;
	}
	//��ȡ�ļ�
	BOOL flag = FALSE;

	char staffinfo [MAX_BUF] = {'0'};
	p_staff = NULL;
	while(fileinfo.getline(staffinfo,sizeof(staffinfo)))//��ȡһ����)
	{
		//����
		p_staff = prasestaff(staffinfo);//�����յ���һ���ַ���
		//ͨ�����������һ�����й���Ա����

		//������������������û������������ƥ�䣬
		if (strcmp( p_staff->Get_id() , l_id) == 0 
			&& 
			strcmp(p_staff->Get_password(),l_password) == 0)
		{
			flag = TRUE;
			//
			break;
		}
	}

	//�ر��ļ�
	fileinfo.close();
	return flag;
}

CStaff * CStaffDao:: prasestaff(char * pstaffinfo)//����
{
	char a_staffinfo[5][MAX_BUF] = {'0'};
	int index = 0 ;//�����±�
	char * fengefu = "##";//�ָ���
	char * pbuf = NULL;
	char * pstr = NULL;

	CStaff * pStaff = NULL;//���ڷ������й���Ա��Ϣ����ָ��
	pStaff = new CStaff();//�Ӷ��Ϸ���һ������

	pbuf = pstaffinfo;

	while((pstr = strtok(pbuf,fengefu)) != NULL)
	{
		strcpy(a_staffinfo[index],pstr );
		index++;
		pbuf = NULL ;
	}

	pStaff->Set_id (a_staffinfo[0]);
	pStaff->Set_password (a_staffinfo[1]);
	pStaff->Set_name (a_staffinfo[2]);
	pStaff->Set_bankname (a_staffinfo[3]);
	int n_p = atoi(a_staffinfo[4]);
	pStaff->Set_nper (n_p);

	return pStaff;

}
char * CStaffDao::ret_name()//���ظ��Ѿ�ƥ�䵽�Ķ�����������ڴ��ݵ�������
{
	return p_staff->Get_name();
}