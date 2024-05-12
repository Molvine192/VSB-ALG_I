#include "utils.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

void removeDuplicates(vector<int>& set)
{
    if (set.size() < 2) { return; }

    int i = 1;
    while (i < set.size())
    {
        if (set[i] == set[i - 1])
        {
            set.erase(set.begin() + i);
        }
        i++;
    }
}

vector<int> findIntersection(vector<int>& setA, vector<int>& setB)
{
    vector<int> intersection;
    int i = 0, j = 0;

    while (i < setA.size() && j < setB.size())
    {
        if (setA[i] == setB[j])
        {
            intersection.push_back(setA[i]);
            i++;
            j++;
        }
        else if (setA[i] < setB[j])
        {
            i++;
        }
        else if (setA[i] > setB[j])
        {
            j++;
        }
    }

    return intersection;
}

void printSet(vector<int> set)
{
    cout << "Set: { ";
    for (int elem : set)
    {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

vector<int> loadSetFromFile(string path)
{
    vector<int> set;
    string line;
    ifstream file(path);
    if (!file.is_open())
    {
        cout << "Failed to open file \"" << path << "\"." << endl;
    }
    else
    {
        while (getline(file, line))
        {
            set.push_back(stoi(line));
        }
    }
    file.close();
    return set;
}

void saveSetToFile(string path, vector<int> set)
{
    ofstream result;
    result.open(path);
    if (!result.is_open())
    {
        cout << "Failed to open file \"" << path << "\"." << endl;
    }
    else
    {
        for (int i = 0; i < set.size(); i++)
        {
            result << set[i];
            if (i != (set.size() - 1))
            {
                result << endl;
            }
        }
    }
    result.close();
}