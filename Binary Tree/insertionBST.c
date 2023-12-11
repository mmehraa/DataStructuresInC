#include <stdio.h>
#include <malloc.h>

struct node {
        int data;
        struct node *lChild;
        struct node *rChild;
};

struct node *addTreeNode(int data){
        struct node *treenode = (struct node *)malloc(sizeof(struct node));
        treenode -> data = data;
        treenode ->lChild = NULL;
        treenode -> rChild = NULL;
        return treenode;
}

void insertNode(struct node *root, int data){
        struct node *prev = NULL;

        while (root != NULL){
                prev = root;
                if(root -> data == data){
                        printf("Cannot insert %d. Already exists.", data);
                        return;
                } else if (root -> data > data){
                        root = root -> lChild;
                } else{
                        root = root -> rChild;
                }
        }
        struct node *newNode = addTreeNode(data);
        if (prev -> data > data){
                prev -> lChild = newNode;
        } else {
                prev -> rChild = newNode;
        }
}

int main(){
        struct node *root = addTreeNode(5);
        struct node *p1 = addTreeNode(3);
        struct node *p2 = addTreeNode(6);
        struct node *p3 = addTreeNode(1);
        struct node *p4 = addTreeNode(4);

        root -> lChild = p1;
        root -> rChild = p2;
        p1 -> lChild = p3;
        p1 -> rChild = p4;

        insertNode(root, 6);
        printf("%d", root -> rChild -> rChild -> data);

        return 0;
}