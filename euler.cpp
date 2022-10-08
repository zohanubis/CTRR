#include "bits/stdc++.h"
using namespace std;

ussing ll = long long;
int n, m;
set<int>adj[1001];
int degree[1001];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y ; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}
int main()
{
    #ifdef ONLINE_JUDGE
    
    #endif // ONLINE_JUDGE
}
