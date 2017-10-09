#include "stdafx.h"
#include "Staff.h"
#include <string.h>

CStaff::CStaff(void)//无参数构造函数
{
	strcpy(m_id,"");
	strcpy(m_password,"");
	strcpy(m_name,"");
	strcpy(m_bankname,"");
	m_nper = 0;
}
//有参构造函数
CStaff::CStaff(char id[] , char password[] , char name[] , char bankname[] , int nper)
{
	strcpy(m_id,id);
	strcpy(m_password,password);
	strcpy(m_name,name);
	strcpy(m_bankname,bankname);
	m_nper = nper;
}

CStaff::~CStaff(void)
{
}
void CStaff::Set_id(char s_id[21]) //设置帐号
{
	strcpy(m_id,s_id);
}
char * CStaff::Get_id()//获得帐号
{
	return m_id;
}

void CStaff::Set_password(char s_password[7])
{
	strcpy(m_password,s_password);

}
char * CStaff::Get_password()
{
	return m_password;
}

void CStaff::Set_name(char s_name[15])
{
	strcpy(m_name,s_name);

}
char * CStaff::Get_name()
{
	return m_name;
}

void CStaff::Set_bankname(char s_bankname[41])
{
	strcpy(m_bankname,s_bankname);
}
char * CStaff::Get_bankname()
{
	return m_bankname;
}

void CStaff::Set_nper(int s_nper)
{
	m_nper = s_nper;
}
int CStaff::Get_nper()
{
	return m_nper;
}