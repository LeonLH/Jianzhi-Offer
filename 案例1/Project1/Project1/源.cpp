//atoi���ֶ�ʵ�֣����ַ���ת��Ϊ���֣����硰123������>123
//��δʵ�ֵ��ַ������ݴ���int�ķ�Χʱ�������
#include<iostream>
using namespace std;



int g_Invalide = 0; //0��������

int StrToInt(const char *str)
{
	char* Oldstr;
	Oldstr = (char*)str;
	//�쳣��������+ - 0-9���������Ķ��ǷǷ��ַ���
	while (*str != '\0')
	{
		if((*str>'9' || *str <'0' )&& *str != '-' && *str != '+')
		{
			g_Invalide = 1;	//1��������Ƿ�
			return 0;
		}
		++str;
	} 

	//�����Ŵ�����λΪ��+ -��
	int minus=0;	//Ĭ��0λ����
	str = Oldstr;
	if(*str == '-' || *str == '+')
	{
		if(*str == '-')
			minus = 1;
		++str;
	}
	//ת��
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
