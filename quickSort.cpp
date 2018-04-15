#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int partition(vector <int>& nonSortedVector, int left, int right);

void quicksort(vector <int>& nonSortedVector, int left, int right)
{
	if (left < right)
	{
		int q = partition(nonSortedVector, left, right);
		quicksort(nonSortedVector, left, q - 1);
		quicksort(nonSortedVector, q + 1, right);
	}
}

int partition(vector <int>& nonSortedVector, int left, int right)
{
	int driver = nonSortedVector[right];
	int i = left- 1;
	for (int j = left; j <= right-1; j++)
	{
		if (nonSortedVector[j] <= driver)
		{
			i++;
			int temp = nonSortedVector[i];
			nonSortedVector[i] = nonSortedVector[j];
			nonSortedVector[j] = temp;
		}
	}
	int temp = nonSortedVector[i+1];
	nonSortedVector[i+1] = nonSortedVector[right];
	nonSortedVector[right] = temp;
	return i + 1;
}

