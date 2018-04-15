#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void bubbleSortRecursive(vector <int>& nonSortedVector, int size);
void selectionSortRecursive(vector <int>& nonSortedVector, unsigned int startingPoint);
void mergeSort(vector <int>& nonSortedVector, int left, int right);
void insertSort(vector <int>& nonSortedVector);
void insertSortBinary(vector <int>& nonSortedVector);
void quicksort(vector <int>& nonSortedVector, int left, int right);
void heapSort(vector <int>& nonSortedVector);



