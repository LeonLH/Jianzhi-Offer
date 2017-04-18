//atoi的手动实现，将字符串转换为数字，例如“123”——>123
//还未实现当字符串数据大于int的范围时的情况；
#include<iostream>
using namespace std;



int g_Invalide = 0; //0代表正常

int StrToInt(const char *str)
{
	char* Oldstr;
	Oldstr = (char*)str;
	//异常处理：除‘+ - 0-9’，其他的都是非法字符串
	while (*str != '\0')
	{
		if((*str>'9' || *str <'0' )&& *str != '-' && *str != '+')
		{
			g_Invalide = 1;	//1代表输入非法
			return 0;
		}
		++str;
	} 

	//正负号处理：首位为‘+ -’
	int minus=0;	//默认0位正数
	str = Oldstr;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			minus = 1;
		++str;
	}
	//转化
	int number = 0;
	while(*str != '\0')
	{
		number = number*10 + (*str - '0');
		++str;
	}
	if(minus)
		number *= -1;
	return number;
}


void main()
{
	char *str = "-23a4" ;
	int x = StrToInt(str);
	if(g_Invalide)
		cout << "Illegal Input";
	cout << x;
	
}
