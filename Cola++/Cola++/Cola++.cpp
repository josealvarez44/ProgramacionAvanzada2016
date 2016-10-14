// Cola++.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "Cola.cpp"
#include <iostream>


using namespace std;

int main()
{
	/* Does it exist any difference between both of this objects?*/
	/* Do they work different?*/

	Cola cola; 
	Cola *col = new Cola(); 
	
	cola.Queue(14);
	cola.Queue(13);
	cola.Queue(12);
	cola.Queue(11);
	cola.Dequeue();
	cola.Dequeue();
	cola.Dequeue();

	cout << "This will return 11: " << cola.Front() << endl;

	cola.Dequeue();
	cola.Queue(12);
	cola.Queue(11);
	cout << "This will return 12: " << cola.Front() << endl; 


	col->Queue(14);
	col->Queue(13);
	col->Queue(12);
	col->Queue(11);
	col->Dequeue();
	col->Dequeue();
	col->Dequeue();

	cout << "This will return 11: " << col->Front() << endl;

	col->Dequeue();
	col->Queue(14);
	col->Queue(13);
	col->Queue(12);
	col->Queue(11);
	col->Queue(12);
	col->Queue(11);
	col->Dequeue();
	col->Dequeue();
	col->Dequeue();
	cout << "This will return 11: " << col->Front() << endl;
	cin.get();
    return 0;
}

