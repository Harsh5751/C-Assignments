#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "a4.h"

int cmpfunc(const void * a, const void * b) {
	return ((*(Individual *)a).fitness - (*(Individual*)b).fitness);
}

PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate) {
	srand(time(NULL));
	Individual *population = generate_population(population_size, image->width, image->height, image->max_color);

	comp_fitness_population(image->data, population, population_size);

	qsort(population, population_size, sizeof(Individual), cmpfunc);

	for (int i = 1; i <= num_generations; i++) {
		printf("GENERATION %d:\n", i);
		crossover(population, population_size);
		mutate_population(population, population_size - 1, rate);
		comp_fitness_population(image->data, population, population_size);
		qsort(population, population_size, sizeof(Individual), cmpfunc);
	}


	PPM_IMAGE * image1 = (PPM_IMAGE*)malloc(sizeof(PPM_IMAGE));
	image1->width = (population)->image.width;
	image1->height = (population)->image.height;
	image1->data = (population)->image.data;
	image1->max_color = (population)->image.max_color;

	for (int j = 1; j < population_size; j++) {
		free((population + j)->image.data);
	}
	free(population); 

	return image1;
}

void free_image(PPM_IMAGE *p) {
	free(p->data);
	p->data = NULL;
	p->width = 0;
	p->height = 0;
	free(p); 
}
