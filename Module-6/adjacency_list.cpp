#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
//vector<int> adjli[N];
//for weighted
vector<pair<int, int>> adjli[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++)
    {
        int u, v,w;
        cin >> u >> v>>w;
        adjli[u].push_back({v,w});//directed
        //adjli[v].push_back(u);//undirected
    }

    for (int i = 1; i <= n;i++)
    {
        cout << "List " << i << ": ";
        for(auto j:adjli[i])
        {
            cout << "(" << j.first;
           cout << ", "<<j.second<<"),";
        }
        cout << endl;
    }

        return 0;
}