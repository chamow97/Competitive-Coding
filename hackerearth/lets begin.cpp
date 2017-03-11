#include<bits/stdc++.h>
using namespace std;
int main()
{
    int dp[100001];

    int n = 4;
    int t,x,i,j;
    cin>>t;
    dp[1] = -1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 1;
    dp[6] = 2;
    dp[7] = 1;
    dp[8] = 2;
    dp[9] = 2;
    dp[10] = 2;
    for(i=11;i<=100000;i++)
    {
        dp[i] = min(1+dp[i-7],min(1+dp[i - 5], min(1+dp[i - 3], 1+dp[i-2])));
    }
    while(t--)
    {
        cin>>x;
        cout<<dp[x]<<endl;
    }

}
