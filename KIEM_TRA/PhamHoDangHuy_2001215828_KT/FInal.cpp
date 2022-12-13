#include "stdio.h"
#include"stdlib.h"
#include "conio.h"
#define MAX 50
struct Graph
{
	int flag;
	int n;
	int m[MAX][MAX];
};
struct Canh
{
	int u, v, w;
};
struct DanhSachCanh
{
	Canh data[MAX];
	int n;
};
struct DanhSachDinh
{
	int dinh;
	int bac;
};
int n;
void khoiTaoMaTrix(Graph &g);
void xuatMaTran(Graph g);
void docFile(DanhSachCanh &dsc);
void xuatMaTranTrongSo(Graph &g, DanhSachCanh dsc);
void ghiFileCanhCoTrongSoMin(DanhSachCanh dsc);
void sapXep(DanhSachCanh &dsc);
void tinhBac(Graph &g, DanhSachDinh dsDinh[]);
void xuatTangSoBac(Graph &g, DanhSachDinh dsDinh[]);
void xuatDinhKeChung(Graph &g, int u, int v);

int main()
{
	Graph g;
	DanhSachCanh dsc;
	DanhSachDinh dsDinh[MAX];
	docFile(dsc);
	xuatMaTranTrongSo(g, dsc);
	ghiFileCanhCoTrongSoMin(dsc);
	int u, v;
	printf("\nNhap u , v");
	xuatDinhKeChung(g, u, v);
	//tinhBac(g, dsDinh);
	//xuatTangSoBac(g, dsDinh); 
	return 0;
}
void docFile(DanhSachCanh &dsc)
{
	FILE *f = fopen("g.txt", "rt");
	if (f == NULL)
	{
		printf("\n\tFile ko ton tai");
		return;
	}
	else{
		fscanf(f, "%d", &dsc.n);
		for (int i = 0; i < dsc.n; i++)
		{
			fscanf(f, "%d%d%d", &dsc.data[i].u, &dsc.data[i].v, &dsc.data[i].w);
		}
	}
}
void khoiTaoMaTrix(Graph &g)
{
	for (int i = 1; i <= g.n; i++){
		for (int j = 1; j <= g.n; j++)
		{
			g.m[i][j] = 100;
		}
	}
}
//void xuatMaTran(Graph g)
//{
//	printf("\n\tMa tran : \n");
//	for (int i = 0; i < g.n; i++)
//	{
//		for (int j = 0; j < g.n; j++)
//		{
//			printf("%d\t", g.m[i][j]);
//		}
//	}
//	printf("\n");
//}
void xuatMaTranTrongSo(Graph &g, DanhSachCanh dsc)
{
	int max = dsc.data[0].u;
	for (int i = 0; i < dsc.n; i++)
	{
		if (dsc.data[i].u > max)
		{
			max = dsc.data[i].u;
		}
		if (dsc.data[i].u > max)
		{
			max = dsc.data[i].v;
		}

	}
	g.n = max;
	khoiTaoMaTrix(g);
	for (int i = 0; i < dsc.n; i++)
	{
		g.m[dsc.data[i].u][dsc.data[i].v] = dsc.data[i].w;
		g.m[dsc.data[i].v][dsc.data[i].u] = dsc.data[i].w;
	}
	for (int i = 1; i <= g.n; i++)
	{
		printf("\n");
		for (int j = 1; j <= g.n; j++)
		{
			printf("\t%d", g.m[i][j]);
		}
	}
}
void sapXep(DanhSachCanh &dsc)
{
	Canh temp;
	for (int i = 1; i < dsc.n-1; i++)
	{
		for (int j = i + 1; j < dsc.n; j++)
		{
			if (dsc.data[i].w > dsc.data[j].w){
				temp = dsc.data[i];
				dsc.data[i] = dsc.data[j];
				dsc.data[j] = temp;
			}
		}
	}
}
void ghiFileCanhCoTrongSoMin(DanhSachCanh dsc)
{
	sapXep(dsc);
	int min = dsc.data[0].w;
	FILE *f = fopen("KQ.txt", "w");
	for (int i = 0; i < dsc.n; i++)
	{
		if (dsc.data[i].w == min)
		{
			fprintf(f, "%d %d %d\n", dsc.data[i].u, dsc.data[i].v, dsc.data[i].w);
		}
	}
}
void tinhBac(Graph &g, DanhSachDinh dsDinh[])
{
	for (int i = 1; i <= g.n; i++)
	{
		dsDinh[i].bac = 0;
		dsDinh[i].dinh = i;
		for (int  j = 0; j <= g.n; j++)
		{
			if (g.m[i][j] != 100)
			{
				dsDinh[i].bac++;
			}
		}
	}
}
void xuatTangSoBac(Graph &g, DanhSachDinh dsDinh[]){
	for (int i = 1; i <= g.n - 1; i++)
	{
		for (int j = i + 1; j <= g.n; j++)
		{
			if (dsDinh[i].bac > dsDinh[j].bac){
				int  temp = dsDinh[i].dinh;
				dsDinh[i].dinh = dsDinh[j].dinh;
				dsDinh[j].dinh = temp;
			}
		}
	}
	printf("\nDanh sachh cac dinh sap xep tang theo so bac : ");
	for (int i = 1; i < g.n; i++)
	{
		printf("%d", dsDinh[i].dinh);
	}
}
void xuatDinhKeChung(Graph &g, int u, int v)
{
	printf("Danh sach cac dinh ke chung : ");
	for (int i = 1; i <= g.n; i++)
	{
		if (g.m[u][i] != 100 && g.m[v][i] != 100)
		{
			printf("%d", i);
		}
	}
}