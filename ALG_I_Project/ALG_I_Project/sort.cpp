#include "sort.h"
#include <vector>
using namespace std;

void selectionSort(vector<int>& set)
{
    int N = set.size();
    for (int i = 0; i < N - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < N; j++)
        {
            if (set[j] < set[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = set[i];
        set[i] = set[minIndex];
        set[minIndex] = temp;

    }
}