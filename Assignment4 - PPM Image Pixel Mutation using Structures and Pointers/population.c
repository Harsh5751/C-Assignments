#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"


PIXEL *generate_random_image(int width, int height, int max_color) {
	PIXEL * data = (PIXEL*)malloc(width*height * sizeof(PIXEL));
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			(data + width*i + j)->r = rand() % (max_color);
			(data + width*i + j)->g = rand() % (max_color);
			(data + width*i + j)->b = rand() % (max_color);
		}
	}
	return data;
}

Individual *generate_population(int population_size, int width, int height, int max_color) {
	
	Individual * individual = (Individual*)malloc(population_size*sizeof(Individual));
	for (int i = 0; i < population_size; i++) {
		(individual[i]).image.width = width;
		(individual[i]).image.height = height;
		(individual[i]).image.max_color = max_color;
		(individual[i]).image.data = generate_random_image(width, height, max_color);
	}
	return individual;
}
