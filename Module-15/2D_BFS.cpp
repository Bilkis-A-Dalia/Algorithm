#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e3 + 5;
bool vis[N][N];
int dis[N][N];
vector<pii> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n, m;

bool isValid(int ci,int cj)
{
    if(ci>=0 && ci<n && cj>=0 && cj<m)
        return true;
    else
        return false;
}

void bfs(int si,int sj)
{
    queue<pii> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    vis[si][sj] = true;
    while(!q.empty())
    {
        pii parent = q.front();
        int pi = parent.first;//p=parent
        int pj = parent.second;
        q.pop();
        for (int i = 0; i < 4;i++)
        {
            pii p = path[i];
            int ci = pi + p.first;//c=child
            int cj = pj + p.second;
            //cout << ci << " " << cj << endl;
            if(isValid(ci,cj) && !vis[ci][cj])
            {
                vis[ci][cj]=true;
                q.push({ci, cj});
                dis[ci][cj] = dis[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    char a[n][m];
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }

    int si, sj;
    cin >> si >> sj;
    bfs(si, sj);
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cout << dis[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}