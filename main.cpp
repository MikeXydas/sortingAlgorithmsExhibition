#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <sstream>
#include <string>
#include <fstream>

#include "sortingFunctionsDefinitions.h"
#include "vectorManipulationDefinitions.h"

using namespace std;

int main(int argc, char * argv[])
{
	srand(time(NULL));
	vector <int> testVector;
	bool printsEnabled = true;
	int repeats = -1;

	if (argc == 3)
	{
		string arg2(argv[2]);
		if (!arg2.compare("-v"))
			printsEnabled = false;
	}
	repeats = atoi(argv[1]);

	for (int i = 0; i < repeats; i++)
	{
		testVector.push_back(rand() % 10000 + 1);
	}

	cout << "			---- Sorting algorithms exhibition ----" << endl;
	cout << endl;
	cout << "-Choose your algorithm by pressing the coresponding number: " << endl;
	cout << "-1. Bubble Sort (Recursive)" << endl;
	cout << "-2. Selection Sort (Recursive)" << endl;
	cout << "-3. Merge Sort" << endl;
	cout << "-4. Insert Sort" << endl;
	cout << "-5. Insert Sort (With binary search)" << endl;
	cout << "-6. Quick Sort" << endl;
	cout << "-7. Heap Sort" << endl;

	string input;
	string name;
	cout << endl << "-";
	cin >> input;

	if(printsEnabled)
		printIntVector(testVector);

	clock_t t = clock();

	if (!input.compare("1"))
	{
		name = "Bubble Sort (Recursive)";
		bubbleSortRecursive(testVector, testVector.size());
	}
	else if (!input.compare("2"))
	{
		name = "Selection Sort (Recursive)";
		selectionSortRecursive(testVector, 0);
	}
	else if (!input.compare("3"))
	{
		name = "Merge Sort";
		mergeSort(testVector, 0, testVector.size() - 1);
	}
	else if (!input.compare("4"))
	{
		name = "Insert Sort";
		insertSort(testVector);
	}
	else if (!input.compare("5"))
	{
		name = "Insert Sort (With binary search)";
		insertSortBinary(testVector);
	}
	else if (!input.compare("6"))
	{
		name = "Quick Sort";
		quicksort(testVector, 0, testVector.size() - 1);
	}
	else if (!input.compare("7"))
	{
		name = "Heap Sort";
	heapSort(testVector);
	}
	else
		cout << "Wrong input, try again" << endl;

	t = clock() - t;

	if (printsEnabled)
	{
		cout << endl << "---Sorted vector:" << endl;
		printIntVector(testVector);
	}

	cout << endl << "-Algorithm tested: " << name << endl;
	cout << "-Size of input: " << testVector.size() << endl;
	cout << "-Time elapsed (CPU time): " <<  t*1.0 / CLOCKS_PER_SEC << " seconds!" <<  endl;
	if (printsEnabled)
		cout << "(Time to complete prints is not added on time elapsed)" << endl;
	
	cout << endl;

	return 0;
}