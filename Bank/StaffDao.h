#pragma once
#include "Staff.h"
class CStaffDao
{
public:
	CStaffDao(void);
	~CStaffDao(void);

public:
	BOOL login(const char * l_id , const char * l_password);//��֤���й����û��������룡
	
	char * ret_name();//���ظ��Ѿ�ƥ�䵽�Ķ�����������ڴ��ݵ�������
private:
	CStaff * p_staff;
	CStaff * prasestaff(char * pstaffinfo);//����

};

