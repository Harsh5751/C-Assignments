#include <stdio.h>
#include <math.h>

int main(void) {
	int a;
	double x0, nextTerm;
	int n;

	printf("Enter a, x0, and n:");
	scanf("%d%lf%d", &a, &x0, &n);

	for (int i = 1; i <= n; ++i) {
		nextTerm = x0 * (1.5 - (0.5 * a * (x0 * x0)));
		double relativeError = fabs(nextTerm - (1 / sqrt(a)))*sqrt(a);
		printf(" %2d %.15e  %.2e\n", i, nextTerm, relativeError);
		x0 = nextTerm;
	}

	return 0;
}