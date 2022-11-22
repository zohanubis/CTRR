#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define vmax 20
struct Graph{
	int flag;
	int n;
	int w[vmax][vmax];
};
struct Edge{
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
void readFile(Graph &g, char *fileName);
void outputGraph(Graph g);
void outputCayKhung(Edge T[], int noEdge);
void initStack(Stack &s);
int isEmpty(Stack s);
void push(Stack &s, int x);
int pop(Stack &s);
void xayDungCayKhungDFSKhongDeQuy(Graph g, Edge T[], int &noEdge, int u);
void xayDungCayKhungBFS(Graph g, Edge T[], int &noEdge);
void menu();
int main(){
	menu();
	getch();
}
void menu(){
	char fileName[50] = "graph.txt";
	Graph g;
	readFile(g,fileName);
	if(g.flag == 0){
		printf("Do thi vo huong:\n");
	}else{
		printf("Do thi co huong:\n");
	}
	outputGraph(g);
	printf("\n1.DFS khong de quy.");
	printf("\n2.BFS de tim cac cay khung cua do thi.");
	int nhap;
	Edge T[50];
	do{
		printf("\n\nNhap 0 de thoat!");
		printf("\nNhap thao tac muon thuc hien: ");
		scanf("%d",&nhap);
		switch(nhap){
			case 1:{
				int noEdge = 0;
				for(int i = 1; i <= g.n; i++){
					chuaxet[i] = 0;
				}
				xayDungCayKhungDFSKhongDeQuy(g,T,noEdge,1);
				break;
			}
			case 2:{
				int noEdge = 0;
				for(int i = 1; i <= g.n; i++){
					chuaxet[i] = 0;
				}
				xayDungCayKhungBFS(g,T,noEdge);
				break;
			}
		}
	}while(nhap != 0);
}
void readFile(Graph &g, char *fileName){
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
void xayDungCayKhungDFSKhongDeQuy(Graph g, Edge T[], int &noEdge, int u){
	Stack s;
	initStack(s);
	push(s,u);
	while(!isEmpty(s)){
		u = pop(s);
		chuaxet[u] = 1;
		for(int v = 1; v <= g.n; v++){
			if(g.w[u][v] != 0 && chuaxet[v] == 0){
				noEdge++;
				T[noEdge].u = u;
				T[noEdge].v = v;
				if(noEdge == g.n - 1){
					outputCayKhung(T,noEdge);
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
void xayDungCayKhungBFS(Graph g, Edge T[], int &noEdge){
	for(int u = 1; u <= g.n; u++){
		for(int v = 1; v <= g.n; v++){
			if(g.w[u][v] != 0 && chuaxet[v] == 0){
				noEdge++;
				T[noEdge].u = u;
				T[noEdge].v = v;
				chuaxet[u] = 1;
				chuaxet[v] = 1;
				if(noEdge == g.n - 1){
					outputCayKhung(T,noEdge);
					return;
				}
			}
		}
	}
}