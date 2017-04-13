// 2017.4.13
// Double Linked List in C
// made by Jisu An

#include<stdio.h>

// node for linked List
typedef struct node {
	int data;
	struct node* front;
	struct node* rear;
}Node;

typedef Node* List;

// push do not divide stack and queue
void push(int data,List* now);
// pop data from Last to First 
int stackPop(List* tail);
// pop data from First to Last
int queuePop(List* head, List *tail);

int main(){

	int select;
	int inputData;
	List head = (Node*)malloc(sizeof(Node));
	List tail = head;
	head->front = head;

	printf("input an integer : ");
	while ((inputData = getchar()) != '\n') // input to use push
		push(inputData-'0', &tail);
	printf("Select Method (1) Stack (2) Queue : ");
	scanf("%d", &select);

	if (1 == select){
		while (head != tail)
			printf("%d\n", stackPop(&tail));

	}
	else if(2 == select){
		while (head != tail)
			printf("%d\n", queuePop(&head, &tail));
	}
	else{
		printf("select error!\n");
	}
}

void push(int data, List* now){
	(*now)->rear = (Node*)malloc(sizeof(Node));
	((*now)->rear)->front = *now;
	((*now)->rear)->data = data;
	*now = (*now)->rear;
}

int stackPop(List* tail){
	int data = (*tail)->data;
	Node* preNode = (*tail)->front;

	free(preNode->rear);

	preNode->rear = NULL;
	*tail = preNode;

	return data;
}

int queuePop(List* head, List *tail){

	Node* nextNode = (*head)->rear;
	int data = nextNode->data;

	if((*head)->rear != (*tail)){

		(*head)->rear = nextNode->rear;
		(nextNode->rear)->front = *head;

	}else{
		*tail = *head;
	}

	free(nextNode);

	return data;
}
