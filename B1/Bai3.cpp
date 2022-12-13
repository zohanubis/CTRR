#include "stdio.h"
#include "conio.h"
#define MAXSIZE 50
struct Graph{
	int flag;
	int n;
	int m[MAXSIZE][MAXSIZE];
};
void docDanhSachCanh(Graph &g,char *fileName);
void khoiTaoMaTran(Graph &g);
void xuatMaTran(Graph g);
int main(){
	Graph g;
	char fileName[50] = "input_dsc.txt";
	docDanhSachCanh(g,fileName);
	xuatMaTran(g);
	getch();
}
void docDanhSachCanh(Graph &g, char *fileName){
	FILE *f = fopen(fileName,"rt");
	if( f == NULL){
		g.flag = -1;
		printf("\n\tFile khong ton tai!");
		return;
	}
	fscanf(f,"%d",&g.flag);
	fscanf(f,"%d",&g.n);
	khoiTaoMaTran(g);
	int soCanh;
	fscanf(f,"%d",&soCanh);
	for(int i = 0; i < soCanh; i++){
		int dinhDau,dinhCuoi;
		fscanf(f,"%d%d",&dinhDau,&dinhCuoi);
		g.m[dinhDau][dinhCuoi] = 1;
		if(g.flag == 0){
			g.m[dinhCuoi][dinhDau] = 1;
		}
	}
	fclose(f);
}
void khoiTaoMaTran(Graph &g){
	for(int i = 0; i < g.n; i++){
		for(int j = 0; j < g.n; j++){
			g.m[i][j] = 0;
		}
	}
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