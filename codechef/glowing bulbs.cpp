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
    ll t,k,j;
    int prime[] {2,3,5,7,11,13,17,19};
    string s;
    t = readInt();
    while(t--)
    {
        cin>>s;
        k = readInt();
        rep(i,0,8)
        {
            if(s[prime[i]]-1 == '1')
            {
                for(j=i*2;j<=40; j+=i)
                {
                    s[j - 1] = '1';
                }
            }
        }
        vector<int> dp(41);
        dp[0] = 0;
        rep(i,1,41)
        {
            if(s[i-1] == '1')
            {
                dp[i] = dp[i-1] + 1;
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }
        rep(i,1,41)
        {
            if(dp[i] == k)
            {
                cout<<i-1<<endl;
                break;
            }
        }

    }
    return 0;
}
