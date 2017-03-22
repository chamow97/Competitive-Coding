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

	ll n, m, counter = 0;
	n = readInt();
	m = readInt();
	vector<ll> a(n,0);
	vector<ll> b;
	rep(i,0,n)
	{
		a[i] = readInt();
	}
	sort(a.begin(), a.end());
	ll prev = 1;
	rep(i,0,n)
	{
		while(prev < a[i] && m>0)
		{
			if((m-prev) < 0)
			{
				break;
			}
			m -= prev;
			b.pb(prev);
			++counter;
			prev += 1;
		}
		prev = a[i] + 1;
	}
	while(m > 0)
	{	
		if((m-prev) < 0)
		{
			break;
		}
		m -= prev;
		b.pb(prev);
		++counter;
		prev += 1;
	}
	cout<<counter<<endl;
	rep(i,0,b.size())
	{
		cout<<b[i]<<" ";
	}

    return 0;
}
