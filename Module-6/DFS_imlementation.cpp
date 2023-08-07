#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool visited[N];

void dfs(int u)
{
    //section-1:actions just after entring node
    visited[u] = true;
    cout << "Visiting node:" << u << endl;

    for(int v:adj[u])
    {
        //section-2:before entring new  neighbor
        //if(visited[v]==false)
        if(visited[v]==true)
            continue;
        dfs(v);
        //section-3:after exiting a neighbor
    }
    //section-4:before exiting node u
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);//directed
        //adj[v].push_back(u);//undirected
    }

    /*for (int i = 1; i <= n;i++)
    {
        cout << "Node" << i << ": ";
        for(int j:adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }*/
    dfs(1);

    //visited na hoile 0.
    cout << "visiting array\n";
    for (int i = 1; i <= n;i++)
    {
        cout << "Node" << i << "Status:" << visited[i] << endl;
    }
        return 0;
}