#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 4000000
#define ARRAY_SIZE 500

int fibonacci(int n) {
	static int fibonacci[ARRAY_SIZE] = { 0 };
	if (n == 0) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else if (n < sizeof(fibonacci)/sizeof(fibonacci[0])
		&& fibonacci[n] == 0) {
			fibonacci[n] = fibonacci(n - 2) + fibonacci(n - 1);
	} else {
		return -1;
		// n exceeds the capacity of the array; create a new array
		// int prev2 = (fibonacci[n - 2] == 0) ? fibonacci(n - 2) : fibonacci[n - 2];
		// int prev1 = (fibonacci[n - 1] == 0) ? fibonacci(n - 1) : fibonacci[n - 1];
		// fibonacci = (int *)ralloc(ARRAY_SIZE * sizeof(int));
		// fibonacci[n - 1] = prev1;
		// fibonacci[n] = prev2 + prev1;
	}
	return fibonacci[n];
}

// calculate the sum of even-valued (every three) Fibonnaci	numbers below 4,000,000.
int main(int args, char *argv[]) {
	int sum = 0;
	// begin at index 2, the first even Fibonacci number (2)
	int fibIdx = 2;
	int fib = fibonacci(fibIdx);
	while (fib < MAX_VALUE) {
		if (fib < 0) {
			printf("ARRAY_SIZE (%d) exceeded.", ARRAY_SIZE);
		}
		sum += fib;
		// increment index by 3, since every three Fibonacci numbers is even.
		fibIdx += 3;
	}
	printf("Sum of even-valued Fibonacci numbers below %d: %d", MAX_VALUE, sum);
}
