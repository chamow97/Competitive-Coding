#include <bits/stdc++.h>
using namespace std;

bool myFunc(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int i,t,n,dp[201];
    cin>>t;
    while(t--)
    {
        cin>>n;
    pair<int, int> a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n,myFunc);
    dp[0] = 0;
    dp[n] = a[n-1].second;
    for(i=n-2;i>=0;i--)
    {
        if(a[i].first < a[i+1].first)
        {
            dp[i+1] = dp[i+2] + a[i].second;
        }
        else
        {
            dp[i+1] = max(dp[i+2], a[i].second);
        }
    }
    cout<<dp[1]<<endl;

    }


    return 0;
}
