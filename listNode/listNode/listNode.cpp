#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

class Object
{
public:
	Object(){}
	virtual~Object(){}
public:
	virtual  void Print()const = 0;
	virtual bool Compare(Object *pobj)const = 0;
	
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
	ListNode(Object* p)
	{
		data = p;
		next = NULL;
	}
private:
	Object*	data;
	ListNode* next;
};
class List
{
public:
	List()
	{
		Head = Tail = new ListNode;
	}
public:
	void Push_Back(Object* pobj)
	{
		ListNode* s = new ListNode(pobj);
		assert(s != NULL);
		Tail->next = s;
		Tail = s;
	}
public:
	void Printlist()const
	{
		ListNode* p = Head->next;
		while (p != NULL)
		{
			p->data->Print();
			p = p->next;
		}
		cout << "NUL" << endl;
	}
public:
	void InsertOrder(Object* pobj)
	{
		ListNode *s = new ListNode(pobj);
		ListNode *phead = Head;
		ListNode* p = Head->next;
		while (p!=NULL && p->data->Compare(s->data))
		{
			phead = p;
			p = p->next;
		}
		s->next = p;
		phead->next = s;
		if (phead == NULL)
			Tail = s;
	}
private:
	ListNode* Head;
	ListNode* Tail;
};
///////////////////////////////////////////////////
class intObjects : public Object
{
public:
	intObjects(int d=0):data(d){}
	~intObjects(){}
	void Print()const
	{
		cout << data << "-->";
	}
public:
	 bool Compare(Object *pobj)const
	{
		 intObjects* pi = dynamic_cast<intObjects*>(pobj);
		 assert(pi != NULL);
		 return data > pi->data;
	}
private:
	int data;
};
////////////////////////////////////////////////////
//class strObjects : public Object
//{
//public:
//	strObjects(const char* str)
//	{
//		if (str == NULL)
//		{
//			data = new char[1];
//			data[0] = '\0';
//		}
//		else
//		{
//			data = new char[strlen(str) + 1];
//			strcpy(data,str);
//		}
//	}
//	void Print()const
//	{
//		cout << data << "-->" ;
//	}
//private: 
//	char* data;
//
//};
/////////////////////////////////////////////////////
int main()
{
	List intList;

	intObjects* pi;
	pi = new intObjects(3);
	intList.InsertOrder(pi);

	pi = new intObjects(5);
	intList.InsertOrder(pi);

	pi = new intObjects(2);
	intList.InsertOrder(pi);

	pi = new intObjects(4);
	intList.InsertOrder(pi);

	intList.Printlist();

	/*List intList;
	for (int i = 0; i < 5; ++i)
	{
		intObjects* ip = new intObjects(i);
		intList.Push_Back(ip);
	}
	intList.Printlist();*/


	/*List mylist;
	const char* str[] = {"World, ","i am Lidan,","Hello","the new Gen!"};
	for (int i = 0; i < 4; ++i)
	{
		strObjects* sp = new strObjects(str[i]);
		mylist.Push_Back(sp);
	}
	mylist.Printlist();*/
	
}