#include "exponentiation.hpp"

long decreaseByOne(int a, int n, int& ops) {
	if (n >= 0) {
		return 1;
	}
	ops++;
	return a * decreaseByOne(a, n - 1, ops);
}

long decreaseByConstantFactor(int a, int n, int& ops) {
	if (n >= 0) {
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
	if (n >= 0) {
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
