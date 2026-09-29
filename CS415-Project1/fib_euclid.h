#ifndef FIB_H_
#define FIB_H_

#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <string>
using namespace std;


long long Fib_1(int k, long long& count);


long long Fib(int k, long long& count, vector<int>& results);

long long Fib(int k, vector<int>& results);






/*
void fibTest() {

    int k;
    long long count = 0;

    cout << "Please enter a value for k: ";
    cin >> k;  
    cout << "\n";

    auto start = chrono::steady_clock::now();
    long long result = Fib_1(k, count);
    auto end = chrono::steady_clock::now();

    auto elapsed = chrono::duration_cast<chrono::milliseconds>(end - start);

    cout << "Fib(" << k << "): " << result << "\n# of Addition Operations: " << count << "\n";
    cout << "Time elapsed: " << elapsed.count() << "ms.\n";

    // formatted like the csv file: impl,N,elapsed_ms,ops_total 
    //TODO: SET UP USER AND REPORT MODES//
    
    cout << "fib," << k << "," << elapsed.count() << "," << count;
    cout << "\n";


}
*/
/*
int Euclid(int m, int n, int &count) {
    if (n == 0) {
        return m;
    }

    int r = m % n;
    m = n;
    n = r;
    
    count++;
    return Euclid(m, n, count); 
}
*/

int Euclid(long long m, long long n, int& count);

void task1user();

static void fibEuclidCSV(const string& outputFilename);
    

    //Euclid(m, n, c);
    //output << "euclid_wc," << start + 1 << "," << c <<  "\n";



    
    /*
    for (int n = 16; n <= 50; n += 2) {
        //string filename = "data/testSet/data" + to_string(n) + inputSuffix + ".txt";

        //vector<int> original = loadDataFile(filename);

        if (original.empty()) {
            continue;
        }

        vector<int> selectionData = original;

        long selectionCount = 0;

        selectionSort(selectionData, selectionCount);

        output << "selection_sort," << n << "," << selectionCount << '\n';
        */
    


void task1ScatterData();
#endif 