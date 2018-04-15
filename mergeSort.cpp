#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void mergeVectors(vector <int>& vectorBeingMerged, int left, int right);

void mergeSort(vector <int>& nonSortedVector, int left, int right)
{
	if (left < right)
	{
		int middle = (left + right) / 2;
		mergeSort(nonSortedVector, left, middle);
		mergeSort(nonSortedVector, middle + 1, right);
		mergeVectors(nonSortedVector, left, right);
	}
}

void mergeVectors(vector <int>& vectorBeingMerged, int left, int right)
{
	int middlePoint = (left + right) / 2;
	vector <int> leftVector;
	vector <int> rightVector;
	vector <int> mergedVector;
	for (int i = left; i <= middlePoint; i++)
	{
		leftVector.push_back(vectorBeingMerged[i]);
		if(middlePoint - left +i +1 <= right)
			rightVector.push_back(vectorBeingMerged[middlePoint - left + i+1]);
	}
	
	
	unsigned int leftPointer = 0;
	unsigned int rightPointer = 0;
	for (int i = 0; i < right - left + 1; i++)
	{
		if(leftPointer == leftVector.size())
		{
			mergedVector.push_back(rightVector[rightPointer]);
			rightPointer++;
		}
		else if (rightPointer == rightVector.size())
		{
			mergedVector.push_back(leftVector[leftPointer]);
			leftPointer++;
		}
		else  if (leftVector[leftPointer] <= rightVector[rightPointer])
		{
			mergedVector.push_back(leftVector[leftPointer]);
			leftPointer++;
		}
		else
		{
			mergedVector.push_back(rightVector[rightPointer]);
			rightPointer++;
		}
	}
	
	
	int mergedPointer = 0;
	for (int i = left; i <= right; i++)
	{
		vectorBeingMerged[i] = mergedVector[mergedPointer];
		mergedPointer++;
	}
}