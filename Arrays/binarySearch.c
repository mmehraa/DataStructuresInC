#include <stdio.h>

void input(int*, int);
int binarySearch(int*, int, int);

int main() {
    int length;
    printf("Enter Array Length : ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter Array Elements : ");
    input(arr, length);

    int target;
    printf("Enter target Element : ");
    scanf("%d", &target);

    int answer = binarySearch(arr, length, target);
    if (answer >= 0) {
        printf("Element Found at index : %d", answer);
    } else {
        printf("Element Not Found.");
    }

    return 0;
}

void input(int* arr, int length) {
    for (int i = 0; i < length; i++){
        scanf("%d", arr + i);
    }
}

int binarySearch(int* arr, int length, int target) {
    int start = 0;
    int end = length - 1;

    while (start <= end) {
        int mid = start + (end - start)/2;
        if (*(arr + mid) > target) {
            end = mid - 1;
        } else if (*(arr + mid) < target) {
            start = mid + 1;
        } else {
            return mid;
        }
    }
    return 1;
}