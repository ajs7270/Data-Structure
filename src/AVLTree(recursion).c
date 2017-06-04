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
Node *rotateright(Node* root);
Node *rotateleft(Node* root);
Node *RR(Node* root);
Node *LL(Node* root);
Node *LR(Node* root);
Node *RL(Node* root);

//support rotate functions
int balanceFactor(Node *root);
int Height(Node* root);

//fuction for tree traversal
void preorder(node *root);
void inorder(node *root);


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

Node* insert(Node* root,int data){
  if(root==NULL){
    root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->height = 0;
  }else{
    if(data < root->data){ // input left child node
      root->left = insert(root->left,data);
      if(){
        if()
      }
    }else{ // input right child node
      root->right = insert(root->right,data);
      if(){

      }
    }
  }
  root->height = Height(root);
  return root;
}
Node* delete(Node* root, int data){

}

Node *rotateright(Node* root){
  node *y;
  y=x->left;
  x->left=y->right;
  y->right=x;
  x->ht=height(x);
  y->ht=height(y);
  return(y);
}
Node *rotateleft(Node* root){
  node *y;
  y=x->right;
  x->right=y->left;
  y->left=x;
  x->ht=height(x);
  y->ht=height(y);

  return(y);
}
Node *RR(Node* root){
  T=rotateleft(T);
  return(T);
}
Node *LL(Node* root){
  T=rotateright(T);
  return(T);
}
Node *LR(Node* root){
  T->left=rotateleft(T->left);
  T=rotateright(T);

  return(T);
}
Node *RL(Node* root){
  T->right=rotateright(T->right);
  T=rotateleft(T);

  return(T);
}

int balanceFactor(Node *root){
  int leftHeight,rightHeight;
    if(root==NULL)
        return 0;

    if(root->left == NULL)
        leftHeight = 0;
    else
        leftHeight = 1 + root->left->height;

    if(root->right == NULL)
        rightHeight = 0;
    else
        rightHeight = 1 + root->right->height;

    return(leftHeight-rightHeight);
}
int Height(Node* root){
  int leftHight,rightHight;
   if(root == NULL)
       return(0);

   if(root->left==NULL)
       leftHight = 0;
   else
       leftHight = 1 + root->left->height;

   if(root->right==NULL)
       rightHight = 0;
   else
       rightHight = 1+root->right->height;

   if(rightHight>leftHight){
     return rightHight;
   }else{
     return leftHight;
   }
}

void preorder(node *root){
  if(root){
        printf("%d ",T->data);
        preorder(T->left);
        preorder(T->right);
    }
}

void inorder(node *root){
  if(root){
      inorder(T->left);
      printf("%d ",T->data);
      inorder(T->right);
  }
}
