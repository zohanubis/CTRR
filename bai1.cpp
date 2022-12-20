#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct Graph{
	int n;
	int w[100][100];
};
void docFile(Graph &g, char tenFile[])
{
	FILE* f = fopen(tenFile, "rt");
	if (f != NULL)
	{
		fscanf(f, "%d\n", &g.n);
		for (int i = 1; i <= g.n;i++)
			for (int j = 1; j <= g.n; j++)
				fscanf(f, "%d", &g.w[i][j]);
	}
	fclose(f);
}
// cau1
int soCanh(Graph g)
{
	int dem = 0;
	for (int i = 1; i <= g.n;i++)
		for (int j = 1; j <= g.n;j++)
			if (g.w[i][j]>0 && g.w[i][j]<100)
			{
				dem++;
				g.w[i][j] = g.w[j][i] = 0;
			}
		return dem;
}
// cau2
void bacCanh(int bac[100], Graph g)
{
	for (int i = 1; i <= g.n;i++)
		for (int j = 1; j <= g.n;j++)
			if (g.w[i][j] > 0 && g.w[i][j] < 100)
				bac[i]++;
}
void xuatBacCanh(int bac[], Graph g,char tenFile[])
{
	FILE*f = fopen(tenFile, "wt");
	for (int i = 1; i <= g.n; i++)
		fprintf(f, "%d bac %d\n", i, bac[i]);
	fclose(f);
}
// cau3
void xuatKe(Graph g)
{
	for (int i = 1; i <= g.n; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= g.n; j++)
			if (g.w[i][j] > 0 && g.w[i][j] < 100)
				printf("%d ",j);
		printf("\n");
	}
}
void DFS(int x, Graph g, int chuaxet[])
{
	chuaxet[x] = 1;
	for (int i = 1; i <= g.n;i++)
		if (g.w[i][x]>0 && g.w[i][x] < 100 && chuaxet[i] == 0)
			DFS(i, g, chuaxet);
}
//cau 4
void DSCacDinhLienThong(Graph g, int x)
{
	int chuaxet[100] = { '0' };
	DFS(x, g, chuaxet);
	for (int i = 1; i <= g.n;i++)
		if (chuaxet[i] == 1)
			printf("%d ", i);
}
// cau5
bool ktLienThong(Graph g, int n,int a[])
{
	int chuaxet[100] = { '0' };
	DFS(a[1], g, chuaxet);
	for (int i = 1; i <= n;i++)
		if (chuaxet[a[i]] == 0)
			return false;
	return true;
}
// cau 6
//cau 7
struct DiaDiem{
	int n;
	char ten[30];
};
void DSCacDiaDiem(char ten[10], Graph g, char TenFile[],DiaDiem dd[])
{
	FILE* f = fopen(TenFile, "rt");
	int chuaxet[100] = { '0' };
	if (f != NULL)
	{
		for (int i = 1; i <= g.n; i++)
		{
			fflush(stdin);
			fscanf(f, "%d%s\n", dd[i].n, dd[i].ten);
		}
	}
	else
		printf("Khong tim thay file\n");
	for (int i = 1; i <= g.n; i++)
		puts(dd[i].ten);
	fclose(f);
	for (int i = 1; i <= g.n;i++)
		if (strcmp(ten, dd[i].ten) == 0)
			DFS(i, g, chuaxet);
	printf("%s: ", ten);
	for (int i = 0; i <= g.n; i++)
		if (chuaxet[i] == 1)
			printf("%s, ", dd[i].ten);
}
void DemTPLT(Graph g, char tenFile[])
{
	FILE *f = fopen(tenFile, "wt");
	
}
void main()
{
	Graph g;
	DiaDiem dd[100];
	int bac[100] = { '0' };
	int x, n, a[100],dinh;
	docFile(g, "G.txt");
	// cau 1
	printf("Do thi co %d canh\n", soCanh(g));
	// cau 2
	bacCanh(bac, g);
	xuatBacCanh(bac, g, "BAC.txt");
	// au 3
	xuatKe(g);
	// cau 4
	printf("Nhap x: ");
	scanf("%d", &x);
	printf("Cac dinh lien thong x\n");
	DSCacDinhLienThong(g, x);
	// cau 5
	printf("Nhap n: ");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	if (ktLienThong(g, n, a))
		printf("Cac dinh lien thong nhau\n");
	else
		printf("Cac dinh khong lien thong nhau\n");
	char tendd[30];
	printf("Nhap ten dia diem: ");
	fflush(stdin);
	scanf("%s", tendd);
	DSCacDiaDiem(tendd, g, "DiaDiem.txt", dd);
	system("pause");
}
