#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
const int INF = INT_MAX;
vector<pii> g[N];
long long int k[N];
long long int n, m;

void bellman(int a)
{
    for (int i = 1; i <= n;i++)
    {
        k[i] = INF;
    }
    k[a] = 0;
    for (int i = 1; i <= n;i++)
    {
        for (int u = 1; u <= n;u++)
        {
            for(pii vpair:g[u])
            {
                int v = vpair.first;
                int w = vpair.second;
                if(k[u]!=INF && k[v]>k[u]+w)
                {
                    k[v] = k[u] + w;
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    while(m--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});

    }
    int a, b;
    cin >> a>>b;
    bellman(a);
    while(b--)
    {
        long long int p, q;
        cin >> p >> q;
        if(k[p]<=q)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}