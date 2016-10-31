#include "stdafx.h"
#include "DoublyLinkedList.h"


void DoublyLinkedList::Add(int newVal)
{
	if (head == NULL)
	{
		head = new CNode();
		head->value = newVal;
		head->previous = NULL;
		head->next = NULL;
	}
	else
	{
		CNode* temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		CNode* newElement = new CNode();
		newElement->value = newVal;
		newElement->next = NULL;
		newElement->previous = temp;
		temp->next = newElement;
	}
	count++;
}

void DoublyLinkedList::RemoveFirstValue(int delValue)
{	
	if ((head->next == NULL) && (head->value == delValue))
	{
		head = NULL;
		return;
	}
	CNode* current = head->next;
	while (current->next != NULL)
	{
		if (current->value == delValue)
		{
			current->previous->next = current->next;
			current->next->previous = current->previous;
			delete(current);
			count--;
			return;
		}
		else
		{
			current = current->next;
		}
	}
}


DoublyLinkedList::DoublyLinkedList()
{
}


DoublyLinkedList::~DoublyLinkedList()
{
}
