#include <stack>
#include <iostream>

using namespace std;




struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};
ListNode* g_pHead = 0;


void InverseListPrint(ListNode* pHead)
{
	stack<int> s;
	ListNode* pData = pHead;
	if(!pData)
		return;
	while(pData)
	{
		s.push(pData->m_nKey);
		pData = pData->m_pNext;
	}
	while(!s.empty())
	{
		int data = s.top();
		s.pop();
		cout << data << ' ';
	}


}

void ListPrint(ListNode *pHead)
{
	ListNode* pData = pHead;
	while(pData )
	{
		cout << pData->m_nKey << ' ';
		pData = pData->m_pNext ;
	}


}
void AddList( int n)
{
	ListNode *pData = new ListNode;
	pData->m_nKey = n;

	if(!g_pHead)
	{
		g_pHead = pData;
		pData->m_pNext = 0;
		return;
	}

	pData->m_pNext = g_pHead;
	g_pHead = pData;
	return;

}


int main()
{
	AddList(6);
	AddList(34);
	AddList(56);
	AddList(22);
	ListPrint(g_pHead);
	InverseListPrint(g_pHead);
	return 0;
}
