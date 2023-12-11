#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *prev;
        struct node *next;
};


void doublyTraversal(struct node *start) {
        struct node *ptr = start;

        while (ptr != NULL){
                printf("\n%d\n", ptr -> data);
                ptr = ptr -> next;
        }
}

int main(){
        struct node * start = (struct node *)malloc(sizeof(struct node));
        struct node *second = (struct node *)malloc(sizeof(struct node));
        struct node *third = (struct node *)malloc(sizeof(struct node));
        struct node *fourth = (struct node *)malloc(sizeof(struct node));
        struct node *fifth = (struct node *)malloc(sizeof(struct node));

        start -> data = 7;
        start -> next = second;
        start -> prev = NULL;

        second -> data = 11;        
        second -> next = third;
        second -> prev = start;

        third -> data = 17;
        third -> next = fourth;
        third -> prev = second;

        fourth -> data = 23;
        fourth -> next = fifth;
        fourth -> prev = third;

        fifth -> data = 34;
        fifth -> next = NULL;
        fifth -> prev = fourth;

        doublyTraversal(start);
        return 0;        
}