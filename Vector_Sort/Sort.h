#pragma once
#include <vector>
void Write_to_file(const int vect_size, const int exc_count, const int com_count);
void Quick_Write_to_file(const int vect_size, const int exc_count, const int com_count);


void Bubble(std::vector <int>& vect);
void Sinking(std::vector<int>& vect);
void Check_bubble(std::vector<int>& vect);
void Selection(std::vector<int>& vect);
void Insert(std::vector<int>& vect);
void Shell(std::vector<int>& vect);
void Shell_dop(std::vector<int>& vect);
void Gnome(std::vector<int>& vect);
void Sheiker(std::vector<int>& vect);
void Chet_Nechet(std::vector<int>& vect);
void MergeSort(std::vector<int>& vect, int left, int right);
void Merge(std::vector<int>& vect, const int l, const int r);
void heapify(std::vector <int>& arr, const int n, const  int i);
void heapSort(std::vector <int>& arr);
void QuickSort(std::vector<int>& vect, const size_t start, const size_t end);
void heapSort_ob(std::vector <int>& arr);
void heapify_ob(std::vector <int>& arr, const int n, const  int i);
void rr(std::vector <int>& arr);
