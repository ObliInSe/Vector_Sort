#include "Sort.h"
#include <fstream>
#include <iostream>
#include "Print.h"
using namespace std;
//com = сравнени€ 
void Write_to_file(const int vect_size, const int exc_count, const int com_count)
{
	ofstream exc_file("Exchange.txt", ios_base::app);
	ofstream com_file("Comparisons.txt", ios_base::app);
	exc_file << exc_count << endl;
	com_file << com_count << endl;
	exc_file.close();
	com_file.close();
}

static int quick_exc_count = 0, quick_com_count = 0;
void Quick_Write_to_file(const int vect_size, const int exc_count, const int com_count)
{
	ofstream exc_file("Exchange.txt", ios_base::app);
	ofstream com_file("Comparisons.txt");
	exc_file << exc_count << endl;
	com_file << com_count << endl;
	exc_file.close();
	com_file.close();
}
void Sinking(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	for (size_t i = 0; i < vect.size(); i++)
	{
		for (size_t j = 0; j < vect.size() - (i + 1); j++)
		{
			com_count++;
			if (vect[j] < vect[j + 1])
			{
				
				swap(vect[j], vect[j + 1]);
				exc_count++;
			}
		}
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Bubble(std::vector<int>& vect)
{
	int exc_count =0, com_count = 0;
	for (size_t i = 0; i < vect.size(); i++)
	{
		for (size_t j = vect.size()-1; j > 0; j--)
		{
			com_count++;
			if (vect[j]<vect[j-1])
			{
				swap(vect[j], vect[j - 1]);
				exc_count++;
				Print_vector(vect);
			}
		}
	}
	Write_to_file(vect.size(),exc_count, com_count);
}
void Check_bubble(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	for (size_t i = 0; i < vect.size(); i++)
	{
		bool iteration = false;
		for (size_t j = vect.size() - 1; j > 0; j--)
		{
			com_count++;
			if (vect[j] < vect[j - 1])
			{
				swap(vect[j], vect[j - 1]);
				exc_count++;
				Print_vector(vect);
				iteration = true;
			}
		}
		if (iteration == false) break;
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Selection(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	int max_index;
	for (size_t i = 0; i < vect.size(); i++)
	{
		max_index = i;
		for (size_t j = i+1; j < vect.size(); j++)
		{
			com_count++;
			if (vect[j] < vect[max_index])
			{
				max_index = j;
			}
		}
		exc_count++;
		swap(vect[i], vect[max_index]);
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Insert(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	for (size_t i = 0; i < vect.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			com_count++;
			if (vect[j] < vect[j - 1])
			{
				swap(vect[j], vect[j - 1]);
				exc_count++;
			}
		}
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Shell(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	int step = vect.size() / 2;
	while (step > 0)
	{
		for (size_t i = 0; i < vect.size(); i++)
		{
			for (size_t j = vect.size()-i; (j-step) >= 0; j-=step)
			{
				//cout << "step = " << step << "\t";
				//com_count++;
				if (vect[j] < vect[j - step])
				{
					swap(vect[j], vect[j - step]);
					//exc_count++;
				}
			}
		}
		step /= 2;
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Shell_dop(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	int step = vect.size() / 2;
	
		for (size_t i = 0; i < vect.size(); i++)
		{
			for (size_t j = i; (j + step) < vect.size(); j += step)
			{
				com_count++;
				if (vect[j] > vect[j + step])
				{
					swap(vect[j], vect[j + step]);
					exc_count++;
				}
			}
		}
		step = 1;
		for (size_t i = 0; i < vect.size(); i++)
		{
			for (size_t j = i; (j + step) < vect.size(); j += step)
			{
				com_count++;
				if (vect[j] > vect[j + step])
				{
					swap(vect[j], vect[j + step]);
					exc_count++;
				}
			}
		}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Gnome(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	for (size_t i = 0; i < vect.size(); i++)
	{
		for (int j = i; j > 0; j--)
		{
			com_count++;
			if (vect[j] < vect[j - 1])
			{
				exc_count++;
				swap(vect[j - 1], vect[j]);
			}
		}
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Sheiker(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	bool check=1;
	while (check != 0)
	{
		check = 0;
		int r = vect.size()-1, l = 0;
		for (size_t i = l; i < vect.size()-1; i++)
		{
			com_count++;
			if (vect[i] > vect[i + 1])
			{
				exc_count++;
				swap(vect[i], vect[i + 1]); 
				Print_vector(vect);
				check = 1;
			}
		}
		r--;
		for (size_t i = r; i > 0; i--)
		{
			com_count++;
			if (vect[i] < vect[i - 1])
			{
				exc_count++;
				swap(vect[i], vect[i - 1]);
				check = 1;
			}
		}
		l++;
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
void Chet_Nechet(std::vector<int>& vect)
{
	int exc_count = 0, com_count = 0;
	bool check = 1;
	while (check != 0)
	{
		check = 0;
		for (size_t i = 0; i+1 < vect.size(); i+=2)
		{
			com_count++;
			if (vect[i] > vect[i + 1])
			{
				exc_count++;
				swap(vect[i], vect[i + 1]);
				check = 1;
			}
		}
		for (size_t i = 1; i+1 < vect.size(); i += 2)
		{
			com_count++;
			if (vect[i] > vect[i + 1])
			{
				exc_count++;
				swap(vect[i], vect[i + 1]);
				check = 1;
			}
		}
	}
	Write_to_file(vect.size(), exc_count, com_count);
}
int count_dop_dop = 0;
void Merge(std::vector<int>& vect, const int left, const int right)
{
	int middle, start, final, j;
	int exc_count = 0, com_count = 0;
	vector <int> vect_dop;
	vect_dop.assign(vect.begin(), vect.end());
	middle = (left + right) / 2;
	start = left;
	final = middle + 1;
	for (j = left; j <= right; j++)
	{
		if ((start <= middle) && ((final > right) || (vect[start] < vect[final])))
		{
			vect_dop[j] = vect[start];
			start++;
			count_dop_dop++;
		}
		else
		{
			vect_dop[j] = vect[final];
			final++;
			count_dop_dop++;
		}
		Print_vector(vect);
		
	}
	for (size_t i = 0; i < vect_dop.size(); i++)
	{
		vect[i] = vect_dop[i];
	}
	cout << count_dop_dop << endl;
}
 int count_dop = 0;
 
void MergeSort(std::vector<int>& vect, int left, int right)	
{
	//int count=0;
	if (left < right)
	{
		MergeSort(vect, left, (left + right) / 2);
		MergeSort(vect, (left + right) / 2 + 1, right);
		Merge(vect, left, right);
		count_dop++;
	}
	//cout << count_dop/2 << endl;
}

static int c = 0;
static int sr = 0;
void heapify(vector <int>& arr, const int n, const  int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	sr += 2;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// –екурсивно преобразуем в двоичную кучу затронутое поддерево
		c++;
		heapify(arr, n, largest);
	}
	
	
}
// ќсновна€ функци€, выполн€юща€ пирамидальную сортировку
void heapSort(std::vector <int>& arr)
{//32415
	for (int i = arr.size() / 2 -1; i >= 0; i--)
		heapify(arr, arr.size(), i);
	for (int i = arr.size() - 1; i >=0; i--)
	{
		
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
	Write_to_file(arr.size(),c,sr);
}




void heapify_ob(std::vector <int>& arr, const int n,   int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] < arr[largest])
		largest = l;
	if (r < n && arr[r] < arr[largest])
		largest = r;
	sr += 2;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		// –екурсивно преобразуем в двоичную кучу затронутое поддерево
		c++;
		heapify_ob(arr, n, largest);
	}


}
// ќсновна€ функци€, выполн€юща€ пирамидальную сортировку
void heapSort_ob(vector <int>& arr)
{
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
		heapify_ob(arr, arr.size(), i);
	// ќдин за другим извлекаем элементы из кучи
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		//cout << i << endl;
		swap(arr[0], arr[i]);
		heapify_ob(arr, i, 0);
	}
	Write_to_file(arr.size(), c, sr);
}

	void rr(std::vector <int> & arr)
	{
		for (int i = arr.size() / 2 - 1; i >= 0; i--)
			heapify_ob(arr, arr.size(), i);
	}

void QuickSort(std::vector<int>& vect, const size_t start, const size_t end) {
	int left = start, right = end;
	const int pivot = vect[end];

	do {
		while (vect[left] < pivot) {
			left++;
		}
		while (vect[right] > pivot) {
			right--;
		}
		
		//quick_com_count++;
		if (left < right) {
			if (vect[right] < vect[left]) {
				//quick_exc_count++;
				swap(vect[right], vect[left]);
				Print_vector(vect);
				
			}
		}
	} while (left < right);

	if (start < left) {
		QuickSort(vect, start, left - 1);
	}
	if (left < end) {
		QuickSort(vect, left + 1, end);
	}
	//Quick_Write_to_file(vect.size(), quick_exc_count, quick_com_count);
}