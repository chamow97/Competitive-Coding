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
	ll n,t;
	t = readInt();
	vector<bool> a(101);
	a[0] = false;
	a[1] = false;
	a[2] = true;
	a[3] = true;
	a[4] = true;
	a[5] = true;
	rep(i,6,101)
	{
		if((a[i-2] & a[i-3] & a[i-5]) == 0)
		{
			a[i] = true;
		}
		else
		{
			a[i] = false;
		}
	}
	while(t--)
	{
		n = readInt();
		if(a[n] == true)
		{
			cout<<"First\n";
		}
		else
		{
			cout<<"Second\n";
		}
	}
    return 0;
}
