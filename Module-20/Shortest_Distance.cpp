#include <bits/stdc++.h>
using namespace std;
const long long int INF = LONG_MAX;

int main()
{
    long long int n, e;
    cin >> n >> e;
    long long int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        long long int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] < INF && dis[k][j] < INF)
                {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
    }

    int p;
    cin >> p;
    while (p--)
    {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF)
            cout << -1 << endl;
        else cout << dis[a][b] << endl;
    }
    return 0;
}
