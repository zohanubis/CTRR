#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAX 20
struct Graph{
	int n;
	int w[MAX][MAX];
};
struct Edge{
	int u,v;
};
int visited[100];
void readFile(Graph &g, char *fileName);
void outputGraph(Graph g);
void outputCayKhung(Edge T[], int noEdge);
void xayDungCayKhungBFS(Graph g, Edge T[], int &noEdge);
int ghiFile(Edge T[], int noEdge, char *fileName);
int main(){
	char fileName[50] = "BridgeIn.txt";
	Graph g;
	readFile(g,fileName);
	Edge T[50];
	int noEdge = 0;
	for(int i = 1; i <= g.n; i++){
		visited[i] = 0;
	}
	printf("Do thi vo huong:\n");
	outputGraph(g);
	xayDungCayKhungBFS(g,T,noEdge);
	char fileName2[50] = "BridgeOut.txt";
	int result = ghiFile(T,noEdge,fileName2);
	if(result == 1){
		printf("\n\tGhi file thanh cong!");
	}else{
		printf("\n\tGhi file khong thanh cong!");
	}
	getch();
}
void readFile(Graph &g, char *fileName){
	FILE *f = fopen(fileName,"rt");
	if(f == NULL){
		printf("\nError");
		return;
	}
	fscanf(f,"%d",&g.n);
	for(int i = 1; i <= g.n; i++){
		for(int j = 1; j <= g.n; j++){
			fscanf(f,"%d",&g.w[i][j]);
		}
	}
}
void outputGraph(Graph g){
	for(int i = 1; i <= g.n; i++){
		for(int j = 1; j <= g.n; j++){
			printf("\t%d",g.w[i][j]);
		}
		printf("\n");
	}
}
void outputCayKhung(Edge T[], int noEdge){
	printf("\nCay khung la: \n");
	for(int i = 1; i <= noEdge; i++){
		printf("\t(%d, %d)",T[i].u,T[i].v);
	}
}
void xayDungCayKhungBFS(Graph g, Edge T[], int &noEdge){
	for(int u = 1; u <= g.n; u++){
		for(int v = 1; v <= g.n; v++){
			if(g.w[u][v] != 0 && visited[v] == 0){
				noEdge++;
				T[noEdge].u = u;
				T[noEdge].v = v;
				visited[u] = 1;
				visited[v] = 1;
				if(noEdge == g.n - 1){
					outputCayKhung(T,noEdge);
					return;
				}
			}
		}
	}
}
int ghiFile(Edge T[],int noEdge, char *fileName){
	FILE *f = fopen(fileName,"wt");
	fprintf(f,"%d\n",noEdge);
	for(int i = 1; i <= noEdge; i++){
		fprintf(f,"%d %d\n",T[i].u,T[i].v);
	}
	return 1;
}