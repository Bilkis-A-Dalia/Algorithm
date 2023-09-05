#include<bits/stdc++.h>
using namespace std;
int parent[8] = {-1, -1, 1, 1, 6, 4, -1, -1};
int find(int n)//n=node
{
    while(parent[n]!=-1)//value colte thakbe
    {
        n = parent[n];
    }
    return n;
}
int main()
{
    cout << find(6)<<endl;
    cout << find(7)<<endl;
    cout << find(3)<<endl;
    return 0;
}