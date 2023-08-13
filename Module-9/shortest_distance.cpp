//not recursive
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];
int parent[N];

void bfs(int s)//s-source-> O(n)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    parent[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u])
        {
            if(visited[v]==true) continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            parent[v] = u;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int s, d;//source,destination
    cin >> s >> d;

    bfs(s);//complixity -> O(n+m)->(node+edge) 
    cout <<"distance: "<< level[d] << endl;

    // for (int i = 1; i <= n;i++)
    // {
    //     cout << "Parent of " << i << ": " << parent[i];
    //     cout << endl;
    // }

    //path finding -> O(n)
    vector<int> path;
    //int current = 0;
    int current = d;
    while(current != -1)
    {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());
    cout << "Path: ";
    for(int node: path)
    {
        cout << node << " ";
    }
    return 0;
}