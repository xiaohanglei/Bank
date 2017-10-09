#include "stdafx.h"
#include "Card.h"


CCard::CCard(void)
{
	strcpy(m_kahao,"");
	strcpy(m_password,"");
	strcpy(m_id,"");
	strcpy(m_bank,"");
	m_money = 0;
}
CCard::~CCard(void)
{
}

BOOL CCard:: CunKuan(double c_money)//存款
{
	m_money += c_money;
	return TRUE;
}
BOOL CCard:: Qukuan(double c_money)//取款
{
	if (c_money > m_money)
	{
		return FALSE;
	}
	else
	{
		m_money -= c_money;
		return TRUE;
	}
}
BOOL CCard:: ZhuanZhang(CCard & m_card , double c_money)//转账
{
	m_card.CunKuan(c_money);
	return TRUE;
}

void CCard:: Set_kahao(char s_kahao[21])     
{
	strcpy(m_kahao,s_kahao);
}
void CCard:: Set_password(char s_password[7]) 
{
	strcpy(m_password,s_password);
}
void CCard:: Set_id(char s_id[21]) 
{
	strcpy(m_id,s_id);
}
void CCard:: Set_bank(char s_bank[64]) 
{
	strcpy(m_bank,s_bank);
}
void CCard:: Set_money(double s_money) 
{
	m_money = s_money ;
}
void CCard:: Set_createdate(tm * s_createdate) 
{
	m_createdate = * s_createdate;
}
	
char * CCard:: Get_kahao() 
{
	return m_kahao;
}
char * CCard:: Get_password()
{
	return m_password;
}
char * CCard:: Get_id() 
{
	return m_id;
}
char * CCard:: Get_bank() 
{
	return m_bank;
}
double CCard:: Get_money() 
{
	return m_money;
}
tm CCard:: Get_createdate() 
{
	return m_createdate;
}
