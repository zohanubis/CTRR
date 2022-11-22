#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define vmax 20
struct DoThi{
	int n;
	int w[vmax][vmax];
};
struct Canh{
	int u,v;
};
int chuaxet[100];
void khoiTaoMaTran(DoThi &g);
void docFile(DoThi &g, Canh T[], char *fileName);
void xuatDoThi(DoThi g);
void xuatCayKhung(Canh T[], int soCanh);
void xayDungCayKhungBFS(DoThi g, Canh T[], int &soCanh);
int ghiFile(Canh T[], int soCanh, char *fileName);
int main(){
	char fileName[50] = "BridgeIn.txt";
	DoThi g;
	Canh T[50];
	docFile(g,T,fileName);
	int soCanh = 0;
	for(int i = 1; i <= g.n; i++){
		chuaxet[i] = 0;
	}
	printf("Do thi vo huong:\n");
	xuatDoThi(g);
	getch();
}
void khoiTaoMaTran(DoThi &g){
	for(int i = 1; i <=g.n; i++){
		for(int j = 1; j <= g.n; j++){
			g.w[i][j] = 0;
		}
	}
}
void docFile(DoThi &g,Canh T[], char *fileName){
	FILE *f = fopen(fileName,"rt");
	if(f == NULL){
		printf("\nLoi doc file");
		return;
	}
	fscanf(f,"%d",&g.n);
	khoiTaoMaTran(g);
	int dinhDau;
	int dinhCuoi;
	for(int i = 1; i <= g.n; i++){
		fscanf(f,"%d%d",&dinhDau,&dinhCuoi);
		g.w[dinhDau][dinhCuoi] = 1;
		g.w[dinhCuoi][dinhDau] = 1;
	}
}
void xuatDoThi(DoThi g){
	for(int i = 1; i <= g.n; i++){
		for(int j = 1; j <= g.n; j++){
			printf("\t%d",g.w[i][j]);
		}
		printf("\n");
	}
}
void xuatCayKhung(Canh T[], int soCanh){
	printf("\nCay khung la: \n");
	for(int i = 1; i <= soCanh; i++){
		printf("\t(%d, %d)",T[i].u,T[i].v);
	}
}
int ghiFile(Canh T[],int soCanh, char *fileName){
	FILE *f = fopen(fileName,"wt");
	fprintf(f,"%d\n",soCanh);
	for(int i = 1; i <= soCanh; i++){
		fprintf(f,"%d %d\n",T[i].u,T[i].v);
	}
	return 1;
}