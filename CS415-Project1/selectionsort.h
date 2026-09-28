#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <chrono>

using namespace std;



void selectionSort(vector<int> &arr, long& comparisons) {
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {

        // Assume the current position holds
        // the minimum element
        int min_idx = i;

        // Iterate through the unsorted portion
        // to find the actual minimum
        for (int j = i + 1; j < n; ++j) {
            comparisons++;
            if (arr[j] < arr[min_idx]) {

                // Update min_idx if a smaller
                // element is found
                min_idx = j; 
            }
        }

        // Move minimum element to its
        // correct position
        swap(arr[i], arr[min_idx]);
    }
}


vector<int> loadDataFile(const string& filename){
    ifstream file(filename);

    if (!file){
        cerr << "Error: could not open " << filename << '\n';

        return {};
    }

    vector<int> data;

    int value;

    while (file >> value){
        data.push_back(value);
    }

    return data;
}

void printData(const vector<int>& data){
    for (int value : data){
        cout << value << ' ';
    }

    cout << '\n';
}


void task3UserTest(){
    int n;

    cout << "\nSelection Sort - User Testing Mode\n";
    cout << "Enter list size "
        "(10 to 100 in increments of 10): ";

    cin >> n;

    if (n < 10 || n > 100 || n % 10 != 0){
        cout << "Invalid list size.\n";
        return;
    }

    

    string filename = "data/smallSet/data" + to_string(n) + ".txt";

    vector<int> original = loadDataFile(filename);

    if (original.empty()){
        return;
    }

    vector<int> selectionData = original;

    long selectionCount = 0;

    selectionSort(selectionData, selectionCount);

    cout << "\nInsertion Sort:\n";
    printData(selectionData);
    cout << "Comparisons: " << selectionCount << '\n';

}

static void generateCaseCSV(const string& outputFilename, const string& inputSuffix){
    ofstream output(outputFilename);

    if (!output){
        cerr << "Could not create " << outputFilename << '\n';

        return;
    }

    output << "impl,N,ops_total\n";

    for (int n = 100; n <= 10000; n += 100) {
        string filename = "data/testSet/data" + to_string(n) + inputSuffix + ".txt";

        vector<int> original = loadDataFile(filename);

        if (original.empty()) {
            continue;
        }

        vector<int> selectionData = original;

        long selectionCount = 0;

        selectionSort( selectionData, selectionCount);

        output << "selection_sort," << n << "," << selectionCount << '\n';
    }
}
void task3ScatterData(){
    generateCaseCSV("csv/Selection_best.csv", "_sorted");

    generateCaseCSV("csv/Selection_average.csv", "");

    generateCaseCSV( "csv/Selection_worst.csv", "_rSorted");

    cout << "Task 3 scatter plot data generated.\n";
}




void s(int p) {
    p = 2;
    
}


#endif