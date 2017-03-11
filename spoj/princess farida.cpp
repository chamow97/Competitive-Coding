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
	ll ans = 0,t,n,a[10001],b[10001];
	t = readInt();
	rep(l,0,t)
	{
		ans = 0;
		n = readInt();
		rep(i, 0, n)
		{
			a[i] = readInt();
		}
		b[0] = a[0];
		b[1] = max(b[0], a[1]);
		rep(i,2,n)
		{
			b[i] = max(a[i] + b[i-2], b[i-1]);
		}
		cout<<"Case "<<l+1<<": "<<b[n-1]<<endl;
	}

    return 0;
}
