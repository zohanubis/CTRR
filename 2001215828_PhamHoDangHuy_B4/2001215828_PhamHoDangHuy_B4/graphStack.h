
#include <iostream>
#include "thaoTacStack.h"
#ifndef duyetGraphStack
#define duyetGraphStack
using namespace std;
#define TRUE 1
#define FALSE 0
#define MAX 100
int soTPLienThong = 1, n;
int a[MAX][MAX];
bool visit[MAX];
void initStack(Stack &q);
bool isEmptyStack(Stack q);
void pushStack(Stack &q, int v);
int popStack(Stack &q);
void initVisit();

void initStack(Stack &q);
bool isEmptyStack(Stack q);
void pushStack(Stack &q, int v);
int popStack(Stack &q);
void initVisit(){
	for (int i = 0; i <= n; ++i){
		visit[i] = FALSE;
	}
}
void duyetGraphDFS(int v){
	Stack P;
	initStack(P);
	visit[v] = true;
	pushStack(P, v);
	int i;
	while (!isEmptyStack(P))
	{
		v = P->top;
		for (int i = 1; i < n; ++i)
		{
			if (a[i][v] != 0 && visit[i] == FALSE)
			{
				pushStack(P, i);
				visit[i] = TRUE;
				v = i; 
				i = -1;
			}
		}
		popStack(P);
	}
}
bool kiemTraLienThong(){
	for (int i = 1; i < n; i++)
	{
		if (visit[i] == FALSE){
			return FALSE;
		}
	FALSE;
	}
	return TRUE;
}
#endif