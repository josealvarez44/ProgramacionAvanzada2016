#include "stdafx.h"
//THIS CLASS DEFINES THE SKELETON OF ANY NODE.

class Node
{
public:

	int Value; 
	Node *Last; 
	Node *Next;


	Node(int _value, Node *_anterior) { // DEFAULT CONSTRUCTOR, THIS MUST BE USED IN ORDER TO 'QUEUE' A NEW NODE.
		Value = _value;
		Last = _anterior;
		Next = NULL;
	}

	Node() { // AUXILIARY CONSTRUCTOR, ITS HELPFUL WHENEVER YOU WANT A EMPTY NODE - REALLY. IT'S A NULL NODE.
		Value = 0;
		Last = NULL;
		Next = NULL;
	}

	bool Master(Node* Suspect, Node* Victim) { //THIS IS USEFUL. THE SUSPECT MUST AIM TO ANOTHER VICTIM (TALKING ABOUT NODES, OF COURSE).
		Suspect->Next = Victim;
		return true;
	}

private:

};

