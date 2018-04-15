#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void insertSort(vector <int>& nonSortedVector)
{
	for (int i = 1; i < nonSortedVector.size(); i++)
	{
		int key = nonSortedVector[i];
		int j = i - 1;
		while ((j >= 0) && (nonSortedVector[j] > key))
		{
			nonSortedVector[j + 1] = nonSortedVector[j];
			j--;
		}
		nonSortedVector[j + 1] = key;
	}
}

int findInsertionPlace(vector <int>& nonSortedVector, int pointSearched, int left, int right)
{
	int middle = (right - left) / 2 + left;
	if ((left == right))
	{
		if (nonSortedVector[left] < nonSortedVector[pointSearched])
			return left + 1;
		else
			return left;
	}		
	else if (nonSortedVector[middle] == nonSortedVector[pointSearched])
		return middle;
	else if (nonSortedVector[middle] < nonSortedVector[pointSearched])
		return findInsertionPlace(nonSortedVector, pointSearched, middle+1, right);
	else
		return findInsertionPlace(nonSortedVector, pointSearched, left, middle);
}

void insertSortBinary(vector <int>& nonSortedVector)
{
	for (int i = 1; i < nonSortedVector.size(); i++)
	{
		int key = nonSortedVector[i];
		int insertionPlace = findInsertionPlace(nonSortedVector, i, 0, i-1);
		int j = i - 1;
		while (j >= insertionPlace)
		{
			nonSortedVector[j + 1] = nonSortedVector[j];
			j--;
		}
		nonSortedVector[j + 1] = key;
	}
}