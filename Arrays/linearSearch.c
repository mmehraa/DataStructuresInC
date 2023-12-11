#include <stdio.h>

void input(int*, int);
int linearSearch(int[], int, int);

int main(){
    int length;
    printf("Enter Array length : ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter Array Elements: ");
    input(arr, length);

    int target;
    printf("Enter Element to be Found : ");
    scanf("%d", &target);

    int answer = linearSearch(arr, length, target);

    if (answer > 0){
        printf("Element Found at index : %d", answer);
    } else {
        printf("Element Not Found.");
    }
    return 0;
}

void input(int* arr, int length) {
    for(int i = 0; i < length; i++) {
        scanf("%d", arr + i);
    }
}

int linearSearch(int arr[], int length, int target) {

    for (int i = 0; i < length; i++){
        if (*(arr + i) == target){
            return i;
        }
    }
    return -1;
}