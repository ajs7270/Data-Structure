#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
  int i,j;// 두개의 vertex들
  int weight;
}Edge;

//graph를 정의
void makeGraph(Edge graph[],int edges){
  for(int i = 0; i< edges;i++){
    printf("Input edge((i,j),Weight): ");
    scanf("%d,%d,%d",&graph[i].i,&graph[i].j,&graph[i].weight);
  }
}

//생성한 minimum spanning tree를 행렬로 프린트
void print(Edge tree[]){
  int matrix[5][5] = {0, };

}

//
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
      
    }
  }
}

void main(int argc, char* argv[]){

}
