#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define vc 100
#define vmax 20

struct dothi
{
	int flag; 
	int n; 
	int w[100][100];
};
int chuaxet[vmax];
void docfile(dothi &g)
{
	FILE *f = fopen("data.txt", "r");
	if (f == NULL)
		printf("\nKhong tim thay file");
	else
	{
		fscanf(f, "%d", &g.flag);
		fscanf(f, "%d", &g.n);
		for (int i = 1; i <= g.n; i++)
			for (int j = 1; j <= g.n; j++)
				fscanf(f, "%d", &g.w[i][j]);
}
}
void xuatdothi(dothi g)
{
if (g.flag == 0)
printf("\nDo thi vo huong");
else
printf("\nDo thi co huong");
printf("\nMa tran ke hoac ma tran trong so cua do thi:");
for (int i = 1; i <= g.n; i++)
{
printf("\n");
for (int j = 1; j <= g.n; j++)
printf("%5d", g.w[i][j]);
}
}

struct prim
{
	int dinh;
	int chiphi;
};

void xuatbangchiphi(dothi g, prim bangchiphi[100][100])
{
	printf("\nBang mo ta thuat toan Prim tim cay khung nho nhat \n");
	for (int i = 1; i <= g.n; i++)
		printf("%10d", i);
	for (int i = 0; i <= g.n; i++)
	{
		printf("\n----------------------------------------------------\n");
		for (int j = 1; j <= g.n; j++)
			printf("\t(%d, %d)", bangchiphi[i][j].dinh, bangchiphi[i][j].chiphi);
	}
}

void xuatcaykhung(dothi g, prim bangchiphi[100][100])
{
	printf("\nDanh sach cac canh thuoc cay khung nho nhat.\n");
	int i = 2;
	while (i <= g.n)
	{
		printf("\t(%d, %d)", bangchiphi[g.n][i].dinh, i);
		i++;
	}
}

void Prim(dothi g, prim bangchiphi[100][100], int dinhkhoidau)
{
	int chuaxet[vmax];


	for(int i = 1; i <= g.n; i++)
	{	 
		chuaxet[i] = 0;
		bangchiphi[0][i].chiphi = vc;
		bangchiphi[0][i].dinh = 0;
	}
	bangchiphi[0][dinhkhoidau].chiphi = 0;
	bangchiphi[0][dinhkhoidau].dinh = 0;
	int i = 0;
	while(i < g.n)
	{
		int chondinh_min = 1;
		while (chuaxet[chondinh_min] == 1)
			chondinh_min++;
		for (int j = 1; j < g.n; j++)
		{
			if (chuaxet[j] == 0 && bangchiphi[i][j].chiphi < bangchiphi[i][chondinh_min].chiphi)
				chondinh_min = j;
		}

		chuaxet[chondinh_min] = 1;
		i++;
		for (int j = 1; j <= g.n; j++)
		{
			if (chuaxet[j] == 1 || g.w[chondinh_min][j] == vc)
				bangchiphi[i][j] = bangchiphi[i - 1][j];
			if (chondinh_min != j && chuaxet[j] == 0 && g.w[chondinh_min][j] < vc)
				if (bangchiphi[i - 1][j].chiphi > g.w[chondinh_min][j])
				{
					bangchiphi[i][j].chiphi = g.w[chondinh_min][j];
					bangchiphi[i][j].dinh = chondinh_min;
				}
			else
				bangchiphi[i][j] = bangchiphi[i - 1][j];

		}
	}
}
int main()
{
	dothi g;
	docfile(g);
	xuatdothi(g);
	prim bangchiphi[100][100];
	Prim(g, bangchiphi, 1);
	xuatbangchiphi(g,bangchiphi);
	xuatcaykhung(g, bangchiphi);
	return 0;
}

