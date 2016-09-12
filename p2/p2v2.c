#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUE 4000000
#define INITIAL_ARRAY_SIZE 200

typedef struct {
	int *array;
	size_t used;
	size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
	a -> array = malloc(initialSize * sizeof(int));
	a -> used = 0;
	a -> size = initialSize;
}

void setAtIndex(Array *a, int index, int value) {
	if (index <= (a -> used)) {
		a -> array[index] = value;
	} else {
		printf("Unable to set index %d of expandable array to value %d;"
		" the specified index exceeded the size (%d).", index, value, a -> size);
	}
}

void addToArray(Array *a, int value) {
	if (a -> used == a -> size) {
		// expand the array by doubling its capacity
		a -> size *= 2;
		a -> array = realloc(a -> array, a -> size * sizeof(int));
	}
	a -> array[a -> used++] = value;
}

void freeArray(Array *a) {
	free(a -> array);
	a -> array = NULL;
	a -> used = a -> size = 0;
}

int fibonacci(int n) {
	static Array cache;
	static int arrayInitialized = 0;
	if (arrayInitialized == 0) {
		printf("Initializing expandable array...\n");
		initArray(&cache, INITIAL_ARRAY_SIZE);
		addToArray(&cache, 1);
		addToArray(&cache, 1);
		arrayInitialized = 1;
		printf("...expandable array initialized successfully.\n");
	}
	if (n >= cache.used) {
		// calculate this Fibonacci number and add it to the cache
		int fib = fibonacci(n - 2) + fibonacci(n - 1);
		addToArray(&cache, fib);
	}
	return cache.array[n];
}

int main(int argc, char *argv[]) {
	int sum = 0;
	int n = 2;
	int fib = fibonacci(n);
	while (fib < MAX_VALUE) {
		printf("Adding number with index %d and value %d to running sum %d.\n", n, fib, sum);
		sum += fib;
		n += 3;
		fib = fibonacci(n);
	}
	printf("\nFinal sum: %d\n", sum);
}
