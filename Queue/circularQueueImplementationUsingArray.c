#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 5

void pushCQ();
void popCQ();
void displayCQ();

int cQueue[MAX];
int front = - 1, rear = -1;


int main(){
        int choice;
        do {
                printf("\nCircular Queue OPERATIONS USING ARRAY");
                printf("\n-------------------------------------");
                printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);

                switch(choice) {
                        case 1:
                                pushCQ();
                                break;
                        case 2:
                                popCQ();
                                break;
                        case 3:
                                displayCQ();
                                break;
                        case 4:
                                printf("\nEXIT POINT ");
                                break;
                        default:
                                printf ("\nPlease Enter a Valid Choice(1/2/3/4)");       
                }
        }
        while(choice!=4);

        return 0;
}

void pushCQ(){
        int item;
        printf("Enter Element : ");
        scanf("%d", &item);

        if (front == 0 && rear == MAX -1 || front == rear + 1) {
                printf("\nCircular Queue Overflow.\n");
                return;
        }
        else{
                if (front == -1){
                        front = 0;
                        rear = 0;
                }
                else if (rear == MAX - 1){
                        rear = 0;
                }
                else {
                        rear++;
                }
        }
        cQueue[rear] = item;
        printf("\nValue Inserted.\n");
}

void popCQ(){
        int temp;
        if(front == -1){
                printf("\nCircular Queue Underflow.\n");
                return;
        }
        else {
                temp = cQueue[front];
                if (front == MAX -1){
                        front = 0;
                }
                else {
                        front++;
                }
                printf("\nValue Deleted.\n");
        }
}

void displayCQ(){
        if (front == -1){
                printf("Empty Circular Queue.\n");
                return;
        }
        if (front <= rear){
                for(int i = front; i<= rear; i++){
                        printf("\n%d\n", cQueue[i]);
                }
        }
        else {
                for(int i = front; i <= MAX - 1; i++){
                        printf("\n%d\n", cQueue[i]);
                }
                for(int i = 0; i <= rear; i++){
                        printf("\n%d\n", cQueue[i]);
                }
        }
}