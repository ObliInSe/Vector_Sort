#include <iostream>
#include "Sort.h"
#include "Print.h"
#include <vector>
using namespace std;


int main()							 
{								
	 int size = 15;
	vector<int>* vect = new vector<int> [size];
	for (size_t i = 1; i < size; i++)
	{
		Filling_vector(vect[i],i);
	}
	
	cout << "Start_Vector" << endl;
	Print_vector(vect[4]);
	QuickSort(vect[4], 0, vect[4].size() - 1);
	cout << "End_Vector" << endl; 
	Print_vector(vect[4]);

	return 0;
}


