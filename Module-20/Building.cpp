#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int parSize[N];
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

void dj_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        parSize[i] = 1;
    }
}
int dj_find(int node)
{
    while (par[node] != -1)
    {
        node = par[node];
    }
    return node;
}

void dj_union(int a, int b)
{
    int l1 = dj_find(a);
    int l2 = dj_find(b);
    if (l1 != l2)
    {
        if (parSize[l1] > parSize[l2])
        {
            par[l2] = l1;
            parSize[l1] += parSize[l2];
        }
        else
        {
            par[l1] = l2;
            parSize[l2] += parSize[l1];
        }
    }
}

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int main()
{
    int n, e;
    cin >> n >> e;
    dj_set(n);
    vector<edge> v;
    vector<edge> ans;
    while (e--)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        v.push_back(edge(a, b, w));
    }
    sort(v.begin(), v.end(), cmp);
    int c = 0;
    for (edge val : v)
    {
        int a = val.a;
        int b = val.b;
        int l1 = dj_find(a);
        int l2 = dj_find(b);
        if (l1 == l2) continue;
        ans.push_back(val);
        dj_union(a, b);
        c++;
    }
    long long sum = 0;
    for (edge val : ans)
    {
        sum += val.w;
    }
    if (c != n - 1)
        cout << -1 << endl;
    else
        cout << sum << endl;
    return 0;
}
