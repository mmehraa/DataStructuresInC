#include <stdio.h>
#include <malloc.h>

struct node{
        int data;
        struct node *lChild;
        struct node *rChild;
};

struct node *addTreeNode(int value){
        struct node *treeNode = (struct node*)malloc(sizeof(struct node));
        treeNode -> data = value;
        treeNode -> lChild = NULL;
        treeNode -> rChild = NULL;
        return treeNode;
}
   
int main(){
        struct node *root = addTreeNode(7);
        struct node *honey = addTreeNode(10);
        struct node *shivam = addTreeNode(11);
        root -> lChild = honey;
        root -> rChild = shivam;
        return 0;
}