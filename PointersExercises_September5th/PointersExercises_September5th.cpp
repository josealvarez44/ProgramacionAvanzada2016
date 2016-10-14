// PointersExercises_September5th.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;

//Exercise 1: Pointer array of Double
double* menor(double* a, int x)
{
	double menor = *a;
	double* position = NULL;
	for (size_t i = 0; i < x; i++)
	{
		if (*(a + i) < menor)
		{
			menor = *(a + i);
			position = a + i;
		}
	}
	return position;
}
/*Exercise 2: Compare two integers and with the function "IsHigher" return the largest 
and the function "IsLower" return the smallest number*/

//Function IsHigher 
int IsHigher(int a, int b)
{
	return a > b ? a : b;
}
//Function IsLower
int IsLower(int a, int b)
{
	return a < b ? a : b;
}
//Exercise 3: Implemetation of a list with pointers
struct NODE
{
	int value;
	NODE* next;
};

class LIST
{
public:
	NODE* head;
	void ADD(int x) {
		NODE NN;
		NN.value = x;
		NN.next = NULL;
		NODE* T = head;
		while (T -> next != NULL)
		{
			T= T ->next;
		}
		T-> next = &NN;
	
	}
	
private:

};

int main()
{
	
	//Exercise 2: Function pointers
	int(*f)(int, int);
	int num1 = 0;
	int num2 = 0;
	//Data entry
	cout << "Ingrese el primer numero: ";
	cin >> num1;
	cout << "Ingrese el segundo numero: ";
	cin >> num2;
	//Proof with IsHigher function
	f = IsHigher;
	f(num1, num2);
	cout <<"El numero mayor es: "<< (f(num1, num2)) << endl;
	//Proof with IsLower function
	f = IsLower;
	f(num1, num2);
	cout << "El numero menor es: " << (f(num1, num2)) << endl;

	//Pause before the end
	system("pause");
	
	return 0;
	
}
