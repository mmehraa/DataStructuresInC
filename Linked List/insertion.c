#include <stdio.h>
#include <stdlib.h> 

struct Node {
        int data;
        struct Node* next;
};

struct Node *insertAtBeginning(struct Node *head, int data){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        ptr -> next = head;
        ptr -> data = data;
        head = ptr;
        return head; 
}

struct Node *insertInBetween(struct Node *head, int data, int index){
        struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
        struct Node *p = head;
        int i = 0;
        while (i != index - 1){
                p = p -> next;
                i++;
        }

        ptr -> data = data;
        ptr -> next = p -> next;
        p -> next = ptr;
        return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
        struct Node *ptr = (struct Node*) malloc(sizeof(struct Node));
        struct Node *p = head;

        while (p -> next != NULL){
                p = p -> next;
        }

        ptr -> data = data;
        p -> next = ptr; 
        ptr -> next = NULL;
        return head;
}

void linkedListTraversal(struct Node *ptr){
        while (ptr != NULL){
                printf("  %d\n", *ptr);
                ptr = ptr -> next;
        }
}


int main(){
        struct Node* head, *second, *third, *fourth;
        head = (struct Node*) malloc (sizeof(struct Node));
        second = (struct Node*) malloc (sizeof(struct Node));
        third = (struct Node*) malloc (sizeof(struct Node));


        head -> data = 7;
        head -> next = second;  

        second -> data = 11;
        second -> next = third;

        third -> data = 66;
        third -> next = NULL;

        linkedListTraversal(head);

        head = insertAtBeginning(head, 56);
        linkedListTraversal(head);

        // head = insertInBetween(head, 69, 2);
        // linkedListTraversal(head);

        // head = insertAtEnd(head, 72);
        // linkedListTraversal(head);

        return 0;
} 