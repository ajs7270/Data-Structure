#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define VERTEX 5
#define TRUE 1
#define FALSE 0

typedef struct edge{
  int i,j;// 두개의 vertex들
  int weight;
}Edge;

void makeGraph(Edge graph[], int edges);
void print(Edge tree[]);
void sel(int ms[], int i, int j);
int check(int ms[], int i, int j);
void kruskal(Edge graph[], Edge tree[], int edges);


//make graph
void makeGraph(Edge graph[],int edges){
  for(int i = 0; i< edges;i++){
    printf("Input edge((i,j),Weight): ");
    scanf("%d,%d,%d",&graph[i].i,&graph[i].j,&graph[i].weight);
  }
}

//print generated minimum spanning tree
void print(Edge tree[]){
  int matrix[5][5] = {0, };
  int sum = 0;
  for (int i = 0; i < VERTEX - 1; i++){
	  matrix[tree[i].i - 1][tree[i].j - 1] = 1;
	  matrix[tree[i].j - 1][tree[i].i - 1] = 1;
	  sum += tree[i].weight;
  }

  for (int i = 0; i < 5; i++){
	  for (int j = 0; j < 5; j++){
		  printf("%d ", matrix[i][j]);
	  }
	  printf("\n");
  }
  printf("\n minimum cost = %d", sum);
}

//for the entrance of the values in the array to check mst graph cycle
void sel(int ms[],int i,int j){
  if(ms[i+1]==0 && ms[j+1]==0){
    if(i<j){
      ms[i+1]=i+1;
      ms[j+1]=i+1;
    }else{
      ms[i+1]=j+1;
      ms[j+1]=j+1;
    }
  }else if(ms[i+1]!=0 && ms[j+1]!=0){
    if(i<j){
		for (int k = 0; k < VERTEX; k++){
			if (ms[k] == ms[j + 1]){
				ms[k] = ms[i + 1];
			}
		}
	}
	else{
		for (int k = 0; k < VERTEX; k++){
			if (ms[k] == ms[i + 1]){
				ms[k] = ms[j + 1];
			}
		}
	}
  }
  else{
	  if (ms[i + 1] != 0){
		  ms[j + 1] = ms[i + 1];
	  }
	  else{
		  ms[i + 1] = ms[j + 1];
	  }
  }
}


int check(int ms[], int i, int j){
	if (ms[i + 1]==0 && ms[j + 1] == 0){
		return TRUE;
	}
	else if (ms[i + 1] == ms[j + 1]){
		return FALSE;
	}
	else{
		return TRUE;
	}
}


void kruskal(Edge graph[], Edge tree[],int edges){
	Edge temp;
	int* ms = (int*)malloc(sizeof(int)*(VERTEX));

	for (int i = 0; i < VERTEX; i++){
		ms[i] = 0;
	}
	
	//selection sort (use weight)
	for (int i = 0; i < edges - 1; i++){
		for (int j = i + 1; j < edges; j++){
			if (graph[i].weight > graph[j].weight){
				temp = graph[i];
				graph[i] = graph[j];
				graph[j] = temp;
			}
		}
	}

	//tree
	for (int i = 0, k = 0; i < VERTEX - 1; i++){
		while (TRUE){
			if (check(ms, graph[k].i, graph[k].j)){
				tree[i] = graph[k];
				sel(ms, graph[k].i, graph[k].j);
				k++;
				break;
			}
			k++;
		}
	}

}

void main(int argc, char* argv[]){
	int edges;
	Edge* graph;
	Edge* tree;

	printf("Input edges num:");
	scanf("%d", &edges);

	graph = (Edge*)malloc(edges*sizeof(Edge));
	tree = (Edge*)malloc((VERTEX - 1)*sizeof(Edge));

	makeGraph(graph,edges);
	kruskal(graph, tree, edges);

	for (int i = 0; i < VERTEX - 1; i++){
		printf("%d %d %d\n", tree[i].i, tree[i].j, tree[i].weight);
	}

	print(tree);
	printf("");

	return;
}

