#include "stdio.h"
#include "conio.h"
#define MAXSIZE 50
struct Graph{
	int flag;
	int n;
	int m[MAXSIZE][MAXSIZE];
};
void docMaTranKe(Graph &g,char *fileName);
void xuatMaTran(Graph g);
 int main(){
	Graph g;
	char fileName[50] = "input_mtk.txt";
	docMaTranKe(g,fileName);
	xuatMaTran(g);
	getch();
}
void docMaTranKe(Graph &g, char *fileName){
	FILE *f = fopen(fileName,"rt");
	if(f == NULL){
		g.flag = -1;
		printf("\n\tFile khong ton tai!");
		return;
	}
	fscanf(f,"%d",&g.flag);
	fscanf(f,"%d",&g.n);
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			fscanf(f,"%d",&g.m[i][j]);
		}
	}
	fclose(f);
}
void xuatMaTran(Graph g){
	printf("\nMa tran ke:\n");
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			printf("%d\t",g.m[i][j]);
		}
		printf("\n");
	}
}