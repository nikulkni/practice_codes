#include<iostream>
#include<fstream>
#include <stdlib.h>
#include<stdio.h>
#include<strings.h>
#include<float.h>
#include "quicksort.h"
#include "limits.h"

using namespace std;

struct arrayVal{
	int value;
	struct arrayVal *next;
};

int * readArrayFromFile(char *filename){
	struct arrayVal head;
	struct arrayVal *prev = &head;
	int size = 0;
	int *array;

	ifstream myReadFile;
	myReadFile.open("inputFile.txt");
	char output[100];
	struct arrayVal *newVal;

	if(myReadFile.is_open()){
		if (!myReadFile.eof()) {
			do{
				size++;
				bzero(output, 100);
				myReadFile >> output;
				newVal = (arrayVal *)malloc(sizeof(arrayVal));

				newVal->value = atoi(output);

				prev->next = newVal;
				//cout<<prev->value<<endl;
				prev = prev->next;
			}while(!myReadFile.eof());

			prev = head.next;

			while(prev){
				cout<<prev->value<<endl;
				prev = prev->next;
			}

			array = (int *)malloc(sizeof(int) * size);
			int i=0;

		}
	}else{
		cout<<"Couldn't open the file: "<< filename;
	}

	myReadFile.close();

	return array;
}

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

//	int *array;
readArrayFromFile(NULL);

//	for (size = 1; size <= 1000; size++) {
//		array = (double *) malloc(sizeof(double) * size);
//		if (array != NULL) {
//			srand(time(NULL));
//			for (i = 0; i < size; i++) {
//				array[i] = rand() % time(NULL);
//			}
//
//			quick_sort(array, size);
//
//			testArrayAscending(array, size);
//			printArray(array, size);
//			cout<<endl;
//		}
//
//		free(array);
//	}

//	for (i = 0; i < size; i++) {
//		cout << array[i] << " ";
//	}

	return 0;
}
