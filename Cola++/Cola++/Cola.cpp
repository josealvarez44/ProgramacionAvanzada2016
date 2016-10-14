#include "stdafx.h"
#include "Cola.h"
#include "Node.cpp"

// TOP SECRET: THIS IS MAGIC.

class Cola
{
public:

	bool Queue(int Value) { // USE THIS TO ADD A NODE TO THE QUEUE.

		if (Head->Next == NULL) // IF HEAD IS NOT POINTING AT NO NODE...
		{
			Node* Temporary = new Node(Value, Head); // THEN JUST CREATE A NEW ONE. BE CAREFUL, THISS NODE MUST POINT TO THE HEAD.
			Head->Next = Temporary; // AND FINALLY MAKE HEAD TO POINT AT THE LAST NODE CREATED.
		}
		else //SURELY, QUEUE WON'T BE EMPTY MOST OF THE TIME.
		{
			Node* Temporary = new Node(Value, &(*Last())); // SO IT'S IMPORTANT TO CREATE A NEW NODE, BUT, ITS CONSTRUCTOR WILL RECEIVE THE LAST NODE IN THE QUEUE TO WHICH THIS NEW NODE MUST POINT TO. 
			Head->Master(Last(), Temporary); // THE NODE, THAT JUST A MILLISECOND AGO WAS THE LATEST NODE IN THE QUEUE, MUST POINT TO 'THE NEW LATEST NODE'.
		}

		return true;
	}

	bool Dequeue() { // DELETE A NODE MUST BE EASY, ISN'T IT?

		if (Head->Next == NULL)
		{
			// NOTHING TO DO HERE :)
		}
		else
		{
			Node* Aux = new Node(); // CREATE AN AUXILIARY NULL NODE.
			Aux = Head->Next; //AUXILIARY NOW IS SAME AS HEAD->NEXT NODE.
			
			if (Aux->Next != NULL)
			{
				Head->Next = Aux->Next;  //HEAD NOW IS POINTING TO AUXILIARY->NEXT NODE - IT MEANS, HEAD IS POINT TO THE 'HEAD' OF THE QUEUE
				Aux = Aux->Next; //AUXILIARY IS NOW SAME AS ITSELF->NEXT NODE
				Aux->Last = Head; // THE FIRST NODE IN QUEUE MUST POINT TO HEAD.

			}
			else
			{
				Head->Next = NULL;
			}


			// PANCAKES.
		}
		return true;
	}

	int Front() { // THIS RETURN THE VALUE OF THE FIRST NODE IN THE QUEUE. SO BASIC.
		if (Head->Next != NULL)
		{
			Node* Aux = new Node();
			Aux = Head->Next;
			return Aux->Value;
		}
		else
		{
			return NULL; // RETURN NULL IF QUEUE IS EMPTY.
		}
	}

	bool IsEmpty() {
		return Head->Next == NULL ? true : false;
	}

private:

	Node* Head = new Node();

	Node* Last() { //THIS FUNCTION IS A KIND OF RESEARCHER.

		Node* Temporary = new Node(); // CREATE A NULL NODE.
		Temporary = Head; // TEMPORARY IS SAME AS HEAD.

		while (Temporary->Next != NULL) // SO, WHILE THE FOLLOWING NODE OF TEMPORARY NODE ISN'T NULL...
		{
			Temporary = Temporary->Next; // WE MAKE TEMPORARY NODE SAME AS THE FOLLOWING NODE.
		}

		return Temporary; //LAST NODE IN QUEUE WILL BE THE ONE THAT IS POINTING AT NO NODE.
	}
};


