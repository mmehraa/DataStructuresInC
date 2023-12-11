#include <stdio.h>

void input(int*, int);
void output(int*, int);
void mergeArray(int*, int*, int*, int, int);

int main(){

    int length1;
    printf("Enter Length of first Sorted Array : ");
    scanf("%d", &length1);
    int arr1[length1];
    printf("Enter Sorted Array 1 Elements : ");
    input(arr1, length1);

    int length2;
    printf("Enter Length of second Sorted Array : ");
    scanf("%d", &length2);
    int arr2[length2];
    printf("Enter Sorted Array 2 Elements : ");
    input(arr2, length2);

    int length3 = length1 + length2;
    int arr3[length3];

    mergeArray(arr1, arr2, arr3, length1, length2);
    printf("Merged Array : ");
    output(arr3, length3);

    return 0;
}

void input(int* arr, int length){
    for(int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

void output(int* arr, int length){
    for (int i = 0; i < length; i++){
        printf("%d ", *(arr + i));
    }
}

void mergeArray(int* arr1, int* arr2, int* arr3, int length1, int length2){
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < length1 && j < length2) {
        if (arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            i++;
        } else {
            arr3[k] = arr2[j];
            j++;
        }
        k++;
    }

    if (i == length1) {
        while (j < length2) {
            arr3[k] == arr2[j];
            j++;
            k++;
        }
    }
    else if (j == length2){
        while (i < length1){
            arr3[k] = arr1[i];
            i++;
            k++;
        }
    }
}
