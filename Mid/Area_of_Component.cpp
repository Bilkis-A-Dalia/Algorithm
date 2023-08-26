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

int bfs(int s,int t)
{
        int c = 0;
        queue<pii> q;
        visited[s][t] = true;
        q.push({s, t});
        c++;
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
                c++;
            }
        }
        }
        return c;
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
    int area = INT_MAX;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(a[i][j]=='.' && !visited[i][j])
                area = min(area, bfs(i, j));
        }
    }
    if(area==INT_MAX)
        cout << -1 << endl;
    else
        cout << area << endl;
    return 0;
}