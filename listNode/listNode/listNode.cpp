#include <iostream>
using namespace std;

class Objects
{
public:
	Objects()
	{}
	virtual ~Objects()
	{}
private:
	int data;
};
class ListNode
{
public:
	ListNode()
	{
		data = NULL;
		next = NULL;
	}
	ListNode(Objects* pobj)
	{
		data = pobj;
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
	~List()
	{

	}
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
	}
}
