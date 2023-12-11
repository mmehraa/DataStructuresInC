#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *lchild;
        struct node *rchild;
};

void displayGivenLevel(struct node *, int);
int height(struct node *);
struct node *newNode(int);

int main(){
        struct node *root = newNode(1);
        root->lchild = newNode(2);
        root->rchild = newNode(3);
        root->lchild->lchild = newNode(4);
        root->lchild->rchild = newNode(5);
        printf("Level Order traversal of binary tree is: ");
        displayLevelOrder(root);
        return 0;
}


/*function to allocate a new node*/
struct node *newNode(int data){
        struct node *node = (struct node *)malloc(sizeof(struct node));
        node->data = data;
        node->lchild = NULL;
        node->rchild = NULL;
        return (node);
}


/*Function to display level order traversal a tree*/
void displayLevelOrder(struct node *root){
        int h = height(root);
        int i;
        for (i = 1; i <= h; i++){
                displayGivenLevel(root, i);
        }
}


/*Dispaly nodes at a given level*/
void displayGivenLevel(struct node *root, int level){
        if (root == NULL)
                return;
        if (level == 0)
                printf("%d ", root->data);
        else if(level > 0){
                displayGivenLevel(root->lchild, level - 1);
                displayGivenLevel(root->rchild, level - 1);
        }
}


/* Finding the height of a tree*/
int height(struct node *node){
        int l_height, r_height;
        if (node == NULL)
                return 0;
        else{
                l_height = height(node->lchild);
                r_height = height(node->rchild);
                /* use the larger one */
                if (l_height > r_height)
                        return (l_height + 1);
                else
                        return (r_height + 1);
        }
}