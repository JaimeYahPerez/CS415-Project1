#include "exponentiation.hpp"
#include <fstream>
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
	std::ofstream file("data/exponentiation.csv");

	file << "impl,N,ops_total,a,result\n";

	for (int n = 1; n <= N; n++){
		int count1 = 0;
		int count2 = 0;
		int count3 = 0;

		long result1 = decreaseByOne(a, n, count1);

		long result2 = decreaseByConstantFactor(a, n, count2);

		long result3 = divideAndConquer(a, n, count3);

		file << "decrease_by_one,"
			<< n << ","
			<< count1 << ","
			<< a << ","
			<< result1 << '\n';

		file << "decrease_by_constant_factor,"
			<< n << ","
			<< count2 << ","
			<< a << ","
			<< result2 << '\n';

		file << "divide_and_conquer,"
			<< n << ","
			<< count3 << ","
			<< a << ","
			<< result3 << '\n';
	}

	file.close();
}
