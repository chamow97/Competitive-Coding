//template by chamow

#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll readInt () {
	bool minus = false;
	ll result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}
int main()
{
    ll t,n,k,a[100001],dp[100001],maximum = 0;
    t = readInt();
    while(t--)
    {
        maximum = 0;
        n = readInt();
        k = readInt();
        rep(i,1,n+1)
        {
            a[i] = readInt();
            dp[i] = 0;
        }
        dp[0] = 0;
        rep(i,1,n+1)
        {
            if(a[i] <= k)
            {
                dp[i] = dp[i-1] + a[i];
            }
            else
            {
                dp[i] = 0;
            }
        }
        rep(i,1,n+1)
        {
            maximum = max(dp[i], maximum);
        }
        cout<<maximum<<endl;
    }

    return 0;
}
