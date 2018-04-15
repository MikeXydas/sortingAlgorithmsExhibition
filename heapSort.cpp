#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void fixHeap(vector <int>& nonSortedVector, int startingNode, int size);
void createHeap(vector <int>& nonSortedVector);

void heapSort(vector <int>& nonSortedVector)
{
	createHeap(nonSortedVector);
	int size = nonSortedVector.size() - 1;
	for (int i = nonSortedVector.size() - 1; i >= 1; i--)
	{
		int temp = nonSortedVector[size];
		nonSortedVector[size] = nonSortedVector[0];
		nonSortedVector[0] = temp;
		size--;
		fixHeap(nonSortedVector, 0, size);
	}
}

void createHeap(vector <int>& nonSortedVector)
{
	for (int i = (nonSortedVector.size() -1)/ 2; i >= 0; i--)
	{
		fixHeap(nonSortedVector, i,nonSortedVector.size());
	}
}
void fixHeap(vector <int>& nonSortedVector, int startingNode, int size)
{
	int left = startingNode * 2 + 1;
	int right = startingNode * 2 + 2;
	int max = -1;
	if ((left < size) && (nonSortedVector[left] > nonSortedVector[startingNode]))
		max = left;
	else
		max = startingNode;
	if ((right < size) && (nonSortedVector[right] > nonSortedVector[max]))
		max = right;
	if (max != startingNode)
	{
		int temp = nonSortedVector[startingNode];
		nonSortedVector[startingNode] = nonSortedVector[max];
		nonSortedVector[max] = temp;
		fixHeap(nonSortedVector, max, size);
	}
}