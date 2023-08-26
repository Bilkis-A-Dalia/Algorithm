#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 105;
bool visited[N][N];
int level[N][N];
vector<pii> path = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},{2, 1},{2, -1},{-2, 1},{-2, -1}};
int n,m;

void initialization()
{
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            visited[i][j] = false;
            level[i][j]=-1;
        }
    }
}
bool isValid(int p,int q)
{
    if(p>=0 && p<n && q>=0 && q<m)
        return true;
    else
        return false;
}

void bfs(int s,int t)
{
    queue<pii> q;
    visited[s][t] = true;
    level[s][t]=0;
    q.push({s, t});
    while(!q.empty())
    {
        pii parent = q.front();
        int d1 = parent.first;
        int d2 = parent.second;
        q.pop();
        for (int i = 0; i < 8;i++)
        {
            pii child = path[i];
            int d3 = d1 + child.first;
            int d4 = d2 + child.second;
            if(isValid(d3,d4) && !visited[d3][d4])
            {
                visited[d3][d4] = true;
                q.push({d3, d4});
                level[d3][d4]=level[d1][d2]+1;
            }
        }
    }
}
int main()
{
        int t;
        cin >> t;
        while (t--)
        {
            cin >> n >> m;
            int l1, l2, l3, l4;
            cin >> l1 >> l2 >> l3 >> l4;
            initialization();
            bfs(l1, l2);
            cout << level[l3][l4] << endl;
        } 
    return 0;
}