#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *deleteFirst(struct node *start) {
        struct node *ptr = start;
        struct node *p = start -> next;
        while (p -> next != start) {
                p = p -> next;
        }
        start = start -> next;
        p -> next = ptr -> next;
        free(ptr); 
        return start;
}

struct node *deleteItem(struct node *start, int item){
        struct node *ptr1 = start;
        struct node *ptr2 = start -> next;
        while (ptr2 -> data != item) {
                ptr1 = ptr1 -> next;
                ptr1 = ptr1 -> next;
        }
        if (ptr2 -> data == item){
                ptr1 -> next = ptr2 -> next;
                free(ptr2);
        }
        return start;
}

struct node *deleteIndex(struct node *start, int index){
        struct node *ptr = start;
        struct node *p = start -> next;
        int i = 0;
        while (i != index - 1){
                ptr = ptr -> next;
                p = p -> next;
                i++;
        }
        ptr -> next = p -> next;
        free(p);
        return start;
}

void circularTraversal(struct node *start){
        struct node *ptr = start;
        do {
                printf("\n%d\n", ptr -> data);
                ptr = ptr -> next;
        }while (ptr != start);
}

int main() {
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
        printf("\nAfter Deletion\n");
        start = deleteIndex(start, 2);
        circularTraversal(start);

        return 0;
}