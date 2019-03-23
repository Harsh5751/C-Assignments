#include <stdio.h>
#include <math.h>

/* https://www.codewithc.com/c-program-for-gauss-elimination-method/ 
- Code was based of the one provided on this website for guassian elimination 
to generate Upper triangular matrix and to do back substitution.
- The Code was changed to operate on a 1-D matrix or Array.
*/

int linsolve(int n, double A[], double b[], double x[]) {

	/* loop for the generation of upper triangular matrix*/
	for (int h = 0; h < n; h++)
	{
		for (int i = 1; i < n; i++)
		{
			if (i > h)
			{
				double elimination = A[n*i + h] / A[n*h + h];
				b[i] = b[i] - elimination * b[h];
				for (int j = 0; j < n; j++)
				{
					A[n*i + j] = A[n*i + j] - elimination * A[n*h + j];
				}
			}
		}
	}
	x[n - 1] = b[n - 1] / A[n*n - 1];

	/*Back Substitution*/
	for (int i = n - 2; i >= 0; i--)
	{
		double element = 0;
		for (int j = i + 1; j < n; j++)
		{
			element = element + A[n*i + j] * x[j];
		}
		x[i] = (b[i] - element) / A[i*n + i];
	}

	/*Calculating the determinant of the New Upper Triangular Matrix A*/
	double determinant = 1;

	for (int d = 0; d < n; d++) {
		determinant *= A[n*d + d];
	}

	/*Determining if A is singular, returning 0, or if A is not Singular, returning 1.*/
	for (int z = 0; z < n; z++) {
		if (x[z] == INFINITY || isnan(x[z]) || determinant == (double)0 || isnan(determinant)){
			return 0;
		}
		else {
			return 1;
		}
	}
	return 0;
}

