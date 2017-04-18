





#include<string.h>
#include<iostream>
using namespace std;

char* StrTran(char* str)
{

	//异常,返回0，代表异常~
	if(!str)
		return 0;


	int nLen = strlen(str);
	//查找一共有多少个空格
	int i = 0;	//标记空格
	int j = 0;	//原字符串的迭代器
	while (str[j] != '\0')
	{
		if(str[j] == ' ')
			++i;
		j++;
	}
	//计算需要的大小
	char *newstr = new char[i*2+nLen+1];
	newstr[i*2+nLen] = '\0';
	//从尾部到头部赋值
	j = nLen-1;
	int jnew = i*2+nLen-1;
	while(j >= 0)
	{
		if(str[j] == ' ')
		{
			newstr[jnew--] = '0';
			newstr[jnew--] = '2';
			newstr[jnew--] = '%';
			--j;
		}
		else
			newstr[jnew--] = str[j--];
	}
	return newstr;
	
}



void main()
{
	char *p = "hel wo men nihao" ;
	p = 0;
	char *q = StrTran(p);
	if(!q)
	{
		cout << "error";
		return;
	}
	cout << q;


}









//使用std::string 不能达到算法的目的；
/*

#include<string.h>
#include<string>
#include<iostream>

using namespace std;
string StrTran(char *str)
{
	//返回nullptr代表错误
	if(!str)
		return nullptr;
	int i=0;
	int nLen = strlen(str);
	string newstr;
	while (i<nLen)
	{
		if(str[i] == ' ')
			newstr += "%20";
		else
			newstr += str[i];
		++i;
	}
	return newstr;
}

void main()
{
	char *p = "hello world hey!" ;
	string q = StrTran(p);
	cout << q ;


}


*/
