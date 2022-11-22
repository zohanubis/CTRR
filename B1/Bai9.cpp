#include "stdio.h"
#define MAXSIZE 50
struct Graph{
	int flag;
	int n;
	int m[MAXSIZE][MAXSIZE];
};
void nhapMaTran(Graph &g);
void ke(Graph g, int v);
int main(){
	Graph g;
	nhapMaTran(g);
	int v;
	printf("\nNhap dinh v: ");scanf("%d",&v);
	ke(g,v);
	return 0;
}
void nhapMaTran(Graph &g){
	printf("Nhap co cua do thi(0 la vo huong, 1 la co huong): ");
	scanf("%d",&g.flag);
	printf("Nhap so luong dinh: ");
	scanf("%d",&g.n);
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			printf("a[%d][%d] = ",i,j);
			scanf("%d",&g.m[i][j]);
		}
	}
}
void ke(Graph g, int v){
	printf("\tDinh ve voi %d la: ",v);
	for(int j = 0; j < g.n; j++){
		if(g.m[v][j] == 1){
			printf("%d ",j);
		}
	}
}
