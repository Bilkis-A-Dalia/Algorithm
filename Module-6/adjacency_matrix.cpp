//Input
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int adjmat[N][N];//global
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++)
    {
        int u, v,w;
        cin >> u >> v >> w ;
        //for weighted
        adjmat[u][v] = w;
        adjmat[v][u] = w;
        //without weighted
        // adjmat[u][v] = 1;//directed
        // adjmat[v][u] = 1;//undirected
    }
    for (int i = 1; i <=n;i++)
    {
        for (int j = 1; j <=n;j++)
        {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}