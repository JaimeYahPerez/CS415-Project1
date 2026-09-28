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
		
		cout << "0: Exit\n1: Fib\n2:Task 3 - Selection\n3: Task 3 - Scatter Selection\n";
		cin >> choice;

		switch (choice) {
			case 0:
				loop = false;
				break;
			case 1: 
			//fibTest();
			fibandeuclid();
			break;
			case 2: 
			task3UserTest();
			break;
			case 3:
			task3ScatterData();
			break;

			/*cout << "Enter a value for k: ";
			for (int i = 0; i < 11; i++) {
				auto result = Fib(i, c);
				cout << "Result of Fib(" << i << ") = " << result << "\n";
				cout << "total basic ops: " << c << "\n";
			}
			
			case 2:
			int e = Euclid (60, 24, c);
			cout << "Result of Euclid: " << e << "\n";*/
		}
	}
	
}