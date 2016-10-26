#include "stdafx.h"
#include "Lista.h"


Lista::Lista()
{
}


Lista::~Lista()
{
}

bool Lista::Add(int _value) {
	if (Head->Next == NULL)
	{
		Node *Nodo = new Node();
		Nodo->Value = _value;
		Head->Next = Nodo;
		Nodo->Previous = Head;
	}
	else
	{
		Node* Temporary = new Node();
		Temporary = Head;

		while (Temporary->Next != NULL)
		{
			Temporary = Temporary->Next;
		}

		Node *Aux = new Node();
		Temporary->Next = Aux;
		Aux->Value = _value;
		Aux->Previous = Temporary;
	}

	return true;
}

bool Lista::RemoveFirstValue(int _value) {

	if (Head->Next != NULL)
	{
		Node* Temporary = new Node();
		Temporary = Head->Next;
		while (true)
		{
			if (Temporary->Value == _value)
			{

				if (Temporary->Next != NULL)
				{
					Temporary->Previous->Next = Temporary->Next;
					Temporary->Next->Previous = Temporary->Previous;
					delete(Temporary);
					return true;
				}
				else
				{
					Temporary->Previous->Next = Temporary->Next;
					delete(Temporary);
					return true;
				}
			}
			else if (Temporary->Next == NULL)
			{
				return false;
			}
			else
			{
				Temporary = Temporary->Next;
			}
		}
	}
	else
	{
		return false;
	}
	
}

bool Lista::IsEmpty() {
	return true;
}

int Lista::HowManyThereAre(int _value) {

	if (Head->Next != NULL) 
	{
		Node* Temporary = new Node(); 
		Temporary = Head->Next; 
		int Items = 0;

		while (true)
		{
			if (Temporary->Value == _value)
			{
				Items++;
				if (Temporary->Next != NULL)
				{
					Temporary = Temporary->Next;
				}
				else
				{
					return Items;
				}
			}
			else if (Temporary->Next == NULL)
			{
				return Items;
			}
			else
			{
				Temporary = Temporary->Next;
			}
		}
	}
	else
	{
		return 0;
	}
}

bool Lista::Turn() { // THIS WAS HARD TO FIGURE OUT.

	if (Head->Next != NULL) // LIST SHOULD NOT BE EMPTY.
	{
		Node* Temporary = new Node();
		Temporary = Head->Next;

		while (Temporary->Next != NULL)
		{
			Temporary = Temporary->Next;  // SEARCHING THE LATEST ITEM IN LIST.
		}
		
		while (true)
		{
			if (Temporary->Previous != Head) // GOING BACK FROM LATEST TO FIRST ITEM.
			{
				Node * Aux; // AUXILIARY POINTER THAT WILL SAVE A NODE WHILE WE ARE CHANGING SOME STUFF.
				Aux = Temporary->Next; // WE SAVE THE "NODE->NEXT" NODE. THIS IS IMPORTANT FOR NOT LOSE THE "CHAIN";
				Temporary->Next = Temporary->Previous; // THIS MAKES THE CURRENT NODE->NEXT POINTS TO NODE->PREVIOUS.
				Temporary = Temporary->Previous; // WE GO NOW TO THE PREVIOUS NODE FROM CURRENT NODE.
				Temporary->Next->Previous = Aux; // MAKE CURRENT NODE->PREVIOUS (ACTUALLY NOT CURRENT NODE ANY MORE, BUT YOU KNOW) SAME AS AUX.
			}
			else // THIS IS BECAUSE THE FIRST NODE IN LIST MUST BE TREATED IN A SPECIAL WAY. SO SPOILED.
			{
				Temporary->Previous = Temporary->Next;
				Temporary->Next = NULL;
				break;
			}
		}

		while (Temporary->Previous != NULL) // COME ON, GOING DOWN ONCE AGAIN.
		{
			Temporary = Temporary->Previous; // SEARCHING THE NODE. WHICH ACTUALLY IS THE FIRST NODE RIGTH NOW.
		}

		Temporary->Previous = Head; // FOUND IT.  MUST POINT TO HEAD.
		Head->Next = Temporary; // HEAD MUST POINT TO NODE. IT'S A NICE HUG.
		return true;
	}
}