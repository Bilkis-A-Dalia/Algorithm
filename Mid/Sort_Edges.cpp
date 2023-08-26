#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> d;
    while(n--)
    {
        int u, v;
        cin >> u >> v;
        d.push_back({u, v});

    }
    sort(d.begin(), d.end());
    for(auto v:d)
    {
        cout << v.first << " " << v.second << endl;
    }
    return 0;
}