#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e5 + 5;
bool visited[N];
vector<pii> adj[N];
int dist[N];
void dijkstra(int src)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({dist[src], src});// push the src
    while (!pq.empty())
    {
        int parent = pq.top().second;// pop parent 
        pq.pop();                     
        visited[parent] = true;       
        for (pii child : adj[parent]) 
        {
            int childNode = child.first;
            int childCost = child.second;
            if (visited[childNode])// if childNode come 1st then leave it
                continue;
            if (dist[childNode] > dist[parent] + childCost) 
            {
                dist[childNode] = dist[parent] + childCost;
                pq.push({dist[childNode], childNode});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dist[i] = INT_MAX;
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Distance " << i << " : " << dist[i] << endl;
    }

    return 0;
}