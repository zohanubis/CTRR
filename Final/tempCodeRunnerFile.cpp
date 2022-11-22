#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#define MAX 20
struct Graph
{
    int flag; // loại đồ thị : 0 là vô hướng , 1 là có hướng
    int n; // số đỉnh
    int w[MAX][MAX]; // ma trận kề hoặc trọng số
};
struct canh
{
    int u,v;
};
int chuaXet[100]; // Đánh dấu các đỉnh đã xét hay chưa, đầu tiên khởi tạo các đỉnh chưa xét
void readFile(Graph &g)
{
    FILE *f = fopen("graph.txt","rt");
    if (f == NULL)
    {
        printf("\nKhong tim thay file");
    }
    else{
        fscanf(f,"%d",&g.flag);
        fscanf(f,"%d",&g.n);
        for (int i = 1; i < g.n; i++)
        {
            for (int j = 1; j < g.n; j++)
            {
                fscanf(f,"%d",&g.w[i][j]);
            }
        }
    }
}
void outputGraph(Graph g)
{
    if (g.flag == 0)
    {
        printf("\nDo thi vo huong");
    }
    else
        {
            printf("\nDo thi co huong");
            printf("\nMa tran ke hoac ma tran trong so cua do thi:");
        }
        for (int i = 1; i <= g.n; i++)
        {
            printf("\n");
            for (int j = 1; j <= g.n; j++)
            {
                printf("%5d", g.w[i][j]);
            }
        }
}
void outputCayKhung(canh T[], int soCanh)
{
    printf("\nCay khung nho nhat \n");
    for (int i = 1; i <= soCanh; i++)
    {
        printf("\t(%d,%d)",T[i].u,T[i].v);
    }
}
void xayDungCayKhungBFS(Graph g,canh T[], int &soCanh)
{
    for (int u = 1; u <= g.n; u++)
    {
        for (int v = 1; v <= g.n; v++)
        {
            if (g.w[u][v] != 0 && chuaXet[v] == 0)
            {
                soCanh++;
                T[soCanh].u = u;
                T[soCanh].v = v;
                chuaXet[v] = 1;
                chuaXet[u] = 1;
                printf("\n(%d,%d)",T[soCanh].u, T[soCanh].v);
                if (soCanh == g.n -1)
                {
                    outputCayKhung(T,soCanh);
                    return;
                }
            }
        }
    }
}
int main(){
    Graph g;
    readFile(g);
    canh T[MAX];
    outputGraph(g);
    int soCanh = 0;
    for (int i = 0; i < g.n; i++)
    {
        chuaXet[i] =0;
    }
    soCanh =0;
    outputCayKhung(T,soCanh);
    printf("\n\tCay Khung BFS : \n");
    xayDungCayKhungBFS(g,T,soCanh);
}