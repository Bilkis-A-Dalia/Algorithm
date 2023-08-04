#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    int l=0,r=n-1,t,mid;
    cin >> t;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] == t && a[mid+1]==t)
        {
            cout << "YES" << endl;
            return 0;
        }
        else if (a[mid] > t)
            r = mid - 1;
        else
            l = mid + l;
    }
    cout << "NO" << endl;
    return 0;
}
