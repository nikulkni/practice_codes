#include<iostream>
#include <stdlib.h>
#include<stdio.h>
#include<float.h>
#include "quicksort.h"
#include "limits.h"

using namespace std;

void printArray(double *array, int size) {
	int i = 0;

	for (i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

void testArrayAscending(double *array, int size) {

	double maxTillNow = array[0];
	int i = 0;

	for (i = 0; i < size; i++) {
		if (maxTillNow > array[i]) {
			cout << "failed for following array:" << endl;
			printArray(array, size);
			return;
		} else {
			maxTillNow = array[i];
		}
	}
}
int main(int argv, char** argc) {

	double *array;

	int i = 0;
	int size = 1;

	for (size = 1; size <= 1000; size++) {
		array = (double *) malloc(sizeof(double) * size);
		if (array != NULL) {
			srand(time(NULL));
			for (i = 0; i < size; i++) {
				array[i] = rand() % time(NULL);
			}

			quick_sort(array, size);

			testArrayAscending(array, size);
			printArray(array, size);
			cout<<endl;
		}

		free(array);
	}

//	for (i = 0; i < size; i++) {
//		cout << array[i] << " ";
//	}

	return 0;
}
