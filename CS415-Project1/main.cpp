#include <iostream>
#include "exponentiation.hpp"
#include "InsertionSort.hpp"
using namespace std;
int main() {
    int choice;
    cout << "Project 1 Test Menu\n\n";
    while (1) {

    cout << "0. Exit program\n";
    cout << "1. Test Exponentiation user mode\n";
    cout << "2. Test Exponentiation scatter data\n";
    cout << "3. Test Insertion Sort user mode\n";
    cout << "4. Generate Insertion Sort scatter data\n";

    cout << "Choice: ";
    cin >> choice;

    
        switch (choice) {
        case 0:
            return 0;
            break;
        case 1:
            task2UserTest();
            break;

        case 2:
            generateTask2Data(2, 100);
            break;

        case 3:
            task3UserTest();
            break;

        case 4:
            task3ScatterData();
            break;

        default:
            cout << "Invalid selection.\n";
            break;
        }
    }
    return 0;
}