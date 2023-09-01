#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int par[N];
int parSize[N];

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

int main()
{
    long long n, e;
    int c = 0;
    cin >> n >> e;
	dj_set(n);
	while (e--)
    {
	    int a, b;
        cin >> a >> b;
        int l3 = dj_find(a);
        int l4 = dj_find(b);
        if (l3 == l4)
        {
           c++;
        }
        dj_union(a, b);
    }
    cout << c << endl;
	    return 0;
}
