#include <stdio.h>
#include <malloc.h>

struct node{
        int data;
        struct node *lChild;
        struct node *rChild;
};

struct node *addTreeNode(int data){
        struct node *treenode = (struct node *)malloc(sizeof(struct node));
        treenode->data = data;
        treenode->lChild = NULL;
        treenode->rChild = NULL;
        return treenode;
}

struct node *searchBST(struct node *root, int value){
        if (root == NULL){
                return NULL;
        }else if (root->data == value){
                return root;
        }else if (root->data > value){
                return searchBST(root->lChild, value);
        }else{
                return searchBST(root->rChild, value);
        }
}

int main(){
        struct node *root = addTreeNode(5);
        struct node *p1 = addTreeNode(3);
        struct node *p2 = addTreeNode(6);
        struct node *p3 = addTreeNode(1);
        struct node *p4 = addTreeNode(4);

        root->lChild = p1;
        root->rChild = p2;
        p1->lChild = p3;
        p1->rChild = p4;

        if (searchBST(root, 11) == NULL){
                printf("Element Not Found");
        } else {
                printf("Element Found");
        }
}