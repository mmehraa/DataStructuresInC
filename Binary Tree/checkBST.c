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

int isBST(struct node *root){
        static struct  node *prev = NULL;

        if (root != NULL){
                if (!isBST (root -> lChild)){
                        return 0;
                }
                if (prev != NULL && root -> data <= prev -> data){
                        return 0;
                }
                prev = root;
                return isBST(root -> rChild);
        }
        else {
                return 1;
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

        printf("%d", isBST(root));
        return 0;
}