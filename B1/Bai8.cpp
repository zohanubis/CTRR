#include "stdio.h"
#define MAXSIZE 50
struct Graph{
	int flag;
	int n;
	int m[MAXSIZE][MAXSIZE];
};
void nhapMaTran(Graph &g);
int ghiFile(Graph g, char *fileName);
int main(){
	Graph g;
	nhapMaTran(g);
	char fileName[MAXSIZE] = "output_dsk.txt";
	int result = ghiFile(g,fileName);
	if(result == 1){
		printf("\n\tGhi file thanh cong!");
	}else{
		printf("\n\tGhi file khong thanh cong!");
	}
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
int ghiFile(Graph g, char *fileName){
	FILE *f = fopen(fileName,"wt");
	if(f == NULL){
		return 0;
	}
	fprintf(f,"%d\n",g.flag);
	fprintf(f,"%d\n",g.n);
	for(int i = 0; i < g.n; i++){
		int flag = 0;
		for(int j = 0; j < g.n; j++){
			if(g.m[i][j] == 1 && (i < j)){
				if(flag == 0){
					fprintf(f,"%d ",i);
					flag = 1;
				}
				fprintf(f,"%d ",j);
			}
		}
		fprintf(f,"\n");
	}
	fclose(f);
	return 1;
}
