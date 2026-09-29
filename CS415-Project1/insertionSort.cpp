#include "InsertionSort.hpp"
#include "selectionsort.h"

void insertionSort(vector<int>& arr, long& comparisons){
    int n = arr.size();

    for (int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0){
            comparisons++;

            if (arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            else
            {
                break;
            }
        }

        arr[j + 1] = key;
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

    cout << "\nInsertion Sort - User Testing Mode\n";
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

    vector<int> insertionData = original;

    long insertionCount = 0;

    insertionSort(insertionData, insertionCount);

    cout << "\nInsertion Sort:\n";
    printData(insertionData);
    cout << "Comparisons: " << insertionCount << '\n';

}

static void generateCaseCSV(const string& outputFilename, const string& inputSuffix) {
    ofstream output(outputFilename);

    if (!output) {
        cerr << "Could not create " << outputFilename << '\n';

        return;
    }

    output << "impl,N,ops_total\n";

    // Selection Sort
    for (int n = 100; n <= 10000; n += 100) {
        string filename = "data/testSet/data" + to_string(n) + inputSuffix + ".txt";

        vector<int> original = loadDataFile(filename);

        if (original.empty()) {
            continue;
        }

        vector<int> selectionData = original;

        long selectionCount = 0;

        selectionSort(selectionData, selectionCount);

        output << "selection_sort," << n << "," << selectionCount << '\n';
    }

    // Insertion Sort 

    for (int n = 100; n <= 10000; n += 100) {
        string filename = "data/testSet/data" + to_string(n) + inputSuffix + ".txt";

        vector<int> original = loadDataFile(filename);

        if (original.empty()) {
            continue;
        }

        vector<int> insertionData = original;

        long insertionCount = 0;

        insertionSort(insertionData, insertionCount);

        output << "insertion_sort," << n << "," << insertionCount << '\n';
    }




}
void task3ScatterData(){
    generateCaseCSV("csv/Insertion_best.csv", "_sorted");

    generateCaseCSV("csv/Insertion_average.csv", "");

    generateCaseCSV( "csv/Insertion_worst.csv", "_rSorted");

    cout << "Task 3 scatter plot data generated.\n";
}
void task3AlgoSortingUT() {

    int n;

    cout << "\nSelection Sort - User Testing Mode\n";
    cout << "Enter list size "
        "(10 to 100 in increments of 10): ";

    cin >> n;

    if (n < 10 || n > 100 || n % 10 != 0) {
        cout << "Invalid list size.\n";
        return;
    }

    string filename = "data/smallSet/data" + to_string(n) + ".txt";

    vector<int> original = loadDataFile(filename);

    if (original.empty()) {
        return;
    }

    vector<int> selectionData = original;
    long selectionCount = 0;
    selectionSort(selectionData, selectionCount);

    vector<int> insertionData = original;
    long insertionCount = 0;
    insertionSort(insertionData, insertionCount);

    cout << "\nSelection Sort:\n";
    printData(selectionData);
    cout << "Comparisons: " << selectionCount << '\n';

    cout << "\nInsertion Sort:\n";
    printData(insertionData);
    cout << "Comparisons: " << insertionCount << '\n';
}