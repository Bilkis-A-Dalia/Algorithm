//not recursive
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int level[N];

void bfs(int s)//s-source
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;

    while(!q.empty())
    {
        /*pop a node from the queue and insert
        unvisited neighbors of that node*/
        int u = q.front();
        q.pop();
        cout << "visiting node: " << u << endl;

        //section-1:a node start
        for(int v:adj[u])
        {
            //section 2:child push
            if(visited[v]==true) continue;
            q.push(v);
            visited[v] = true;
            //section 3: child pop
            level[v] = level[u] + 1;
        }
        //section 4: end a node(u)
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

    bfs(1);

    for (int i = 1; i <= n;i++)
    {
        cout << "Level of " << i << ":" << level[i] << endl;

    }
        return 0;
}