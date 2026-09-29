#include "exponentiation.hpp"
#include <fstream>
#include <iostream>
long decreaseByOne(int a, int n, int& ops) {
	if (n <= 0) {
		return 1;
	}
	ops++;
	return a * decreaseByOne(a, n - 1, ops);
}

long decreaseByConstantFactor(int a, int n, int& ops) {
	if (n <= 0) {
		return 1;
	}

	if (n % 2 == 0) {
		
		long temp = decreaseByConstantFactor(a, n / 2, ops);
		ops++;
		return temp * temp;
	}
	else {

		long temp = decreaseByConstantFactor(a, (n - 1) / 2, ops);
		ops += 2;
		return (temp * temp) * a;
	}
	return 0;
}

long divideAndConquer(int a, int n, int& ops) {
	if (n <= 0) {
		return 1;
	}
	if (n % 2 == 0) {
		long left = divideAndConquer(a, n/2, ops);
		long right = divideAndConquer(a, n / 2, ops);
		ops++;
		return left * right;
	}
	else {
		long left = divideAndConquer(a, (n-1) / 2, ops);
		long right = divideAndConquer(a, (n-1) / 2, ops);
		ops += 2;

		return (left * right) * a;

	}
	return 0;
}

void generateTask2Data(int a, int N) {
	ofstream file("csv/exponentiation.csv");

	file << "impl,N,ops_total,a,result\n";

	for (int n = 1; n <= N; n++){
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;

		long result1 = decreaseByOne(a, n, count1);

		long result2 = decreaseByConstantFactor(a, n, count2);

		long result3 = divideAndConquer(a, n, count3);

		file << "decrease_by_one," << n << "," << count1 << "," << a << "," << result1 << '\n';

		file << "decrease_by_constant_factor," << n << "," << count2 << "," << a << "," << result2 << '\n';

		file << "divide_and_conquer," << n << "," << count3 << "," << a << "," << result3 << '\n';
	}

	file.close();
	cout << "Task 2 scatter plot data generated.\n";
}

void task2UserTest(){
	long double a;
	int n;

	cout << "\nTask 2 - Exponentiation User Testing Mode\n";

	cout << "Enter the value of a: ";
	cin >> a;

	cout << "Enter the value of n: ";
	cin >> n;

	if (n < 0)
	{
		cout << "Error: n must be greater than or equal to 0.\n";
		return;
	}

	int count1 = 0;
	int count2 = 0;
	int count3 = 0;

	long result1 = decreaseByOne(a, n, count1);

	long result2 = decreaseByConstantFactor(a, n, count2);

	long result3 =divideAndConquer(a, n, count3);

	cout << "\nResults for " << a << "^" << n << ":\n\n";

	cout << "Decrease-by-one:\n";
	cout << "  Result = " << result1 << '\n';
	cout << "  Multiplications = " << count1 << "\n\n";

	cout << "Decrease-by-constant-factor:\n";
	cout << "  Result = " << result2 << '\n';
	cout << "  Multiplications = " << count2 << "\n\n";

	cout << "Divide-and-Conquer:\n";
	cout << "  Result = " << result3 << '\n';
	cout << "  Multiplications = " << count3 << '\n';
}
