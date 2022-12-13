#include "stdio.h"
#include "stdlib.h"
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3

int n;   
int adj[MAX][MAX]; 
int state[MAX]; 

void createGraph(); 
void BF_Traversal();
void BFS(int v);

int queue[MAX], front = -1,rear = -1;
void insert_queue(int vertex);
int delete_queue();
int isEmpty();

int main()
{
        createGraph();
        BF_Traversal();

        return 0;

}

void BF_Traversal()
{
        int v;
        int connected = 1;
        for(v=0; v<n; v++)
                state[v] = initial;
        BFS(0); 
        for(v=0; v<n; v++)
        {
                if(state[v] == initial)
                {
                        connected = 0;
                        break;
                }
        }

        if(connected)
        printf("\nDo thi co chu trinh\n");
        else
        printf("\nDo thi khong co chu trinh\n");
}
void BFS(int v)
{
        int i;

        insert_queue(v);
        state[v] = waiting;

        while( !isEmpty_queue() )
        {
                v = delete_queue( );
                state[v] = visited;
                printf("%d ",v);

                for(i=0;i<=n - 1; i++)
                { 
                        if( adj[v][i] == 1 && state[i] == initial)
                        {
                                insert_queue(i);
                                state[i] = waiting;
                        }
                }
        }
        printf("\n");
}

void insert_queue(int vertex)
{
        if(rear == MAX-1)
                printf("\nQueue Overflow\n");
        else
        {
                if(front == -1)  
                        front = 0;
                rear = rear+1;
                queue[rear] = vertex ;
        }
}

int isEmpty_queue()
{
        if(front == -1 || front > rear )
                return 1;
        else
                return 0;
}

int delete_queue()
{
        int del_item;
        if (front == -1 || front > rear)
        {
                printf("\nQueue Underflow\n");
                exit(1);
        }

        del_item = queue[front];
        front = front+1;
        return del_item;

}

void createGraph()
{
        int i,max_edges,origin,destin;

        printf("\nNhap so dinh : ");
        scanf("%d",&n);
        max_edges = n*(n-1)/2;

        for(i=1; i<=max_edges; i++)
        {
                printf("\nNhap canh %d( -1 -1 de ket thuc, Dinh bat dau tu 0) : ",i);
                scanf("%d %d",&origin,&destin);

                if((origin == -1) && (destin == -1))
                        break;

                if( origin >= n || destin >= n || origin<0 || destin<0)
                {
                        printf("\nCanh khong hop le!\n");
                        i--;
                }
                else
                {
                        adj[origin][destin] = 1;
                        adj[destin][origin] = 1;
                }
        }
}
