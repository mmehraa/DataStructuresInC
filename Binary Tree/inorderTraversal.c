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

struct node *inOrderTraversal(struct node *root){
        if (root != NULL){
                inOrderTraversal(root -> lChild);
                printf("%d ", root -> data);
                inOrderTraversal(root -> rChild);
        }
}

int main(){
        struct node *root = addTreeNode(9);
        struct node *p1 = addTreeNode(4);
        struct node *p2 = addTreeNode(11);
        struct node *p3 = addTreeNode(2);
        struct node *p4 = addTreeNode(7);

        root -> lChild = p1;
        root -> rChild = p2;
        p1 -> lChild = p3;
        p1 -> rChild = p4;

        inOrderTraversal(root);
        return 0;
}