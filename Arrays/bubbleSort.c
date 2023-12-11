#include <stdio.h>
#include <stdbool.h>
#define MAX 20

void input(int*, int);
void output(int*, int);
void bubbleSort(int*, int);

int main(){
        int arr[MAX];
        int length; 

        printf("Enter Number of Elements for the Array : ");
        scanf("%d", &length);

        printf("Enter Array Elements : ");
        input(arr, length);
        printf("\nEntered Element : ");
        output(arr, length);

        printf("\nArray after Bubble Sort implementation : ");
        bubbleSort(arr, length);
        output(arr, length);
}

void input(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

void output(int* arr, int length) {
    for (int i = 0; i < length; i++){
        printf("%d ", *(arr + i));
    }
}

void bubbleSort(int* arr, int length){
        bool swapped;
        for(int i = 0; i < length; i++){
                swapped = false;
                for (int j = 1; j < length; j++){
                        if (arr[j] < arr[j -1]){
                                int temp = arr[j];
                                arr[j] = arr[j - 1];
                                arr[j - 1] = temp;
                                swapped = true;
                        }
                }
                if (!swapped){
                        break;
                }
        }
}