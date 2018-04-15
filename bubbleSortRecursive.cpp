#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void bubbleSortRecursive(vector <int>& nonSortedVector, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (nonSortedVector[i] < nonSortedVector[i + 1])
		{
			int temp = nonSortedVector[i];
			nonSortedVector[i] = nonSortedVector[i + 1];
			nonSortedVector[i + 1] = temp;
		}
	}
	if (size > 1)
		bubbleSortRecursive(nonSortedVector,size - 1);
	else
		return;
}

