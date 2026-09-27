#include "InsertionSort.hpp"


void insertionSort(std::vector<int>& arr, long& comparisons){
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

std::vector<int> loadDataFile(const std::string& filename){
    std::ifstream file(filename);

    if (!file){
        std::cerr << "Error: could not open " << filename << '\n';

        return {};
    }

    std::vector<int> data;

    int value;

    while (file >> value){
        data.push_back(value);
    }

    return data;
}

void printData(const std::vector<int>& data){
    for (int value : data){
        std::cout << value << ' ';
    }

    std::cout << '\n';
}

void task3UserTest(){
    int n;

    std::cout << "\nInsertion Sort - User Testing Mode\n";
    std::cout << "Enter list size "
        "(10 to 100 in increments of 10): ";

    std::cin >> n;

    if (n < 10 || n > 100 || n % 10 != 0){
        std::cout << "Invalid list size.\n";
        return;
    }

    std::string filename = "data/smallSet/data" + std::to_string(n) + ".txt";

    std::vector<int> original = loadDataFile(filename);

    if (original.empty()){
        return;
    }

    std::vector<int> insertionData = original;

    long insertionCount = 0;

    insertionSort(
        insertionData,
        insertionCount);

    std::cout << "\nInsertion Sort:\n";
    printData(insertionData);
    std::cout << "Comparisons: " << insertionCount << '\n';

}

static void generateCaseCSV(const std::string& outputFilename, const std::string& inputSuffix){
    std::ofstream output(outputFilename);

    if (!output){
        std::cerr << "Could not create " << outputFilename << '\n';

        return;
    }

    output << "impl,N,ops_total\n";

    for (int n = 100; n <= 10000; n += 100) {
        std::string filename = "testSet/data" + std::to_string(n) + inputSuffix + ".txt";

        std::vector<int> original = loadDataFile(filename);

        if (original.empty()) {
            continue;
        }

        std::vector<int> insertionData = original;

        long insertionCount = 0;

        insertionSort( insertionData, insertionCount);

        output << "insertion_sort," << n << "," << insertionCount << '\n';
    }
}
void task3ScatterData(){
    generateCaseCSV("csv/Insertion_best.csv", "_sorted");

    generateCaseCSV("csv/Insertion_average.csv", "");

    generateCaseCSV( "csv/Insertion_worst.csv", "_rSorted");

    std::cout << "Task 3 scatter plot data generated.\n";
}
