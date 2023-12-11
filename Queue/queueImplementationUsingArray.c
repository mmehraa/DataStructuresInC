#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void addToQueue();
void deleteFromQueue();
void displayQueue();

int queue[MAX];
int front = -1, rear = -1;

int main(){
        int choice;
        do {
                printf("\nQueue OPERATIONS USING ARRAY");
                printf("\n----------------------------");
                printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT\n");
                printf("Enter your choice : ");
                scanf("%d", &choice);

                switch(choice) {
                        case 1:
                                addToQueue();
                                break;
                        case 2:
                                deleteFromQueue();
                                break;
                        case 3:
                                displayQueue();
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

void addToQueue(){
        int item;
        printf("Enter Element to be Added : ");
        scanf("%d", &item);
        if(rear == MAX - 1){
                printf("Queue Overflow.\n");
                return;
        }
        else{
                if (front == -1){
                        front = 0;
                }

                rear++;
                queue[rear] = item;
        }
        printf("\nValue Inserted.\n");
}

void deleteFromQueue(){
        int item;
        if (front == -1 && rear == -1){
                printf("Queue Underflow.\n");
                return;
        }
        else {
                item = queue[front];
                if(front == rear){
                        front = -1;
                        rear = -1;
                }
                else {
                        front = front + 1;
                }
        }
        printf("\nValue Omitted.\n");
}

void displayQueue(){
        if (rear == -1){
                printf("Empty Queue.\n");
        }
        else {
                for (int i = front; i <= rear; i++){
                        printf("\n%d\n", queue[i]);
                }
        }
}