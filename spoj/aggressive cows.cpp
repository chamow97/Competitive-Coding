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
	ll c,t,n,low,mid,high,present;
	t = readInt();
	while(t--)
	{
		n = readInt();
		c = readInt();
		vector<int> a(n);
		rep(i,0,n)
		{
			a[i] = readInt();
		}
		sort(a.begin(), a.end());
		ll totcows = 0;
		low = 0;
		high = a[n-1];
		while(low < high)
		{
			totcows = 0;
			mid = (low + high + 1)/2;
			++totcows;
			present = a[0];
			rep(i,1,n)
			{
				if(a[i] - present >= mid)
				{
					++totcows;
					present = a[i];
				}
			}
			if(totcows < c)
			{
				high = mid - 1;
			}
			else
			{
				low = mid;
			}			

		}
		cout<<low<<endl;
	}

    return 0;
}
