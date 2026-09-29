#ifndef FIB_H_
#define FIB_H_

#include <iostream>
#include <chrono>
using namespace std;


long long Fib_1(int k, long long &count) {
    
    if (k <= 1) {
        return k; 
    }
    
    count++;
    long long f = Fib_1(k - 1, count) + Fib_1(k - 2, count);   
    return f;
}


long long Fib(int k, long long &count, vector<int> &results) {
    
    if (k <= 1) {
        results[k] = k;
        return k; 
    }
    
    count++;
    long long f = Fib(k - 1, count, results) + Fib (k - 2, count, results);   
    results[k] = f;
    return f;
}

long long Fib(int k, vector<int> &results) {
    
    if (k <= 1) {
        results[k] = k;
        return k; 
    }
    
    long long f = Fib(k - 1, results) + Fib (k - 2, results);   
    results[k] = f;
    return f;
}






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

int Euclid(long long m, long long n, int &count) {
    if (n == 0) {
        return m;
    }

    int r = m % n;
    m = n;
    n = r;
    
    count++;
    return Euclid(m, n, count); 
}

void task1user() {

    int k;
    
    cout << "Please enter a value for k: ";
    cin >> k;

    std::vector<int> t(k + 2); // # of indices = k + 2

    cout << "\n";
    Fib(k+1, t);

    cout << "Fib(" << k << "): " << t.at(k) << "\n";

    long long m = t.at(k+1);
    long long n = t.at(k);

    int c = 0;
    int result = Euclid(m, n, c);

    cout << "Euclid(" << m << "," << n << "): " << result << "\n";

    
}

static void fibEuclidCSV(const string& outputFilename){
    ofstream output(outputFilename);

    if (!output){
        cerr << "Could not create " << outputFilename << '\n';

        return;
    }

    int k = 46;
    std::vector<int> t(k + 2);
    Fib(k+1, t);    
    cout << "Euclid Vector completed!\n";


    output << "impl,N,ops_total\n";
    //long long count = 0;
    //Fib_1(16, count);

    //output << "fib,16" << "," << count << "\n";
    
    for (int k = 16; k <= 40; k += 2) {

        long long count = 0;

        //std::vector<int> t(k);
        Fib_1(k, count);

        output << "fib," << k << "," << count << "\n";
    }

    int start = 16;

    long long m = t.at(start+1);
    long long n = t.at(start);
    int c = 0;
    for (int i = start; i <= k; i += 2) {
        m = t.at(i+1);
        n = t.at(i);
        c = 0;
        Euclid(m, n, c);
        
        output << "euclid_wc," << i + 1 << "," << c <<  "\n";
    }
    

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
    }


void task1ScatterData() {

    fibEuclidCSV("csv/Fib.csv");

    cout << "Task 1 scatter plot data created\n";

}
#endif 