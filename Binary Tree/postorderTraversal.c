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

struct node *postOrderTraversal(struct node *root){
        if (root != NULL){
                postOrderTraversal(root -> lChild);
                postOrderTraversal(root -> rChild);
                printf("%d ", root -> data);
        }
}

int main(){
        struct node *root = addTreeNode(4);
        struct node *p1 = addTreeNode(1);
        struct node *p2 = addTreeNode(6);
        struct node *p3 = addTreeNode(5);
        struct node *p4 = addTreeNode(2);

        root -> lChild = p1;
        
        root -> rChild = p2;
        p1 -> lChild = p3;
        p1 -> rChild = p4;

        postOrderTraversal(root);
        return 0;
}