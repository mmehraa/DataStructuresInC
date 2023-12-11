#include <stdio.h>
#define MAX 20

void input(int*, int);
void output(int*, int);
int insertElement(int*, int, int, int);

int main() {
    int arr[MAX];
    int length, position, item; 

    printf("Enter Number of Elements for the Array : ");
    scanf("%d", &length);

    printf("Enter Array Elements : ");
    input(arr, length);
    printf("\nEntered Element : ");
    output(arr, length);

    printf("\nEnter Element to be inserted : ");
    scanf("%d", &item);
    printf("Enter Position of insertion : ");
    scanf("%d", &position);
    length = insertElement(arr, length, position, item);

    printf("\nArray after Insertion is : ");
    output(arr, length);

    return 0;
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

int insertElement(int* arr, int length, int position, int item) {
    for (int i = length - 1; i >= position - 1; i--){
        arr[i + 1] = arr[i];
    }
    arr[position - 1] = item;
    length++;
    return length;
}
