#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin >> node >> edge;
    vector<int> adj[node + 1];
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i <= node;i++)
    {
        cout << "Index" << i << ": ";
        for (int j = 0; j < adj[i].size();j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
        return 0;
}