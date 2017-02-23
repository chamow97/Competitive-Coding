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
    ll n,a[100001],q,p;
    n = readInt();
    rep(i,0,n)
    {
        a[i] = readInt();
    }
    q = readInt();
    while(q--)
    {
        ll sum = 0,ans = 0;
        p = readInt();
        rep(i,0,n)
        {
            if(a[i] <= p)
            {
                ++sum;
                ans += a[i];
            }
            else
            {
                break;
            }
        }
        cout<<sum<<" "<<ans<<endl;
    }
    return 0;
}
