#pragma once
#include "Card.h"
class CCarddao
{
public:
	CCarddao(void);
	~CCarddao(void);

	BOOL PanDuan(char * id);//判断该卡的用户名是否存在
	BOOL Save(CCard * card);//将文件写入到“Card.txt”文件中
	char * prasepcustomer(char * pstaffinfo);//以文件中的一行字符解析出其中的 用户名
	char * Get_name();

private:
	char name[21];//用于保存名字
};

