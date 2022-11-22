#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define vmax 20
struct DoThi{
	int flag;
	int n;
	int w[vmax][vmax];
};
struct Canh{
	int u,v;
};
struct SNode{
	int info;
	SNode *next;
};
struct Stack{
	SNode *top;
};
SNode *createSNode(int x){
	SNode *p = new SNode;
	if(p == NULL){
		printf("\nKhong du bo nho de cap phat!");
		return NULL;
	}
	p->info = x;
	p->next = NULL;
	return p;
}
int chuaxet[100];
void docFile(DoThi &g, char *fileName);
void xuatDoThi(DoThi g);
void xuatCayKhung(Canh T[], int soCanh);
void initStack(Stack &s);
int isEmpty(Stack s);
void push(Stack &s, int x);
int pop(Stack &s);
void xayDungCayKhungDFSKhongDeQuy(DoThi g, Canh T[], int &soCanh, int u);
void xayDungCayKhungBFS(DoThi g, Canh T[], int &soCanh);
void menu();
int main(){
	menu();
	getch();
}
void menu(){
	char fileName[50] = "dt_vohuong_1.txt";
	DoThi g;
	docFile(g,fileName);
	if(g.flag == 0){
		printf("Do thi vo huong:\n");
	}else{
		printf("Do thi co huong:\n");
	}
	xuatDoThi(g);
	printf("\n1.DFS khong de quy.");
	printf("\n2.BFS de tim cac cay khung cua do thi.");
	int nhap;
	Canh T[50];
	do{
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: ");
		scanf("%d",&nhap);
		switch(nhap){
			case 1:{
				int soCanh = 0;
				for(int i = 1; i <= g.n; i++){
					chuaxet[i] = 0;
				}
				xayDungCayKhungDFSKhongDeQuy(g,T,soCanh,1);
				break;
			}
			case 2:{
				int soCanh = 0;
				for(int i = 1; i <= g.n; i++){
					chuaxet[i] = 0;
				}
				xayDungCayKhungBFS(g,T,soCanh);
				break;
			}
		}
	}while(nhap != 0);
}
void docFile(DoThi &g, char *fileName){
	FILE *f = fopen(fileName,"rt");
	if(f == NULL){
		printf("\nLoi doc file");
		return;
	}
	fscanf(f,"%d",&g.flag);
	fscanf(f,"%d",&g.n);
	for(int i = 1; i <= g.n; i++){
		for(int j = 1; j <= g.n; j++){
			fscanf(f,"%d",&g.w[i][j]);
		}
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
void initStack(Stack &s){
	s.top = NULL;
}
int isEmpty(Stack s){
	return s.top == NULL ? 1 : 0;
}
void push(Stack &s, int x){
	SNode *p = createSNode(x);
	if(p == NULL){
		return;
	}else{
		if(isEmpty(s)){
			s.top = p;
		}else{
			p->next = s.top;
			s.top = p;
		}
	}
}
int pop(Stack &s){
	if(isEmpty(s)){
		return -1;
	}else{
		SNode *temp = s.top;
		s.top = temp->next;
		temp->next = NULL;
		int x = temp->info;
		delete temp;
		return x;
	}
}
void xayDungCayKhungDFSKhongDeQuy(DoThi g, Canh T[], int &soCanh, int u){
	Stack s;
	initStack(s);
	push(s,u);
	while(!isEmpty(s)){
		u = pop(s);
		chuaxet[u] = 1;
		for(int v = 1; v <= g.n; v++){
			if(g.w[u][v] != 0 && chuaxet[v] == 0){
				soCanh++;
				T[soCanh].u = u;
				T[soCanh].v = v;
				if(soCanh == g.n - 1){
					xuatCayKhung(T,soCanh);
					return;
				}else{
					push(s,v);
					push(s,v);
					break;
				}
			}
		}
	}
}
void xayDungCayKhungBFS(DoThi g, Canh T[], int &soCanh){
	for(int u = 1; u <= g.n; u++){
		for(int v = 1; v <= g.n; v++){
			if(g.w[u][v] != 0 && chuaxet[v] == 0){
				soCanh++;
				T[soCanh].u = u;
				T[soCanh].v = v;
				chuaxet[u] = 1;
				chuaxet[v] = 1;
				if(soCanh == g.n - 1){
					xuatCayKhung(T,soCanh);
					return;
				}
			}
		}
	}
}