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
	ll n,a[101],dp[101],counter = 0;
	n = readInt();
	a[0] = 0;
	rep(i,0,n)
	{
		a[i] = readInt();
		if(a[i]!=0)
		{
			++counter;
		}
	}
	cout<<counter<<endl;
	rep(i,0,n)
	{
		if(a[i] != 0)
		{
			cout<<i<<" "<<i;
		}
		else
		{
			cout<<;
		}
	}
	cout<<n<<endl;
    return 0;
}
