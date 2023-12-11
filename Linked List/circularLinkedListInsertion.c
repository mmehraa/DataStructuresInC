#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *insertionAtFirst(struct node *start, int item){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr -> data = item;

        struct node *p = start -> next;
        while (p ->next != start){
                p = p -> next;
        }
        p -> next = ptr;
        ptr -> next = start;
        start = ptr;
        return start;
}

struct node *insertAtIndex(struct node *start, int item, int index){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr -> data = item;
        struct node *p = start;

        int i = 0;
        while (i != index - 1){
                p = p -> next;
                i++;
        }
        ptr -> next = p -> next;
        p -> next = ptr;
        return start;
}

struct node *insertAtEnd(struct node *start, int item){
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr -> data = item;

        struct node *p = start -> next;
        while (p -> next != start){
                p = p -> next;
        }
        p -> next = ptr;
        ptr -> next = start;

        return start;
}

void circularTraversal(struct node *start){
        struct node *ptr = start;
        do {
                printf("\n%d\n", ptr -> data);
                ptr = ptr -> next;
        } while (ptr != start); 
}

int main(){
        struct node *start, *second, *third, *fourth;
        start = (struct node*) malloc (sizeof(struct node));
        second = (struct node*) malloc (sizeof(struct node));
        third = (struct node*) malloc (sizeof(struct node));
        fourth = (struct node*) malloc (sizeof(struct node));

        start -> data = 7;
        start -> next = second;  

        second -> data = 11;
        second -> next = third;

        third -> data = 23;
        third -> next = fourth;

        fourth -> data = 37;
        fourth -> next = start;

        circularTraversal(start);
        printf("\nAfter Insertion\n");
        // start = insertionAtFirst(start, 69);
        // start = insertAtIndex(start, 111, 3);
        // start = insertAtEnd(start, 56);
        circularTraversal(start);

        return 0;
}