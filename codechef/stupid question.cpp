#include<bits/stdc++.h>
using namespace std;
int main()
{
	int dp[26][26],i,j;
	int a[26];
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
	for(i=0;i<=m;i++)
	{
		dp[0][i] = 0;
	}
	for(i=1;i<=n;i++)
	{
		dp[i][0] = 0;
	}

	for(i=1;i<=n;i++)
	{
		for(j=1; j<=m; j++)
		{
			if(i>j || a[i]<j)
			{
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]));
			}
			else
			{
				dp[i][j] = max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+1;
			}
		}
	}
	cout<<dp[n][m];
}
