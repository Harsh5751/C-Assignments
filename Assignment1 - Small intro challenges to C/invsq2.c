#include <stdio.h>
#include <math.h>

int main(void) {

	int a;
	double nextTerm;

	printf("Enter a:");
	scanf("%d", &a);

	double x0 = (double)(2) / (double)(1 + a);
	double maxError = 1 * pow(10, -13);
	double relativeError = 1;

	while (relativeError >= maxError) {
			nextTerm = x0 * (1.5 - (0.5 * a * (x0 * x0)));
			relativeError = fabs(nextTerm - (1 / sqrt(a)))*sqrt(a);
			printf(" %.15e  %.2e\n", nextTerm, relativeError);
			x0 = nextTerm;
		}

	return 0;

	} 

	
