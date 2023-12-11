#include <stdio.h>
#include <stdlib.h>

struct node {
        int data;
        struct node* next;
};

struct node *deleteFromBeginning(struct node *head) {
        struct node *ptr = head;
        head = head -> next;
        free(ptr);
        return head;
}

struct node *deleteAtIndex(struct node *head, int index){
        struct node *ptr1 = head;
        int i = 0;
        while (i != index - 1){
                ptr1 = ptr1 -> next;
                i++;
        }

        struct node *ptr2 = head;
        int j = 0;
        while (j != index) {
                ptr2 = ptr2 -> next;
                j++;
        }
        ptr1 -> next = ptr2 -> next;
        free(ptr2);

        return head;
}

struct node *deleteValue(struct node *head, int item){
        struct node *ptr1 = head;
        struct node * ptr2 = head -> next;
        while (ptr2 -> data != item || ptr2 -> next == NULL){
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
        }
        if (ptr2 -> data == item){
                ptr1 -> next = ptr2 -> next;
                free(ptr2);
        }
        return head;
}

struct node *deleteEnd(struct node *head){
        struct node *ptr1 = head;
        struct node *ptr2 = head -> next;
        while (ptr2 -> next != NULL){
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
        } 
        ptr1 -> next = NULL;
        free(ptr2);
        return head;
}

void linkedListTraversal(struct node *head){
        struct node *ptr = head;
        while (ptr != NULL){
                printf("\n%d\n", *ptr);
                ptr = ptr -> next;
        }
}



int main(){
        struct node *head, *second, *third, *fourth;
        head = (struct node*)malloc(sizeof(struct node));
        second = (struct node*)malloc(sizeof(struct node));
        third = (struct node*)malloc(sizeof(struct node));
        fourth = (struct node*)malloc(sizeof(struct node));


        head -> data = 1;
        head -> next = second;  

        second -> data = 2;
        second -> next = third;

        third -> data = 3;
        third -> next = fourth;

        fourth -> data = 4;
        fourth -> next = NULL;

        // head = deleteFromBeginning(head);
        // head = deleteAtIndex(head, 1);
        // head = deleteEnd(head);
        head = deleteValue(head, 2);
        linkedListTraversal(head);

        return 0;
}