#include "Arrays.h"

// Jonathan Vazquez Rivera
// jvazquez441@email.suagm.edu
// COSC-335 Data Structures 2020-01

//Default constructor: it creates an Array of 100 positions
Arrays::Arrays()
{
	Arr = new int[10];
	size = 10;
}

//Special constructor: it creates an Array of sz positions
Arrays::Arrays(int sz)
{
	Arr = new int[sz];
	size = sz;
}

//Copy Constructor
Arrays::Arrays(Arrays& originalArray)
{
	Arr = originalArray.Arr;
	size = originalArray.size;
}


//Destructor: deallocate memory
Arrays::~Arrays()
{
	delete[]Arr;
	Arr = 0;
}

//readArray Method: Reads all positions of the array
void Arrays::readArray()
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << "Array[" << i << "]= ";
		cin >> Arr[i];
	}
}

//printArray Method: Prints all positions of the array
void Arrays::printArray()
{
	int i;
	for (i = 0; i < size; i++)
	{
		cout << Arr[i] << "  ";
	}
	cout << endl;
}

//printArray Method: Prints the n first positions of the array
void Arrays::printArray(int n)
{
	//
}

void Arrays::generateArray()
{
	int i;
	for (i = 0; i < size; i++)
	{
		Arr[i] = rand() % 1000;
	}

}

void Arrays::initArray(int i)
{
	delete[]Arr;
	Arr = new int[i];
	size = i;
}

//getSize Method: return the size of the Array
int Arrays::getSize()
{
	return size;
}

//Overloading += Operator
void Arrays::operator +=(const Arrays& B)
{
	int i;
	for (i = 0; i < size; i++) {
		Arr[i] += B.Arr[i];
	}
}

//Overloading *= Operator for Array*int
void Arrays::operator *=(int val)
{
	int i;
	for (i = 0; i < size; i++) {
		Arr[i] *= val;
	}

}
//Overloading * operator (dot product or scalar product)
double Arrays::operator *(Arrays& B)
{
	int i;
	double sum = 0;
	for (i = 0; i < size; i++) {
		sum += Arr[i] * B.Arr[i];
	}
	return sum;
}



////Overloading + Operator
Arrays* Arrays::operator +(Arrays& B)
{

	Arrays *C = new Arrays(size);

	if (size == B.size) {
		for (int i = 0; i < size; i++) {
			C->Arr[i] = Arr[i] + B.Arr[i];
		}
	}

	return C;

}
//
//
//
//Overloading * Operator for Array*int
Arrays* Arrays::operator *(int val)
{

	Arrays* C = new Arrays(size);

	for (int i = 0; i < size; i++) {
		C->Arr[i] = Arr[i] * val;
	}

	return C;
}


//Overloading = Operator
void Arrays::operator =(const Arrays& B)
{
	cout << " Operator = activated" << endl;
	if (size == B.size) {
		for (int i = 0; i < size; i++) {
			Arr[i] = B.Arr[i];
		}
	}
}
