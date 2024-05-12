#include "sort.h"
#include "utils.h"
#include <iostream>
using namespace std;

int main()
{
    vector<int> setA = loadSetFromFile("A.txt");
    vector<int> setB = loadSetFromFile("B.txt");

    selectionSort(setA);
    selectionSort(setB);

    removeDuplicates(setA);
    removeDuplicates(setB);

    vector<int> intersection = findIntersection(setA, setB);

    //printSet(intersection);

    saveSetToFile("result.txt", intersection);

	return 0;
}