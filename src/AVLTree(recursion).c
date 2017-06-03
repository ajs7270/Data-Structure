#include <stdio.h>
#include <stdlib.h>

#define TRUE 1

//node for avl tree
typedef struct node{
  int data;
  struct node *right;
  struct node *left;
  int height;
}Node;

//functions for avl tree
Node* insert(Node* root,int data);
Node* delete(Node* root, int data);

//support avl fuctions
Node *rotateright(node *);
Node *rotateleft(node *);
Node *RR(node *);
Node *LL(node *);
Node *LR(node *);
Node *RL(node *);

//fuction for tree traversal
void preorder(node *);
void inorder(node *);


void main(int argc, char* argv[]){
  Node *root = NULL;
  int inputdata;
  int menu;

  while (TRUE){
    printf("Input : ");
    scanf("%d", &inputdata);
    printf("1) Insert 2) Delete : ");
    scanf("%d", &menu);

    if (menu == 1){
      root = insert(root, inputdata);
    }
    else (menu == 2){
      root = delete(root,inputdata);
    }
    else{
      printf("possible input number is 1 or 2\n")
    }

    printf("Preorder: ");
    preorder(root); printf("\n");
    printf("Inorder: ");
    inorder(root); printf("\n");
  }
}
