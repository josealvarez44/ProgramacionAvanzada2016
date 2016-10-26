
#include "stdafx.h"
#include "List.h"
#include <iostream>

using namespace std;

int main()
{

	//Invertir los números
	int count = 0;
	List List1;
	while (count<12)
	{
		List1.Add(count);
		count++;
	}

	cout << "Lista ingresada" << endl;
	cout << List1.returnList() << endl;
	List1.InvertList();
	cout << "Lista invertida" << endl;
	cout << List1.returnList() << endl;
	system("Pause");

	cout << "--------------------------------" << endl;
	//Contar cuantos de un elementos existe en la lista.
	List List2;

	List2.Add(5);
	List2.Add(5);
	List2.Add(5);
	List2.Add(1);
	List2.Add(2);
	List2.Add(3);

	cout << "Cuantos 5 hay en la siguiente lista: " << endl;
	cout << List2.returnList() << endl;
	cout << "Respuesta" << endl;
	cout << List2.RepeatedElements(5) << endl;
	system("Pause");

	return 0;
}


