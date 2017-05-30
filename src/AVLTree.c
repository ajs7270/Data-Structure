// 2017.5.28
// AVL Tree in C
// made by Jisu An

#include <stdio.h>

//node for avl tree
typedef struct node{
  int data;
  struct node *right;
  struct node *left;
  struct node *parent;
  int height;
}Node;

//function for avl tree
Node* insert(Node* root,int data);
Node* delete(Node* root);
Node* balance(Node* root);
Node* mkNode(int data, Node* parent);

//support avl tree function
int maxHeight(int right, int left){
  return right>left ? right : left;
}
int height(Node* root){
  return root ? root->height : 0;
}
int adjustHeight(Node* root){
  root->height = 1 + maxHeight(height(root->right),height(root->left));
}

//support balance function
Node* RotateRight(Node *root);
Node* RotateLeft(Node *root);
Node* LL(Node* root);
Node* LR(Node* root);
Node* RL(Node* root);
Node* RR(Node* root);

//fuction for tree traversal
void inorder(Node* nowNode);
void preorder(Node* nowNode);


Node* insert(Node* root,int data){
  Node* current = root;

  while(current->data != data){

    /*
     *new data insert to right position
     *if insert data already exist, this function doing nothing
     */
    if(data > current->data){
      if(current->right){
        current = current->right;
      }else{
        mkNode(data, current);
        current = current->right;
      }

    }else if(data < current->data){
      if(current->left){
        current = current->left;
      }else{
        mkNode(data, current);
        current = current->left;
      }
    }else{
      return root;
    }

  /*
   *balancing after to insert data
   */
   do{
      current = current->parent;
      adjustHeight(current);
      current = balance(current);
    }while(current->parent);
  }
}

Node* delete(Node* root,int data){
  if(root == NULL){
    return
  }
}

Node* balance(Node *root){

  /*
   *check balance and lotate positon
   *using 4-tpye rotation method
   */
  if(height(root->left) - height(root->right) > 1){

  }else if(height(root->right) - height(root->left) > 1){

  }else{
    return root;
  }

}

//make new node
Node* mkNode(int data, Node* parent){

  Node* newNode = malloc(sizeof(Node));
  newNode->data = data;
  newNode->parent = parent;
  newNode->height = 1;
  newNode->right = NULL;
  newNode->left = NULL:

  return newNode;
}

Node* RotateRight(Node *root){
	Node* leftNode = root->left;
  
}
Node* RotateLeft(Node *root);

Node* LL(Node* root){

}
Node* LR(Node* root){

}
Node* RL(Node* root){

}
Node* RR(Node* root);
