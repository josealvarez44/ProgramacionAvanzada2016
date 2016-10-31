#pragma once
#include "Node.h";

class DoublyLinkedList
{
public:
	CNode* head;
	int count;
	void Add(int newVal);
	void RemoveFirstValue(int delValue);
	bool IsEmpty();
	DoublyLinkedList();
	~DoublyLinkedList();
};

