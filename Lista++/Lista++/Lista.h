#pragma once
#include "Node.h"
class Lista
{
public:

	Node* Head = new Node();


	bool Add(int _value);
	bool RemoveFirstValue(int _value);
	bool IsEmpty();
	int HowManyThereAre(int _value);
	bool Turn();
	Lista();
	~Lista();
};

