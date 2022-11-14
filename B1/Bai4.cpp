#include "stdlib.h"
#include "string"
#include "fstream"
#include "conio.h"
#include "sstream"
using namespace std;
#define MAXSIZE 50
struct Graph{
	int flag;
	int n;
	int m[MAXSIZE][MAXSIZE];
};
void docDanhSachKe(Graph &g,char *fileName);
void khoiTaoMaTran(Graph &g);
void xuatMaTran(Graph g);
void main(){
	Graph g;
	char fileName[50] = "input_dsk.txt";
	docDanhSachKe(g,fileName);
	xuatMaTran(g);
	getch();
}
void docDanhSachKe(Graph &g, char *fileName){
	ifstream fileIn;
	fileIn.open(fileName, ios::in);
	if(fileIn.fail()){
		g.flag = -1;
		printf("\n\tFile khong ton tai!");
		return;
	}
	fileIn >> g.flag;
	int n;
	fileIn >> n;
	g.n = n;
	khoiTaoMaTran(g);
	string line;
	while(getline(fileIn, line)){
		stringstream stream(line);
		int dinhDau;
		stream >> dinhDau;
		while(1){
			int dinhCuoi;
			stream >> dinhCuoi;
			if(!stream) break;
			g.m[dinhDau][dinhCuoi] = 1;
			if(g.flag == 0){
				g.m[dinhCuoi][dinhDau] = 1;
			}
		}
	}
	fileIn.close();
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
			printf("%d ",g.m[i][j]);
		}
		printf("\n");
	}
}