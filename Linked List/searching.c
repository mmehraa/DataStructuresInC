#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void search(struct node *start, int item){
        int flag = 0, position = 0;
        struct node *ptr = start;
        while (ptr != NULL){
                position++;
                if (ptr -> data == item){
                        flag = 1;
                        break;
                }
                else {
                        ptr = ptr -> next;
                }
        }
        if (flag == 1) {
                printf("Element Found at Position : %d", position);
        } else {
                printf("Element Not Found.");
        }
}

int main(){
        struct node *start, *second, *third;
        start = (struct node*) malloc (sizeof(struct node));
        second = (struct node*) malloc (sizeof(struct node));
        third = (struct node*) malloc (sizeof(struct node));


        start -> data = 7;
        start -> next = second;  

        second -> data = 11;
        second -> next = third;

        third -> data = 66;
        third -> next = NULL;

        search(start, 56);


        return 0;
}