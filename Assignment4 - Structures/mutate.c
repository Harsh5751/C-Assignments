#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "a4.h"

void mutate(Individual *individual, double rate) {
	int n = individual->image.height * (individual->image.width);
	int Range_Pixels = (int)(rate / 100 * n);
	int random_val = 0;
	for (int i = 0; i < Range_Pixels; i++) {
		random_val = rand() % (n + 1);
		individual->image.data[random_val].r = rand() % (255);
		individual->image.data[random_val].g = rand() % (255);
		individual->image.data[random_val].b = rand() % (255);
	}
}

void mutate_population(Individual *individual, int population_size, double rate) {
	int index = population_size/4;
	for (int i = index; i <= population_size; i++) {
		mutate(individual + i, rate);
	}
}