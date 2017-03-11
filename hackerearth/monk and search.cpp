//template by chamow
//template
#include<bits/stdc++.h>
using namespace std;
#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
typedef long long ll;
ll upperBound(ll a[], ll n , ll key)
{
	ll low = 0, high = n-1, mid, pos = -1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(!(a[mid] <= key))
		{
			high = mid-1;
			pos = mid;
		}

		else
		{

			low = mid+1;
		}

	}
	return pos;
}

ll lowerBound(ll a[], ll n, ll key)
{
	ll low = 0, high = n-1, mid, pos = -1;
	while(low <= high)
	{
		mid = (low + high)/2;
		if(a[mid] < key)
		{
			low = mid+1;
		}

		else
		{
			pos = mid;
			high = mid-1;
		}

	}
	return pos;
}

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
	ll n,q,a[100000],type,key;
	n = readInt();
	rep(i,0,n)
	{
		a[i] = readInt();
	}
	sort(a, a+n);
	q = readInt();
	while(q--)
	{
		type = readInt();
		key = readInt();
		if(type == 0)
		{

			ll pos = lowerBound(a,n,key);
			if(pos == -1)
			{
				pos = n;
			}
			cout<<n-pos<<endl;
		}
		else
		{
			ll pos = upperBound(a, n, key);
			if(pos == -1)
            {
                pos = n;
            }
			cout<<n-pos<<endl;
		}
	}

    return 0;
}
