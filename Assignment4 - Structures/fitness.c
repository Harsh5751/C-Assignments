#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size) {
	double sum = 0;
	double dist1;
	for (int i = 0; image_size > i; i++) {
		dist1 = pow((A[i].r - B[i].r), 2) + pow((A[i].g - B[i].g), 2) + pow((A[i].b - B[i].b), 2);
		sum += dist1;
	}
	double distance = sqrt(sum);
	return distance;
}

void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size) {
	for (int i = 0; i < population_size; i++) {
		(individual + i)->fitness = comp_distance(image, individual[i].image.data, individual[i].image.height * individual[i].image.width);
		printf("Fitness %d: %lf\n", i, (individual + i)->fitness);
	}
}