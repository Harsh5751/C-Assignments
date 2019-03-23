#include <stdio.h>
int main()
{
	int i, n;
	int term1 = 0;
	int term2 = 1;
	int nextTerm = 0;

	printf("Enter a positive integer: ");
	scanf("%d", &n);
	printf("\n");
	printf("Fibonacci Sequence up to %d: \n", n);
	printf("%d, ", term2);

	int counter2 = 0, counter3 = 0, counter5 = 0, counter6 = 0, counter10 = 0, counter15 = 0, notDivisible = 1;

	while (n > nextTerm)
	{
		nextTerm = term1 + term2;
		if (nextTerm <= n) {
			printf("%d, ", nextTerm);

			if (nextTerm % 2 == 0) {
				counter2 += 1;
			}
			if (nextTerm % 3 == 0) {
				counter3 += 1;
			}
			if (nextTerm % 5 == 0) {
				counter5 += 1;
			}
			if (nextTerm % 6 == 0) {
				counter6 += 1;
			}
			if (nextTerm % 10 == 0) {
				counter10 += 1;
			}
			if (nextTerm % 15 == 0) {
				counter15 += 1;
			}
			if (nextTerm % 2 != 0 && nextTerm % 3 != 0 && nextTerm % 5 != 0 && nextTerm % 6 != 0 && nextTerm % 10 != 0 && nextTerm % 15 != 0) {
				notDivisible += 1;
			}
		}

		term1 = term2;
		term2 = nextTerm;
	}

	printf("\n");
	printf("\n");
	printf("divisible by:\n");
	printf("2\t\t%d\n", counter2);
	printf("3\t\t%d\n", counter3);
	printf("5\t\t%d\n", counter5);
	printf("6\t\t%d\n", counter6);
	printf("10\t\t%d\n", counter10);
	printf("15\t\t%d\n", counter15);
	printf("-\t\t%d\n", notDivisible);

	return 0;
}