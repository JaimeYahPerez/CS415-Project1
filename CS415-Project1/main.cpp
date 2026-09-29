#include <iostream>
#include "exponentiation.hpp"
#include "fib_euclid.h"
#include "selectionsort.h"
#include "InsertionSort.hpp" 




using namespace std;
int main() {

	int choice;

	while (1) {

		cout << "0. Exit program\n";
		cout << "1. Fib & Euclid User Mode\n";
		cout << "2. Fib & Euclid SP Data\n";
		cout << "3. Test Exponentiation user mode\n";
		cout << "4. Test Exponentiation scatter data\n";
		cout << "5. Algorithm Sorting user mode\n";
		cout << "6. Generate Algorithm Sort scatter data\n";


		cin >> choice;

		switch (choice) {
		case 0:
			return 0;
			break;

		case 1:
			task1user();
			break;

		case 2:
			task1ScatterData();
			break;

		case 3:
			task2UserTest();

			break;

		case 4:
			generateTask2Data(2, 100);
			break;

		case 5:

			task3AlgoSortingUT();
			break;

		case 6:
			task3ScatterData();
			break;



		}
	}

}