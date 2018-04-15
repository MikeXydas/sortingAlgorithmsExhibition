#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

void printIntVector(vector <int> printedVector)
{
	for (unsigned int i = 0; i < printedVector.size(); i++)
	{
		cout << " " << i + 1 << "-> " << printedVector[i] << endl;
	}
}