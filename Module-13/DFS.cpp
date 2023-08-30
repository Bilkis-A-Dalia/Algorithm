#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;//N=100005
vector<int> v[N];
bool vis[N];

void dfs(int src)
{
    vis[src] = true;
    cout << src << endl;
    for (int i = 0; i < v[src].size();i++)
    {
        int child = v[src][i];
        if (vis[child]==false)
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1);
        return 0;
}