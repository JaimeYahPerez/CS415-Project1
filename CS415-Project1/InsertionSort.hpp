#ifndef InsertionSort
#define InsertionSort

#include <fstream>
#include <vector>
#include <string>
#include <iostream>

void insertionSort(std::vector<int>& arr, long& comparisons);
std::vector<int> loadDataFile(const std::string& filename);

void printData(const std::vector<int>& data);

void task3UserTest();
void task3ScatterData();
#endif