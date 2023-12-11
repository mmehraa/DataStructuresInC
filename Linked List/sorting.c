#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

void sort(struct node *start){
        struct node *ptr, *cpt;
        int temp;
        ptr = start;
        while (ptr -> next != NULL){
                cpt = ptr -> next;
                while (cpt != NULL) {
                        if (ptr -> data > cpt -> data){
                                temp = ptr -> data;
                                ptr -> data = cpt -> data;
                                cpt -> data = temp;
                        }
                        cpt = cpt -> next;
                }
                ptr = ptr -> next;
        }
}

void linkedListTraversal(struct node *ptr){
        while (ptr != NULL){
                printf("Element : %d\n", *ptr);
                ptr = ptr -> next;
        }
}


int main(){
        struct node *start, *second, *third;
        start = (struct node*) malloc (sizeof(struct node));
        second = (struct node*) malloc (sizeof(struct node));
        third = (struct node*) malloc (sizeof(struct node));


        start -> data = 77;
        start -> next = second;  

        second -> data = 11;
        second -> next = third;

        third -> data = 66;
        third -> next = NULL;

        printf("\nBefore: \n");
        linkedListTraversal(start);
        printf("\nAfter: \n");
        sort(start);
        linkedListTraversal(start);


        return 0;
}