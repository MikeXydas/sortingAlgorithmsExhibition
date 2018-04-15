#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void selectionSortRecursive(vector <int>& nonSortedVector, unsigned int startingPoint)
{
	int maxPointer = startingPoint;
	for (unsigned int i = startingPoint + 1; i < nonSortedVector.size(); i++)
	{
		if (nonSortedVector[i] > nonSortedVector[maxPointer])
			maxPointer = i;
	}

	int temp = nonSortedVector[startingPoint];
	nonSortedVector[startingPoint] = nonSortedVector[maxPointer];
	nonSortedVector[maxPointer] = temp;

	startingPoint++;

	if ((startingPoint + 1) != nonSortedVector.size())
		selectionSortRecursive(nonSortedVector, startingPoint);
	else
		return;
}