#ifndef InsertionSort
#define InsertionSort

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void insertionSort(vector<int>& arr, long& comparisons);
vector<int> loadDataFile(const string& filename);

void printData(const vector<int>& data);

void task3UserTest();
void task3ScatterData();
#endif