#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int parentLevel[1000];
void dsu_set(int node)//node
{
    for (int i = 1; i <= node;i++)
    {
        parent[i] = -1;
        parentLevel[i] = 0;//initial level 
    }
}

int dsu_find(int node)//n=node
{
    while(parent[node]!=-1)//value colte thakbe
    {
        node = parent[node];
    }
    return node;
}

void dsu_union(int a,int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if(leaderA != leaderB)
    {
        if(parentLevel[leaderA]>parentLevel[leaderB])
        {
            parent[leaderB] = leaderA;
        }
        else if(parentLevel[leaderB]>parentLevel[leaderA])
        {
            parent[leaderA] = leaderB;
        }
        else
        {
            parent[leaderB] = leaderA;
            parentLevel[leaderA]++;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    dsu_set(n);
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if(leaderA==leaderB)
        {
            cout << "Cycle detected in between: " << a << " " << b << endl;
        }
        else
        {
            dsu_union(a, b);//connecting
        }
    }
    return 0;
}