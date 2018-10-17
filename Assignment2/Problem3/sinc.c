#include <stdio.h>
#include <math.h>

double sinc(double x) {
	if (x != 0) {
		double sincx = sin(M_PI * x) / (M_PI * x);
		return sincx;
	}
	else {
		double sincx = 1;
		return sincx;
	}
}

double comph(int N) {
	double h = M_PI / (sqrt(2 * N));
	return h;
}

double comprho(double x, double a, double b) {
	double p = (x - a) / (b - x);
	return p;
}

double complambda(double x, double h, double a, double b, int j) {
	double lambda = sinc((log(comprho(x, a, b)) - j * h) / h);
	return lambda;
}

void wj(double x, double a, double b, int N, double *w) {

	double sum = 0;
	double h = comph(N);

	for (int j = (-N + 1); j <= N; j++) {
		sum += complambda(x, h, a, b, j) / (1 + exp(j*h));
	}

	w[0] = (1 + exp(-N * h))*((1 / (1 + comprho(x, a, b)) - sum));

	int index = 1;

	for (int j = (-N + 1); j <= N - 1; j++) {
		double answer = complambda(x, h, a, b, j);
		w[index] = answer;
		index += 1;
	}

	double sum2 = 0;

	for (int j = (-1 * N); j <= N - 1; j++) {
		sum2 += (exp(j*h) * complambda(x, h, a, b, j)) / (1 + exp(j*h));
	}

	w[2 * N] = (1 + exp(-1 * N*h))*(((comprho(x, a, b)) / (1 + comprho(x, a, b))) - sum2);
}

