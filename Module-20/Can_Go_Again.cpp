#include <bits/stdc++.h>
using namespace std;
class edge
{
public:
    int a, b;
    long long w;
    edge(int a, int b, long long w)
    {
        this->a = a;
        this->b = b;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<edge> v;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edge ed(a, b, w);
        v.push_back(ed);
    }
    long long dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    int src;
    cin >> src;
    dis[src] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            edge ed = v[j];
            int a = ed.a;
            int b = ed.b;
            long long w = ed.w;
            if (dis[a] + w < dis[b] && dis[a] != LLONG_MAX)
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < v.size(); i++)
    {
        edge ed = v[i];
        int a = ed.a;
        int b = ed.b;
        long long w = ed.w;
        if (dis[a] + w < dis[b] && dis[a] != LLONG_MAX)
        {
            cycle = true;
            break;
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (cycle)
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
        else if (dis[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else cout << dis[d] << endl;
    } 
    return 0;
}
