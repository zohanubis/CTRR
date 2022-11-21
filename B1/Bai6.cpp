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
void timBac(int m[MAXSIZE][MAXSIZE], int n, int k);
int timBac(Graph g, int k);
int main(){
	Graph g;
	int m,n,flag, k;
	char fileName[50] = "input_mtk.txt";
	docMaTranKe(g,fileName);
	xuatMaTran(g);
	int k = 0;
	int count = timBac(g,k);
	printf("\n\tBac cua dinh : ",count);
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
// void timBac(int m[MAXSIZE][MAXSIZE], int n, int k)
// {
// 	if (k >= 1 && k<= n)
// 	{
// 		int count = 0;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (m[i][k-1] == 1)
// 			{
// 				count++;
// 			}
// 			printf("\n\tBac cua dinh : %d", count);	
// 		}
// 	}
// 	else{
// 				printf("Dinh nhap ko ton tai ");
// 			}
// }
int timBac(Graph g, int k)
{
	int count = 0;
	for (int i = 0; i < g.n; i++)
	{
		if (g.m[k][i] == 1)
		{
			count++;
		}
		
	}
	if (g.m[k][k] == 1)
	{
		count ++;
	}
	return count++;
	
}
// Ma tran ke ra danh sach ke
// Ma tran ke ra danh sach canh