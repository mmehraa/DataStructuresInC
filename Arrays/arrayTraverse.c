#include <stdio.h>
#define MAX 20

void input(int*, int);
void display(int*, int);

int main(){
    int arr[MAX];
    int length;

    printf("Enter Array Length : ");
    scanf("%d", &length);

    printf("\nEnter Array Elements : ");
    input(arr, length);

    printf("\nTraversed Array : ");
    display(arr, length);

    return 0;
}

void input(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

void display(int* arr, int length) {
    for (int i = 0; i < length; i++){
        printf("%d ", *(arr + i));
    }
}