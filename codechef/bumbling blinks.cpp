#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,dp[1000001],x,y,maximum=-100000;
    dp[0] = 0;
    dp[1] = 1;
    for(i=2;i<=1000000;i++)
    {
        if((i&1)==1)
        {
            dp[i] = dp[i/2]+1;
        }
        else
        {
            dp[i] = dp[i/2];
        }
    }
    cin>>x>>y;
    for(i=x;i<y;i++)
    {
        maximum = max(maximum,dp[i]);
    }
    cout<<maximum;
}
