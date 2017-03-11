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
	ll t,a,b,c,k;
	t = readInt();
	while(t--)
	{
		a = readInt();
		b = readInt();
		c = readInt();
		k = readInt();
		ll low = 0, high = sqrt(k)+1, mid, pos = -1;
		while(low <= high)
		{
			mid = (low + high)/2;
			ll value = ((a*(mid * mid)) + (b*mid) + c);
			if(value < k)
			{
				low = mid+1;
			}
			else if(value == k)
			{
				pos = mid;
				break;
			}
			else
			{
				pos = mid;
				high = mid-1;
			}
			//cout<<mid<<"\n";

		}
		cout<<pos<<"\n";
	}
    return 0;
}
