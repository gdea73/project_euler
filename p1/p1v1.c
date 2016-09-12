#include <stdio.h>

int main(int argc, char *argv[]) {
	int sum = 0;
	int threes = 0;
	while (threes < 1000) {
		sum += threes;
		threes += 3;
	}
	int fives = 0;
	while (fives < 1000) {
		sum += fives;
		fives += 5;
	}
	int fifteens = 0;
	while (fifteens < 1000) {
		sum -= fifteens;
		fifteens += 15;
	}
	printf("Sum of all numbers divisible by three or five less than 1,000: %d\n", sum);
}
