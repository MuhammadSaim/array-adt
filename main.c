#include <stdio.h>
#include <stdlib.h>


// struct
struct Array{
	int *A;
	int size;
	int length;
};

int main() {
	
	
	struct Array arr;
	int size;
	char c;
	printf("Enter a size of an Array: ");
	scanf("%d", &size);
	arr.A = (int *)malloc(size * sizeof(int));
	arr.size = size;
	arr.length = 0;
//	test();
	
	while(1){
		system("cls");
		printf("Append into Array => A\n");
		printf("Display the records => D\n");
		printf("Insert into Array => I\n");
		printf("Delete into Array => E\n");
		printf("Update into Array => U\n");
		printf("Reverse an Array => R\n");
		printf("Sort an Array Bubble Sort => B\n");
		printf("Linera Search in array => L\n");
		printf("Exit to program   => X\n");
		c = getch();
		if(c == 'a' || c == 'A'){
			append(&arr);
		}else if (c == 'd' || c == 'D'){
			display(arr);
		}else if (c == 'i' || c == 'I'){
			insertAt(&arr);
		}else if (c == 'e' || c == 'E'){
			deleteAt(&arr);
		}else if (c == 'u' || c == 'U'){
			updateAt(&arr);
		}else if (c == 'r' || c == 'R'){
			reverse(&arr);
		}else if (c == 'b' || c == 'B'){
			bubbleSort(&arr);
		}else if (c == 'l' || c == 'L'){
			linearSearch(&arr);
		}else if(c == 'X' || c == 'x'){
			break;
		}else{
			continue;
		}
	}
	
	
	return 0;
}


// append into ADT
void append(struct Array *arr){
	system("cls");
	int val;
	if(arr->length >= arr->size){
		printf("Array is full\n");
		return;
	}
	printf("Enter a Number to insert: ");
	scanf("%d", &val);
	arr->A[arr->length] = val;
	arr->length++; 
}


// display ADT
void display(struct Array arr){
	system("cls");
	if(arr.length == 0){
		printf("No data found\n");
		getch();
		return;
	}
	int i;
	for(i = 0; i<arr.length; i++){
		printf("%d\t", arr.A[i]);
	}
	getch();
}


// insert at
void insertAt(struct Array *arr){
	system("cls");
	int i, index, val;
	printf("Enter an index to insart at: ");
	scanf("%d", &index);
	if(index >= 0 && index <= arr->length){
		printf("Enter a value to insert: ");
		scanf("%d", &val);
		for(i=arr->length; i>index; i--)
			arr->A[i] = arr->A[i-1];
		arr->A[index] = val;
		arr->length++;
		return;
	}else{
		system("cls");
		printf("This is an invalid index.");
		getch();
		return;	
	}
}


// deleted at
void deleteAt(struct Array *arr){
	system("cls");
	int i, index;
	printf("Enter index to delete: ");
	scanf("%d", &index);
	if(index < arr->length){
		for(i=index; i < arr->length; i++){
			arr->A[i] = arr->A[i+1];
		}
		arr->length--;
		return;
	}else{
		printf("Invalid index");
		getch();
		return;
	}
	
}

// update at
void updateAt(struct Array *arr){
	system("cls");
	int index, val;
	printf("Enter index to update: ");
	scanf("%d", &index);
	if(index < arr->length){
		printf("Enter value to update: ");
		scanf("%d", val);
		arr->A[index] = val;
		return;
	}else{
		printf("Its not a valid index.");
		getch();
		return;
	}
}

// reverse an array
void reverse(struct Array *arr){
	system("cls");
	int i, j, temp;
	for(i=0, j = arr->length - 1; i < j; i++, j--){
		temp = arr->A[i];
		arr->A[i] = arr->A[j];
		arr->A[j] = temp;
	}
	printf("Array is reversed successfully");
	getch();
}


// bubble sort
void bubbleSort(struct Array *arr){
	system("cls");
	int i, j, temp;
	if(arr->length > 0){
		for(i=0; i < arr->length; i++){
			for(j=0; j < arr->length - 1; j++){
				if(arr->A[j] > arr->A[j+1]){
					temp = arr->A[j];
					arr->A[j] = arr->A[j+1];
					arr->A[j+1] = temp;
				}
			}
		}	
		printf("Sorting is done.");
		getch();
	}else{
		printf("Array is empty not able to sort.");
		getch();
	}
}


// linearSearch
void linearSearch(struct Array *arr){
	system("cls");
	int i, val;
	if(arr->length > 0){
		printf("Enter a Value to search: ");
		scanf("%d", &val);
		for(i=0; i<arr->length; i++){
			if(arr->A[i] == val){
				system("cls");
				printf("Element %d is found at index %d", val, i);
				getch();
				return;
			}
		}
		printf("Element %d is not found in the array.");
		getch();
		return;
	}else{
		printf("Array is an empty.");
		getch();
	}
}

// only for test code
void test(){
	int i,j;
	
	for(i=0, j=5; i<5 && j>0; i++, j--){
		printf("i = %d \t j = %d\n", i, j);
	}
}
