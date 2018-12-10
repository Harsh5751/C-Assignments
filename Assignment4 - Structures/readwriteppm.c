#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <math.h>
#include "a4.h"

PPM_IMAGE *read_ppm(const char *file_name) {
	//assign to pointer 
	PPM_IMAGE * image;
	FILE * image_file;
	char skip[80];

	//open file in read mode
	image_file = fopen(file_name, "r");

	image = (PPM_IMAGE *)malloc(sizeof(PPM_IMAGE));
	// read P
	fscanf(image_file, "%c", skip);
	// read 3
	fscanf(image_file, "%c", skip);

	//read height, width, max color, and Pixels
	fscanf(image_file, "%d %d", &(image->width), &(image->height));
	fscanf(image_file, "%d", &(image->max_color));
	image->data = (PIXEL*)malloc(image->height * image->width * sizeof(PIXEL));
	
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			fscanf(image_file, "%hhu %hhu %hhu ", &((image->data + image->width*i + j)->r), &((image->data + image->width*i + j)->g), &((image->data + image->width*i + j)->b));
		}
	}

	//close the file
	fclose(image_file);
	return image;
}

void write_ppm(const char *file_name, const PPM_IMAGE *image) {
	FILE * image_file;
	image_file = fopen(file_name, "w");

	fprintf(image_file, "P3\n");
	fprintf(image_file, "%d %d\n", image->width, image->height);
	fprintf(image_file, "%d\n", image->max_color);
	for (int i = 0; i < image->height; i++) {
		for (int j = 0; j < image->width; j++) {
			fprintf(image_file, "%hhu %hhu %hhu ", (image->data + image->width*i + j)->r, (image->data + image->width*i + j)->g, (image->data + image->width*i + j)->b);
		}
	}

	fclose(image_file);
}
