#include<iostream>

//用递归的方法遍历。

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;

};
BinaryTreeNode* constructCore(int* startPreOrder,int* endPreOrder,int* startInOrder,int* endInOrder)
{
	int rootValue = *startPreOrder;
	BinaryTreeNode* root = new BinaryTreeNode;
	root->m_nValue = rootValue;
	root->m_pLeft = root->m_pRight = nullptr;

	//递归循环的结束条件/边界条件/退出条件：当输入的前序和中序数组都只有一个值的时候return
	if(startPreOrder == endPreOrder)
	{
		if(startInOrder == endInOrder && *startPreOrder == *startInOrder)
			return root;
		else
			throw std::exception("InValid input");
	}
	//在中序遍历中找到根节点的值
	int *rootInOrder = startInOrder;
	while(rootInOrder != endInOrder && *rootInOrder != rootValue)
		++rootInOrder;
	//InOrder中不存在rootValue
	if(rootInOrder == endInOrder && *rootInOrder != rootValue)
		throw std::exception("InValid input");
	int Lenght = rootInOrder - startInOrder;



	if(Lenght>0)
	{//构造左子树
		int* startLeftPreOrder = startPreOrder+1;
		int* endLeftPreOrder = startPreOrder+Lenght;
		int* startLeftInOrder = startInOrder;
		int* endLeftInOrder = startInOrder+Lenght-1;
		root->m_pLeft = constructCore(startLeftPreOrder,endLeftPreOrder,startLeftInOrder,endLeftInOrder);
	}
	if(Lenght<endInOrder-startInOrder)
	{//构造左子树
		int* startRightPreOrder = startPreOrder+Lenght+1;
		int* endRightPreOrder = endPreOrder;
		int* startRightInOrder = startInOrder+Lenght+1;
		int* endRightInOrder = endInOrder;
		root->m_pRight = constructCore(startRightPreOrder,endRightPreOrder,startRightInOrder,endRightInOrder);
	}
	return root;
}



BinaryTreeNode* construct(int* PreOrder,int* InOrder ,int nLength)
{
	if(PreOrder == NULL || InOrder == NULL || nLength<0)
		return NULL;
	return constructCore(PreOrder,PreOrder+nLength,InOrder,InOrder+nLength);

}

void main()
{
	int PreOrder[8] = {1,2,4,7,3,5,6,8};
	int InOrder[8] = {4,7,2,1,5,3,8,6};
	BinaryTreeNode* pRoot;
	pRoot = construct(PreOrder,InOrder,8);


}

/*
int searchforseq(int n,int* Array,int nIn)
{//-1代表输入的数组有误
	int i = 0;
	while(i<nIn)
	{
		if(Array[i] == n)
			return i;
		++i;
	}
	return -1;
}
BinaryTreeNode* CreateTree(int* PreOrder,int nPre,int* InOrder,int nIn)
{
	BinaryTreeNode* pRoot;
	int i = 0,j = 0;
	pRoot->m_nValue = PreOrder[i];
	int k = searchforseq(PreOrder[i],InOrder,nIn);	//代表返回的位序
	
	pRoot->m_pLeft = CreateTree(PreOrder+i+1,k,InOrder+j,k);
	pRoot->m_pRight = CreateTree(PreOrder+k+1,nPre-k-1,InOrder+k+i,nPre-k-1);



	return pRoot;
}

*/

