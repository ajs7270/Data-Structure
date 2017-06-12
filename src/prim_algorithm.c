#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define VERTEX 5
#define TRUE 1
#define FALSE 0


typedef struct edge{
	int i, j;
	int weight;
	bool use;
}Edge;


//make graph
void makeGraph(Edge graph[], int edges){
	for (int i = 0; i< edges; i++){
		printf("Input edge((i,j),Weight): ");
		scanf("%d,%d,%d", &graph[i].i, &graph[i].j, &graph[i].weight);
		graph[i].use = false;
	}
}

//print generated minimum spanning tree
void print(Edge tree[]){
	int matrix[5][5] = { 0, };
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

void prim(Edge graph[], Edge tree[], int edges){
	int index = 0; // 하나의 vertex에 연결된 edge의 수
	int currentVertex = 0;
	Edge temp;
	Edge targetVertex[VERTEX*(VERTEX-1)/2] = { NULL, };

	//selection sort (use vertex i)
	for (int i = 0; i < edges - 1; i++){
		for (int j = i + 1; j < edges; j++){
			if (graph[i].i > graph[j].i){
				temp = graph[i];
				graph[i] = graph[j];
				graph[j] = temp;
			}
		}
	}

	//prim algorithm start point is vertex 0
	targetVertex[0] = graph[0];
	graph[0].use = true;
	for (int i = 0;  graph[i].i == graph[i + 1].i; i++){
		targetVertex[i] = graph[i];
		graph[i].use = true;
	}
	for (int i = 0;i < VERTEX-1; i++){
		while (TRUE){
			index = 0;
			if (targetVertex[i+1].weight != 0){
				if (targetVertex[index].weight>targetVertex[i + 1].weight){
					index = i + 1;// 가장작은 타겟인덱스를 찾음
				}
			}
			else{
				break;
			}
		}
		tree[i] = targetVertex[index];
		currentVertex = tree[i].j;
		// TV 값들을 앞으로 당겨줌
		for (int j = index; targetVertex[j].weight != 0; j++){
			targetVertex[j] = targetVertex[j + 1];
			index = j;
		}

		for (int j = 0; j < edges; j++){
			if (graph[j].i == currentVertex || graph[j].j == currentVertex){
				if (graph[j].use == false){
					targetVertex[index] = graph[j];
					graph[j].use = true;
					index++;
				}
			}
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

	makeGraph(graph, edges);
	prim(graph, tree, edges);

	print(tree);
	printf("");
}