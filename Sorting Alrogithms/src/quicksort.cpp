#include <iostream>
#include <stdlib.h>

int selectPivotIndex(double *array, int start, int end) {
	return start;
}

/*Used by void quicksort(int *array, int size);
 * ReccursiveFunction
 */
void quicksort(double *array, int start, int end) {

	if (!(start < end)) {
		return;
	}

	int pivotIndex = selectPivotIndex(array, start, end);

	double pivot = array[pivotIndex];
	int low, high;
	double swapTemp;
	low = start;
	high = end;

	while (low < high) {
		while (array[low] < pivot) {
			low++;
		}
		while (array[high] > pivot) {
			high--;
		}
		swapTemp = array[high];
		array[high] = array[low];
		array[low] = swapTemp;
	}
	int positionOfPivot = low; //Or = high;

	quicksort(array, start, positionOfPivot - 1);
	quicksort(array, positionOfPivot + 1, end);

	return;
}

void quick_sort(double *array, int size) {

	quicksort(array, 0, size - 1);

	return;
}
