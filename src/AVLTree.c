// 2017.5.28
// AVL Tree in C
// made by Jisu An
// I don't compelite this code

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1


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
Node* delete(Node* root, int data);
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
Node* LL(Node* root);
void LR(Node* root);
void RL(Node* root);
Node* RR(Node* root);

//fuction for tree traversal
void inorder(Node* nowNode);
void preorder(Node* nowNode);


Node* insert(Node* root,int data){
  Node* current = root;

  if (root->data == data){ return root; }
  while (current->data != data){

    /*
     *new data insert to right position
     *if insert data already exist, this function doing nothing
     */
    if(data > current->data){
      if(current->right){
        current = current->right;
      }else{
        current->right = mkNode(data, current);
        current = current->right;

      }

    }else if(data < current->data){
      if(current->left){
        current = current->left;
      }else{
        current->left = (data, current);
        current = current->left;

      }
    }else{
      return root;
    }
  }
  /*
   *balancing after to insert data
   */
   do{
      current = current->parent;
      adjustHeight(current);
      current = balance(current);
    }while(current->parent);

    return current;
}


Node* delete(Node* root,int data){
  Node* current = root;
  while(TRUE){

    /*
     *search data
     *if search data is not exist, this function doing nothing
     */
    if(data > current->data){
      if(current->right){
        current = current->right;
      }else{
		  return root;
      }

    }else if(data < current->data){
      if(current->left){
        current = current->left;
      }else{
		  return root;
      }
    }else{
      break;
    }
  }

  if(current->data == data){
    /*
     *if find data
     *delete this data
     */
    current = current->parent;
    if(current->data < data){
      free(current->right);
      current->right = NULL;
    }else{
      free(current->left);
      current->left = NULL;
    }

     /*
      *balancing after to delete data
      */
      do{
       current = current->parent;
       adjustHeight(current);
       current = balance(current);
      }while(current->parent);

      return current;

    }else{
      return root;
    }
}

Node* balance(Node *root){

  /*
   *check balance and lotate positon
   *using 4-tpye rotation method
   */
  if(height(root->left) - height(root->right) > 1){
    if(height(root->left) - height(root->right) < 0){
    //LR
      LR(root);
      root = LL(root);
	  return root;
    }else{
    //LL
		if (root->parent){
			/*
			 *if LL or RR case check root's parent node
			 */
			if (root->data > root->parent->data){
				root->parent->right = LL(root);
			}
			else{
				root->parent->left = LL(root);
			}
		}
		else{
			root = LL(root);
		}
	  return root;
    }
  }else if(height(root->left) - height(root->right) < -1){
    if(height(root->left) - height(root->right) > 0){
    //RL
      RL(root);
      root = RR(root);

	  return root;
	}else{
    //RR
		if (root->parent){
			/*
			*if LL or RR case check root's parent node
			*/
			if (root->data > root->parent->data){
				root->parent->right = RR(root);
			}
			else{
				root->parent->left = RR(root);
			}
		}
		else{
			root = RR(root);
		}
    }
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
  newNode->left = NULL;

  return newNode;
}

Node* LL(Node* root){
  Node* rootLeft = root->left;

  if(rootLeft->right){
    root->left = rootLeft->right;
    rootLeft->right->parent = root;
  }else{
    root->left = NULL;
  }

  root->height -= 2;

  rootLeft->right = root;
  rootLeft->parent = root->parent;
  root->parent = rootLeft;

  return rootLeft;
}

void LR(Node* root){
  Node* rootLeft = root->left;

  root->left = rootLeft->right;
  root->left->parent = root;

  if(root->left->left){
    rootLeft->right = root->left->left;
	rootLeft->right->parent = rootLeft;
    root->left->left = rootLeft;
  }else{
    rootLeft->right = NULL;
  }
  rootLeft->parent = root->left;
}

void RL(Node* root){
  Node* rootRight = root->right;

  root->right = rootRight->left;
  root->right->parent = root;

  if(root->right->right){
    rootRight->left = root->right->right;
	rootRight->left->parent = rootRight;
    root->right->right = rootRight;
  }else{
    rootRight->left = NULL;
  }
  rootRight->parent = root->right;
}

Node* RR(Node* root){
  Node* rootRight = root->right;

  if(rootRight->left){
    root->right = rootRight->left;
    rootRight->left->parent = root;
  }else{
    root->right = NULL;
  }

  root->height -= 2;

  rootRight->left = root;
  rootRight->parent = root->parent;
  root->parent = rootRight;


  return rootRight;
}

void inorder(Node* nowNode){

}
void preorder(Node* nowNode){

}


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
		  if (root == NULL){
			  root = mkNode(inputdata, NULL);
		  }
		  else{
			  root = insert(root, inputdata);
		  }
	  }
	  else if(menu == 2){
		  root = delete(root,inputdata);
	  }
	  else{ }

	  printf("Preorder: ");
	  preorder(root); printf("\n");
	  printf("Inorder: ");
	  inorder(root); printf("\n");

  }
}
