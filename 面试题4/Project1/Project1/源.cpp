





#include<string.h>
#include<iostream>
using namespace std;

char* StrTran(char* str)
{

	//�쳣,����0�������쳣~
	if(!str)
		return 0;


	int nLen = strlen(str);
	//����һ���ж��ٸ��ո�
	int i = 0;	//��ǿո�
	int j = 0;	//ԭ�ַ����ĵ�����
	while (str[j] != '\0')
	{
		if(str[j] == ' ')
			++i;
		j++;
	}
	//������Ҫ�Ĵ�С
	char *newstr = new char[i*2+nLen+1];
	newstr[i*2+nLen] = '\0';
	//��β����ͷ����ֵ
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









//ʹ��std::string ���ܴﵽ�㷨��Ŀ�ģ�
/*

#include<string.h>
#include<string>
#include<iostream>

using namespace std;
string StrTran(char *str)
{
	//����nullptr�������
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
