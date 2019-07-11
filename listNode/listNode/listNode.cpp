#include <iostream>
#include<assert.h>
using namespace std;

class Objects
{
public:
	Objects()
	{}
	virtual ~Objects()
	{}
public:
	virtual void Print()const = 0;//纯虚函数的另外名字叫接口
};
class List;
class ListNode
{
	friend List;
public:
	ListNode()
	{
		data = NULL;
		next = NULL;
	}
	ListNode(Objects* pobj)
	{
		data = pobj;
		next = NULL;
	}
	~ListNode()
	{

	}
private:
	Objects* data;
	ListNode* next;

};

class List
{
public:
	List()
	{
		Head = Tail = new ListNode;
	}
	void Push_Back(Objects* p)
	{
		ListNode* s = new ListNode(p);
		assert(s != NULL);
		Tail->next = s;
		Tail = s;
	}
	void PrintList()const
	{
		ListNode *p = Head->next;
		while (p != NULL)
		{
			p->data->Print();
			p = p->next;
		}
		cout << "Nul,"<<endl;
	}
	~List(){}
private:
	ListNode* Head;
	ListNode* Tail;
};
///////////////////////////////////////////////////////////////////
class IntObjects : public Objects
{
public:
	IntObjects(int d = 0): data(d)
	{}
public:
	void Print()const//IntObjects继承了Object父类就必须实现他的纯虚函数。
	{
		cout << data << "-->";
	}
	~IntObjects()
	{
	}
private:
	int data;
};
//////////////////////////////////////////////////////////////////

int main()
{
	List mylist;
	for (int i = 1; i <= 5; ++i)
	{
		IntObjects* pi = new IntObjects(i);
		mylist.Push_Back(pi);
	}
	mylist.PrintList();
}
