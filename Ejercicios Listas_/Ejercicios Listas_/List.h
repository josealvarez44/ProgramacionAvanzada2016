#pragma once
#include "Node.h"
#include <string>
#include <sstream>
using namespace std;
class List
{
private:
	CNode* Head;
	CNode* Actual;
	int countNodes = 0;

public:
	List();
	~List();

	bool IsEmpty()
	{
		return Head == NULL;
	}

	void Add(int element)
	{
		CNode* newNode = new CNode(element);

		if (IsEmpty())
		{
			Head = newNode;
		}
		else
		{
			Actual->next = newNode;
		}

		CNode* t = Actual;
		Actual = newNode;

		if (Head->next != NULL)
		{
			Actual->previous = t;
		}
		countNodes++;
	}


	string returnList()
	{
		string text = "";
		if (IsEmpty())
		{
			return "La lista esta vacía";
		}
		else
		{
			CNode* t = Head;

			while (t->next != NULL)
			{
				ostringstream ss;
				ss << t->value;
				text += ss.str() + " ";
				t = t->next;
			}
			ostringstream ss;
			ss << t->value;
			text += ss.str() + " ";
			return text;
		}
	}


	//The times that an element is repeated
	int RepeatedElements(int element)
	{
		if (IsEmpty())
		{
			return -1;
		}
		else
		{
			CNode* t = Head;
			int countElement = 0;

			while (t->next != NULL)
			{
				if (t->value == element)
				{
					countElement++;
				}
				t = t->next;
			}

			if (t->value == element)
			{
				countElement++;
			}

			return countElement;
		}
	}

	void InvertList()
	{
		if (!IsEmpty())
		{
			CNode* t = Head->next;
			CNode* t2;

			while (t->next != NULL)
			{
				t2 = t->previous;
				t->previous = t->next;
				t->next = t2;
				t = t->previous;
			}

			t2 = Head;
			Head = Actual;
			Actual = t2;

			Head->next = Head->previous;
			Head->previous = NULL;
			Actual->previous = Actual->next;
			Actual->next = NULL;
		}
	}
};


