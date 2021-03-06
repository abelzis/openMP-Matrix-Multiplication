//2018-11

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include <omp.h>
using namespace std;


//placing matrixes into heap, in order to allocate a larger amount than the stack offers
const int k = 2000, n = 2000, p = 2000;
int matrix1[n][k] = { 0 }, matrix2[k][p] = { 0 }, matrix3[n][p] = { 0 }; //define matrixes


int main()
{
	int nthreads, tid, chunk = 4; //variables to be used by OpenMP functions
	double dif; //variable to calculate the time difference between the parallelization

	double start = omp_get_wtime(); //start the timer
	srand(time(NULL));
	omp_set_num_threads(2);


	//place to define constants and variables



	int i, j, z, x; //define variables


	//printin matrix sizes
	printf("Matrix1 size: %dx%d\n", n, k);
	printf("Matrix2 size: %dx%d\n", k, p);
	printf("Matrix3 size: %dx%d\n\n", n, p);


	/*** Spawn a parallel region explicitly scoping all variables ***/

#pragma omp parallel shared(matrix1,matrix2,matrix3,nthreads,chunk) private(tid, i, j, z, x)	//create paralell availability


	{
		//basic instruction set
		x = 10;	//setting the maximum value of matrix A values
		tid = omp_get_thread_num();
		if (tid == 0)
		{
			nthreads = omp_get_num_threads();
			printf("Starting matrix multiple example with %d threads\n", nthreads);
		}

		//actions with matrix1
#pragma omp for schedule (static, chunk)	//multiple cores
		for (i = 0; i<n; i++) {
			for (j = 0; j<k; j++) {
				//generating random number to matrix1 from 1 to x
				matrix1[i][j] = 1 + rand() % x;
			}
		}
		


	// actions with matrix2
#pragma omp single	//use single core to generate matrix2
		for (i = 0; i < k; i++) {
			for (j = 0; j < p; j++) {
				//generating randomly 1 or -1 to matrix2
				int temp = rand() % 2;
				if (temp == 0)
					matrix2[i][j] = 1;
				else
					matrix2[i][j] = -1;
			}
		}


		//matrix multiplication
#pragma omp for schedule (static, chunk)	//multiple cores

		for (i = 0; i < n; i++) {
			for (j = 0; j < p; j++) {
				int sum = 0;
				//calculating the sum of multiplication products
				for (z = 0; z < k; z++) {
					sum = sum + matrix1[i][z] * matrix2[z][j];
				}
				matrix3[i][j] = sum; //assigning value to matrix position
			}
		}
	}
	/*****end of parallel region*****/

	//print results
	double end = omp_get_wtime(); //end the timer
	dif = end - start; //store the difference

	////print matrix1
	//printf("\n\nMatrix1:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < k; j++)
	//	{
	//		printf("%d", matrix1[i][j]);
	//		printf(" ");
	//	}
	//	printf(" \n");
	//}

	////print matrix2
	//printf("\n\nMatrix2:\n");
	//for (int i = 0; i < k; i++)
	//{
	//	for (int j = 0; j < p; j++)
	//	{
	//		printf("%d", matrix2[i][j]);
	//		printf(" ");
	//	}
	//	printf(" \n");
	//}

	////print matrix3
	//printf("\n\nMatrix3:\n");
	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < p; j++)
	//	{
	//		printf("%d", matrix3[i][j]);
	//		printf(" ");
	//	}
	//	printf(" \n");
	//}


	printf("Parallelization took %f sec. time.\n", dif);
	printf("******************************************************\n");

	system("pause");
	return 0;
}