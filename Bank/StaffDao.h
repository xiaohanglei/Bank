#pragma once
#include "Staff.h"
class CStaffDao
{
public:
	CStaffDao(void);
	~CStaffDao(void);

public:
	BOOL login(const char * l_id , const char * l_password);//验证银行管理用户名和密码！
	
	char * ret_name();//返回该已经匹配到的对象的名称用于传递到界面上
private:
	CStaff * p_staff;
	CStaff * prasestaff(char * pstaffinfo);//解析

};

