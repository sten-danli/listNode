#include<iostream>
#include<assert.h>
using namespace std;

class Object
{
public:
	Object(){}
	~Object()
	{

	}
};
class ListNode
{
public:
	ListNode()
	{
		data = NULL;
		next = NULL;
	}
	ListNode(Object* pobj)
	{
		data = pobj;
	}
	~ListNode()
	{

	}
private:
	Object* data;
	ListNode* next;
};
class List
{
public:
	List()
	{
		Head = new ListNode;
		Tail = new ListNode;
	}
	~List()
	{

	}
public:
	void Push_Back(Object* p)
	{
		ListNode *s = new ListNode(p);
		assert(s != NULL);
		Tail->next = s;
		Tail = s;
		
	}
private:
	ListNode* Head;
	ListNode* Tail;
};
////////////////////////////////////////////////////////
class IntObjects :public Object
{
public:
	IntObjects(int d =0):data(d)
	{}
	~IntObjects()
	{

	}
private: 
	int data;
};
////////////////////////////////////////////////////////

int main()
{
	List mylist;
	
}