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

BOOL CCarddao:: Save(CCard * card)//将文件写入到“Card.txt”文件中
{
	BOOL flag = FALSE;
	char p_buf[256] = {'0'};
	//判断在Customer.txt中有没有该用户
	if (PanDuan(card->Get_id()))
	{

		//将对象的信息全部填充到数组中
		//将日期转化成字符填充
		char a_time[15] = {'0'};//
		strftime(a_time,sizeof(a_time),"%Y年%m月%d日",&(card->Get_createdate()));

		sprintf(p_buf,"%s##%s##%s##%lf##%s##%s",card->Get_id(),card->Get_kahao(),card->Get_password(),card->Get_money(),card->Get_bank(),a_time);		
		
		//打开文件
		ofstream outfile;
		outfile.open("Card.txt",ios::app);//以追加方式打开
		//写入文件
		char * p = p_buf;
		if(outfile.write(p,sizeof(p_buf)))
		{
			outfile.write("\n",1);
			flag = TRUE;
		}
		//清空缓存
		outfile.flush();

		//关闭文件
		outfile.close();
	}
	return flag;
}
BOOL CCarddao:: PanDuan(char * id)//判断该卡的用户名是否存在
{
	//打开文件
	ifstream fileinfo;
	fileinfo.open("Customer.txt",ios::in);
	if (!fileinfo)
	{
		return FALSE;
	}
	//读取文件



	BOOL flag = FALSE;

	char staffinfo [MAX_BUF] = {'0'};
	char p_customer[21] = {'0'};
	//fileinfo.getline(staffinfo,sizeof(staffinfo));
	
	while(!fileinfo.eof())//读取一整行)
	{
		//解析
		fileinfo.read(staffinfo,sizeof(staffinfo));//读取
		//p_customer = prasepcustomer(staffinfo);//将接收到的一个用户名，
		strcpy(name,prasepcustomer(staffinfo));//就将解析出来的姓名保存到成员变量
		//通过解析，获得一个姓名

		//将参数与解析出来的用户名和用户输入的进行匹配，
		if (strcmp(id,staffinfo)== 0)
		{
			flag = TRUE;
			//
			break;
		}
	}

	//关闭文件
	fileinfo.getline(staffinfo,sizeof(staffinfo));
	fileinfo.close();
	
	return flag;
}

char * CCarddao:: prasepcustomer(char * pstaffinfo)//以文件中的一行字符解析出其中的 用户名
{
	char * fengefu = "##";//分隔符
	static char pstr[21] = {'0'};//用户返回的
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