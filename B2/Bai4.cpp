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
int demThanhPhanLienThongDFS(DoThi g, Canh T[], int &soCanh, int u);
int ghiFile(int soCanh, char *fileName);
int main(){
	char fileName[50] = "HamIn.txt";
	DoThi g;
	Canh T[50];
	docFile(g,T,fileName);
	printf("Do thi vo huong:\n");
	xuatDoThi(g);
	int soCanh = 0;
	for(int i = 1; i <= g.n; i++){
		chuaxet[i] = 0;
	}
	int tongThanhPhanLienThong = 0;
	for (int i = 1; i <= g.n; i++) {
		tongThanhPhanLienThong += demThanhPhanLienThongDFS(g, T, soCanh, i);
	}
	tongThanhPhanLienThong = tongThanhPhanLienThong - 1;
	printf("So duong ham it nhat can xay dung them la: %d", tongThanhPhanLienThong);
	char fileName2[50] = "HamOut.txt";
	int result = ghiFile(tongThanhPhanLienThong, fileName2);
	if (result == 1) {
		printf("\nGhi file thanh cong!");
	}else{
		printf("\nGhi file khong thanh cong!");
	}
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
int demThanhPhanLienThongDFS(DoThi g, Canh T[], int& soCanh, int u) {
	int flag = 0;
	chuaxet[u] = 1;
	for (int v = 1; v <= g.n; v++) {
		if (g.w[u][v] != 0 && chuaxet[v] == 0) {
			flag = 1;
			soCanh++;
			T[soCanh].u = u;
			T[soCanh].v = v;
			if (soCanh == g.n - 1) {
				return 0;
			}
			else {
				demThanhPhanLienThongDFS(g, T, soCanh, v);
			}
		}
	}
	return flag;
}
int ghiFile(int tongThanhPhanLienThong, char *fileName){
	FILE *f = fopen(fileName,"wt");
	fprintf(f,"%d\n",tongThanhPhanLienThong);
	return 1;
}