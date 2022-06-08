#include <stdio.h>
#include <stdlib.h>

struct IntArray {
	int length;
	int *dataPtr;
};

//allocates, initializes, and returns pointer to new struct IntArray
struct IntArray* mallocIntArray(int length) {
	//malloc for instance
	struct IntArray* instance = (struct IntArray*)malloc(sizeof(struct IntArray));
	//point instance to length
	instance->length = length;
	//point instance to dataPtr and malloc for dataPtr
	instance->dataPtr = (int*)malloc(sizeof(int)*length);
	return instance;
}

//frees instance's dataPtr and frees instance
void freeIntArray(struct IntArray *arrayPtr) {
	free(arrayPtr->dataPtr);
	free(arrayPtr);
}

//prompts and reads ints > 0 from the user to fill the array
//prints an error message and prompts again if user enters invalid value
void readIntArray(struct IntArray *array) {
	char buf[60];
	for(int i = 0; i < array->length; i++) {
		//loop till valid input given
		int result;
		for(;;) {
			printf("Enter int: ");
			//get user input
			char* input = fgets(buf, 60, stdin);
			//check user input isn't empty
			if(input == NULL) {
				printf("Invalid input\n");
				continue;
			}
			//create place to hold pointer into input
			char* badData;
			//convert input to int
			result = strtol(input, &badData, 10);
			//if badData is equal to original input, 
			//input is invalid
			if(badData == input){
				printf("Invalid input\n");
				continue;
			}
			//input is valid, leave loop
			break;	
		}
		//fill array with valid input
		array->dataPtr[i] = result;
	}	
}

//swaps int values stored at xp and yp pointers
void swap(int *xp, int *yp) {
	long temp1 = *xp;
	long temp2 = *yp;
	*xp = temp2;
	*yp = temp1;
}

//sorts input array in ascending order using BubbleSort by repeatedly calling swap function as necessary
void sortIntArray(struct IntArray *array) {
	//loop through array indexes
	for(int i = 0; i < array->length; i++) {
		//loop through till length -1
		//biggest value will endup at end of array,
		//therefore, no need to loop until length-1,
		//loop until length-1-i
		for(int j = 0; j < array->length-1-i; j++){
			//swap values if a[j] > a[j+1]
			if(array->dataPtr[j] > array->dataPtr[j+1]) {
				swap(&array->dataPtr[j], &array->dataPtr[j+1]);
			}
		}
	}
}

//prints the array (e.g. "[1, 2, 3, 4]")
void printIntArray(struct IntArray *array) {
	printf("[");
	//print each index with coma, not including last index
	for(int i = 0; i < array->length-1; i++) {
		printf("%d, ", array->dataPtr[i]);
	}
	//print last index with ending bracket
	printf("%d]\n", array->dataPtr[array->length-1]);
}

int main() {
	//prompt for positive int length, printing error meessage if input invalid
	int result;
	char buf[60];
	for(;;) {
		printf("Enter length: ");
		//get user input
		char* input = fgets(buf, 60, stdin);
		//check user input isn't empty
		if(input == NULL) {
			printf("Invalid input\n");
			continue;
		}
		//create place to hold pointer into input
		char* badData;
		//convert input to int
		result = strtol(input, &badData, 10);
		//if badData is equal to original input, 
		//input is invalid
		if(badData == input){
			printf("Invalid input\n");
			continue;
		}
		//input is valid, leave loop
		break;	
	}
	//create array
	struct IntArray* value = mallocIntArray(result);
	//prompt user to fill array
	readIntArray(value);
	//sort array
	sortIntArray(value);
	//print sorted array
	printIntArray(value);
	//free heap memory used by array
	freeIntArray(value);
}
