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
    ll temp,n,f,a[100001],dp[100001];
    bool pos[100001];
    n = readInt();
    f = readInt();
    rep(i,1,n+1)
    {
        a[i] = readInt();
    }

    rep(i,0,n)
    {
        temp = readInt();
        pos[temp] = true;
    }
    ll l=0;
   rep(i,1,n+1)
   {
       if(pos[i] == true)
       {
           dp[i] = a[l++];
       }
   }
    return 0;
}
