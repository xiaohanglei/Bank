#include "stdafx.h"
#include "Customer.h"


CCustomer::CCustomer(void)
{
	strcpy(m_id,"");
	strcpy(m_name,"");
	m_sex = 0;
	strcpy(m_num,"");
	strcpy(m_tel,"");
}


CCustomer::~CCustomer(void)
{
}
void CCustomer:: Set_id(char s_id[21]) //
{
	strcpy(m_id,s_id);

}
void CCustomer:: Set_name(char s_name[15]) //
{
	strcpy(m_name,s_name);
}
void CCustomer:: Set_sex(int s_sex) //
{
	m_sex = s_sex;
}
void CCustomer:: Set_num(char s_num[19]) //
{
	strcpy(m_num,s_num);
}
void CCustomer:: Set_tel(char s_tel[12]) //
{
	strcpy(m_tel,s_tel);
}

void CCustomer:: Set_address(char s_address[128])
{
	strcpy(m_address,s_address) ;
}
	
void CCustomer::Set_dat(tm * s_data)
{
	m_creatdata = * s_data;
}
	
tm CCustomer:: Get_data()
{
	return m_creatdata;
}

char * CCustomer:: Get_address()
{
	return m_address;
}

char * CCustomer:: Get_id() 
{
	return m_id;
}
char * CCustomer:: Get_name() 
{
	return m_name;
}
int CCustomer:: Get_sex() 
{
	return m_sex;
}
char * CCustomer:: Get_num() 
{
	return m_num;
}
char * CCustomer:: Get_tel() 
{
	return m_tel;
}