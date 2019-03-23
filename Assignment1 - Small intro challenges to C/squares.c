#include <stdio.h>

int main(void) {
	int n;
	printf("Enter number of squares:");
	scanf("%d", &n);
	int numberCount = 5;

	do {
		if (n <= 0 || n > 50) {
			printf("Enter number of squares from 1 to 50:");
			scanf("%d", &n);
		}
	} while (n <= 0 || n > 50);

	if (n <= 4) {
		for (int i = 1; i <= n; ++i) {
			printf("###");
			printf(" ");
		}

		printf("\n");

		for (int j = 1; j <= n; ++j) {
			printf("###");
			printf(" ");
		}

		printf("\n");

		for (int k = 1; k <= n; ++k) {
			printf("###");
			printf(" ");
		}
	}

	while (n != 0 && n >= 5) {
		if (numberCount == 5) {
			for (int i = 1; i <= numberCount; ++i) {
				printf("###");
				printf(" ");
			}

			printf("\n");

			for (int j = 1; j <= numberCount; ++j) {
				printf("###");
				printf(" ");
			}

			printf("\n");

			for (int k = 1; k <= numberCount; ++k) {
				printf("###");
				printf(" ");
			}

			if (n != 5) {
				printf("\n");
				printf("\n");
			}

		}

		n = n - numberCount;

		if (n >= 5) {
			numberCount = 5;
		}

		if (n < 5) {
			numberCount = n;
		}

		if (numberCount < 5) {
			for (int i = 1; i <= numberCount; ++i) {
				printf("###");
				printf(" ");
			}

			if (n > 0) {
				printf("\n");
			}

			for (int j = 1; j <= numberCount; ++j) {
				printf("###");
				printf(" ");
			}

			if (n > 0) {
				printf("\n");
			}

			for (int k = 1; k <= numberCount; ++k) {
				printf("###");
				printf(" ");
			}
		}
	}

	printf("\n");
	return 0;

}