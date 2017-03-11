//template by chamow
//template
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
    ll t,m,a[100000];
    t = readInt();
    while(t--)
    {
    ll isOdd=0,isEven=0;

    m = readInt();
    rep(i,0,m)
    {
        a[i] = readInt();

    }
    ll ans = a[0];
    rep(i,1,m)
    {
        ans = ans&a[i];
    }
    cout<<ans<<'\n';
    }

    return 0;
}
