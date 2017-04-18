#include<iostream>
#include<stack>
using namespace std;
/*
class CQueue
{
public:
//	CQueue();
//	~CQueue();
	void appendTail(const int& Node);
	int deleteHead();
private:
	stack<int> stack_push;	//平时数据主要放在这里
	stack<int> stack_pop;	//
};

void CQueue::appendTail(const int& Node)
{
	stack_push.push(Node);
}

int CQueue::deleteHead()
{
	//从push栈中载入数据；
	if(stack_push.empty())
		throw exception("The Queue is Empty");
	while (!stack_push.empty())
	{
		stack_pop.push(stack_push.top());
		stack_push.pop();
	}
	int Node = stack_pop.top();
	stack_pop.pop();

	//再放回到push栈中
	while (!stack_pop.empty())
	{
		stack_push.push(stack_pop.top());
		stack_pop.pop();
	}
	return Node;
}


*/


/*
//非模板化的
class CQueue
{
public:
//	CQueue();
//	~CQueue();
	void appendTail(const int& Node);
	int deleteHead();
private:
	stack<int> stack_push;	//平时数据主要放在这里
	stack<int> stack_pop;	//
};

void CQueue::appendTail(const int& Node)
{
	stack_push.push(Node);
}
int CQueue::deleteHead()
{

	if(stack_pop.size()<=0)
	{
		while(stack_push.size() > 0 )
		{
			stack_pop.push(stack_push.top());
			stack_push.pop();
		}

	}

	//异常处理,不会使用！！！
	if(stack_pop.size() == 0)
		return -1;
//		throw new exception("queue is empty");
		//throw exception("The CQueue is empty!");
	int a = stack_pop.top();
	stack_pop.pop();
	return a;
}


*/


//模板化的：
template<typename T>class CQueue
{
public:
	CQueue();
	~CQueue();
	void appendTail(const T& Node);
	T deleteHead();
private:
	stack<T> stack_push;	//平时数据主要放在这里
	stack<T> stack_pop;	//
};
template<typename T> CQueue<T>::CQueue()
{

}
template<typename T> CQueue<T>::~CQueue()
{

}

template<typename T> void CQueue<T>::appendTail(const T& Node)
{
	stack_push.push(Node);
}
template<typename T> T CQueue<T>::deleteHead()
{

	if(stack_pop.size()<=0)
	{
		while(stack_push.size() > 0 )
		{
			stack_pop.push(stack_push.top());
			stack_push.pop();
		}

	}

	//异常处理,不会使用！！！
	if(stack_pop.size() == 0)
		throw exception("The CQueue is empty!");
//		return -1;
//		throw new exception("queue is empty");
		//throw exception("The CQueue is empty!");
	T a = stack_pop.top();
	stack_pop.pop();
	return a;
}
void main()
{
	int arr[6] = {3,6,7,9,34,55};
	int i = 0;
	CQueue<int> q;
	while(i<6)
	{
		q.appendTail(arr[i]);
		++i;
	}
	while(i>=1)
	{
		cout << q.deleteHead() << " ";
		
		--i;
	}
	
}
