#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
bool visited[N][N];
char a[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n,m;

bool isValid(int p,int q)
{
    if(p>=0 && p<n && q>=0 && q<m && a[p][q]=='.')
        return true;
    else
        return false;
}

void bfs(int s,int t)
{
    queue<pii> q;
    visited[s][t] = true;
    q.push({s, t});
    while(!q.empty())
    {
        pii parent = q.front();
        int d1 = parent.first;
        int d2 = parent.second;
        q.pop();
        for (int i = 0; i < 4;i++)
        {
            pii child = path[i];
            int d3 = d1 + child.first;
            int d4 = d2 + child.second;
            if(isValid(d3,d4) && !visited[d3][d4])
            {
                visited[d3][d4] = true;
                q.push({d3, d4});
            }
        }
    }
    
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> a[i][j];
        }
    }
    int a, b, a2, b2;
    cin >> a >> b >> a2 >> b2;
    bfs(a,b);
    
    if(visited[a2][b2])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
    return 0;
}