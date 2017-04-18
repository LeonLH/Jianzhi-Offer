
/*
//将整个数组传入函数：
bool IsExist(int a[4][4],int b)
{
	
	int i = 1,j = 1;
	if(a[1][1] > b || a[4][4] < b)
		return false;
	int jtmp = 4;
	while(i<=4)
	{
		j = 1;
		while(j<=jtmp)
		{
			if(a[i][j] == b)
				return true;
			if(a[i][j] > b)
				jtmp = j;
			++j;
		}
		++i;
	}
	return false;
}


void main()
{
	int a[4][4]={
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int c = a[7];
	int b = 5;
	bool i = IsExist(a,b);
	return;


}

*/
//将二维数组的首地址传入
bool IsExist(int *Matrix,int rows,int coloms,int b)
{
	//异常分析
	if(!Matrix || rows<1 || coloms < 1)
		return false;
	int row = 1;
	int colom = coloms;
	while(colom > 0)
	{
		if(Matrix[coloms*(row-1)+colom-1] == b)
			return true;
		if(Matrix[coloms*(row-1)+colom-1] > b)
		{
			--colom ;
			continue;
		}
		if(Matrix[coloms*(row-1)+colom-1] < b)
		{
			++row;
			continue;
		}
	}
	return false;
}
void main()
{
	int a[4][4]={
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}
	};
	int b = 5;
	bool i = IsExist(*a,4,4,b);
	return;

}

