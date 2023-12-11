#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node *next;
};

struct node *reverse(struct node *start){
        struct node *prevNode, *currentNode, *nextNode;
        prevNode = NULL;
        currentNode = nextNode = start;
        while (nextNode != NULL) {
                nextNode = nextNode -> next;
                currentNode -> next = prevNode;
                prevNode = currentNode;
                currentNode = nextNode;
        }
        start = prevNode;
        return start;
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


        start -> data = 7;
        start -> next = second;  

        second -> data = 11;
        second -> next = third;

        third -> data = 66;
        third -> next = NULL;

        printf("\nBefore: \n");
        linkedListTraversal(start);
        printf("\nAfter: \n");
        start = reverse(start);
        linkedListTraversal(start);


        return 0;
}