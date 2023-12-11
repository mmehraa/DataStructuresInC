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

struct node *inOrderPredecessor(struct node *root){
        root = root -> lChild;
        while (root -> rChild != NULL){
                root = root -> rChild;
        }
        return root;
}

struct node *deleteNode(struct node *root, int data){
        struct node *inPre;

        //If tree is empty
        if (root == NULL){
                printf("Tree is Empty");
                return NULL;
        }
        //If tree has only one node
        if (root -> lChild == NULL && root -> rChild == NULL){
                free(root);
                return NULL;
        }
        // Searching for the node
        if (data < root -> data){
                root -> lChild = deleteNode(root -> lChild, data);
        } else if (data > root -> data){
                root -> rChild = deleteNode(root -> rChild, data);
        }
        //Deletion Strategy
        else {
                inPre = inOrderPredecessor(root);
                root -> data = inPre -> data;
                root -> lChild = deleteNode(root -> lChild, inPre -> data);
        }
        return root;
}

struct node *inOrderTraversal(struct node *root){
        if (root != NULL){
                inOrderTraversal(root -> lChild);
                printf("%d ", root -> data);
                inOrderTraversal(root -> rChild);
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

        inOrderTraversal(root);
        printf("\n");
        deleteNode(root, 3);
        inOrderTraversal(root);
        return 0;
}