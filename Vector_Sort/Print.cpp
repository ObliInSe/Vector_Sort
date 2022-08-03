#include "Print.h"

void Print_vector(const std::vector<int> &vect)
{
	for (size_t i = 0; i < vect.size(); i++)
	{
		std::cout << vect[i] << " ";
	}
	std::cout << std::endl;
}
void Filling_vector(std::vector<int>& vect, const int size)
{
	for (size_t i = 0; i < pow(2, size); i++)
	{
		vect.push_back(rand()%999+1);
	}
}

void Filling_vector_best(std::vector<int>& vect, const int size)
{
	for (size_t i = 0; i < pow(2, size); i++)
	{
		vect.push_back(i);
	}
}

void Filling_vector_worst(std::vector<int>& vect, const int size)
{
	for (size_t i = 0; i < pow(2, size); i++)
	{
		vect.push_back(pow(2,size)-i);
	}
}
