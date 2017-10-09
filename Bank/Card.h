#pragma once
class CCard
{
public:
	CCard(void);
	~CCard(void);
public:
	BOOL CunKuan(double c_money);//存款
	BOOL Qukuan(double c_money);//取款
	BOOL ZhuanZhang(CCard & m_card , double c_money);//转账

public:
	void Set_kahao(char s_kahao[21]);         
	void Set_password(char s_password[7]);    
	void Set_id(char s_id[21]);               
	void Set_bank(char s_bank[64]);  
	void Set_money(double s_money);
	void Set_createdate(tm * s_createdate);
	
	 char * Get_kahao();
	 char * Get_password();
	 char * Get_id();
	 char * Get_bank();
	 double Get_money();
	 tm Get_createdate();
private:
	char m_kahao[21];//卡号
	char m_password[7];//密码
	char m_id[21];//客户帐号
	char m_bank[64];//银行卡的所属银行
	tm m_createdate;//开卡日期
	double m_money;//金额

};

