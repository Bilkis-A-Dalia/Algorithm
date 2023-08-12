#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
vector<int> adj[N];
int level[N];
bool visited[N];

void bfs(int s)//source
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    while(!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v] = true;
            level[v]=level[u]+1;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;  i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int k;
    cin >> k;
    bfs(k);
    int c = 0;
    for (int i = 0; i < n;i++)
    {
        if(level[i]==1)
            c++;
    }
        cout << c << endl;
    return 0;
}