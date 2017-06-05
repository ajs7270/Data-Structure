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
void preorder(Node *root);
void inorder(Node *root);


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
    else if(menu == 2){
      root = delete(root,inputdata);
    }
    else{
      printf("possible input number is 1 or 2\n");
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
      if(balanceFactor(root)==2){
        if(data > root->left->data){//LR case
          root = LR(root);
        }else{ // LL case
          root = LL(root);
        }
      }
    }else{ // input right child node
      root->right = insert(root->right,data);
      if(balanceFactor(root)==-2){
        if(data > root->right->data){//RR case
          root = RR(root);
        }else{ //RL case
          root = RL(root);
        }
      }
    }
  }
  root->height = Height(root);
  return root;
}

Node* delete(Node* root, int data){
  Node* temp;

  if(root == NULL){
    return root;
  }else{
    if(data < root->data){ // if data is exist, this data exists left child node
      root->left = delete(root->left,data);
      if(balanceFactor(root)==2){
        if(data > root->left->data){//LR case
          root = LR(root);
        }else{ // LL case
          root = LL(root);
        }
      }
    }else{ // if data is exist, this data exists right child node
         if(data > root->data){
           root->right = delete(root->right,data);
           if(balanceFactor(root)==-2){
             if(data > root->right->data){//RR case
               root = RR(root);
             }else{ //RL case
               root = RL(root);
             }
           }
         }else{ // find this data or not found this data
           if(root->right!=NULL){
             temp=root->right;

           while(temp->left!= NULL)
            temp=temp->left;

           root->data=temp->data;
           root->right=delete(root->right,temp->data);

           if(balanceFactor(root)==2)//Rebalance during windup
              if(balanceFactor(root->left)>=0)
                root=LL(root);
              else
                root=LR(root);
          }else
            return(root->left);
        }
      }
    }
    root->height = Height(root);
    return root;
  }
Node *rotateright(Node* root){
  Node *leftNode;

  leftNode=root->left;
  root->left=leftNode->right;
  leftNode->right=root;
  root->height=Height(root);
  leftNode->height=Height(leftNode);
  return leftNode;
}

Node *rotateleft(Node* root){
  Node *rightNode;
  rightNode=root->right;
  root->right=rightNode->left;
  rightNode->left=root;
  root->height=Height(root);
  rightNode->height=Height(rightNode);

  return(rightNode);
}
Node *RR(Node* root){
  root=rotateleft(root);
  return(root);
}
Node *LL(Node* root){
  root=rotateright(root);
  return(root);
}
Node *LR(Node* root){
  root->left=rotateleft(root->left);
  root=rotateright(root);

  return(root);
}
Node *RL(Node* root){
  root->right=rotateright(root->right);
  root=rotateleft(root);

  return(root);
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
  int leftHeight,rightHeight;
   if(root == NULL)
       return(0);

   if(root->left==NULL)
       leftHeight = 0;
   else
       leftHeight = 1 + root->left->height;

   if(root->right==NULL)
       rightHeight = 0;
   else
       rightHeight = 1+root->right->height;

   if(rightHeight>leftHeight){
     return rightHeight;
   }else{
     return leftHeight;
   }
}

void preorder(Node *root){
  if(root){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root){
  if(root){
      inorder(root->left);
      printf("%d ",root->data);
      inorder(root->right);
  }
}
