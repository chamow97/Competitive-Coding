//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
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
    ll n,m,t;
    t = readInt();
    while(t--)
    {
        ll ans;
         n = readInt();
         m = readInt();
         if(n>m)
         {

             ans = 0;
         }
         else if(m==n)
         {
             ans = 1;
         }
         else
         {
             ans = ((m+n+1)/2 - n);
             n += ans;
             m -= ans;
             if(m == n)
             {
                 ans += 1;
             }
         }
         cout<<ans<<endl;
    }

    return 0;
}
