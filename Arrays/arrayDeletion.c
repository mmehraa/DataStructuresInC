#include <stdio.h>
#define MAX 20

void input(int*, int);
void output(int*, int);
int deleteElementPosition(int*, int, int);
int deleteElementItem(int*, int, int);

int main() {
    int arr[MAX];
    int length, position, item;

    printf("Enter Length of Array : ");
    scanf("%d", &length);

    printf("\nEnter Array Elements : ");
    input(arr, length);
    printf("\nEntered Array : ");
    output(arr, length);

    // printf("\nEnter position to be deleted : ");
    // scanf("%d", &position);

    printf("\nEnter Item to be deleted : ");
    scanf("%d", &item);

    // length = deleteElementPosition(arr, length, position);\
    // printf("\nArray after Deletion  :");
    // output(arr, length);

    length = deleteElementItem(arr, length, item);\
    printf("\nArray after Deletion  :");
    output(arr, length);

    return 0;
}

void input(int* arr, int length) {
    for (int i = 0; i < length; i++){
        scanf("%d", arr + i);
    }
}

void output(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(arr + i));
    }
}

// int deleteElementPosition(int* arr, int length, int position) {
//     int temp = arr[position];
//     for (int i = position; i < length; i++) {
//         arr[i] = arr[i + 1];
//     }
//     length--;
//     return length;
// }

int deleteElementItem(int* arr, int length, int item) {
    int position, found;
    for (int i = 0; i < length; i++) {
        if (arr[i] == item){
            found = 1;
            position = i;
            break;
        }
    }

    if (found == 1) {
        for (int i = position; i < length - 1; i++) {
            arr[i] = arr[i + 1];
        }
    }
    length--;
    return length;
}