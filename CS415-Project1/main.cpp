#include <fstream>
#include <iostream>
#include <vector>
#include "fib_euclid.h"
#include "selectionsort.h"




using namespace std;
int main() {
	
	bool loop = true;
	int choice;

	while (loop) {
		
		cout << "0: Exit\n1: Fib\n2: Fib-Euclid Scatterplot Data\n3:Selection Sort\n4:SelectSort SP Data\n";
		cin >> choice;

		switch (choice) {
			case 0:
			loop = false;
			break;
			case 1: 
			task1user();
			break;
			case 2:
			task1ScatterData();
			break;
			case 3: 
			task3SelecSortUserTest();
			break;
			case 4:
			task3ScatterData();
			break;

			
		}
	}
	
}