//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator
#define f first
#define s second

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


/*-------------------------------------------------------- */

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec arr(n + 1);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	vec zeroes(n+1, 0);
	rep(i,1,n + 1)
	{
		if(arr[i] == 0)
		{
			zeroes[i] = 1;
		}
		zeroes[i] += zeroes[i-1];
	}
	ll lPtr = 1, rPtr = 1;
	ll lPos = -1, rPos = -1;
	ll maxSize = 0;
	while(lPtr <= rPtr && rPtr <= n)
	{
		if(zeroes[rPtr] - zeroes[lPtr - 1] <= k)
		{
			if(maxSize < (rPtr - lPtr + 1))
			{
				maxSize = rPtr - lPtr + 1;
				lPos = lPtr;
				rPos = rPtr;
			}
			rPtr++;
		}
		else
		{
			lPtr++;
		}
	}
	rep(i,1,n+1)
	{
		if(i >= lPos && i <= rPos)
		{
			arr[i] = 1;
		}
	}
	maxSize = 0; 
	ll curr = 0;
	rep(i,1,n+1)
	{
		if(arr[i] == 1)
		{
			++curr;
		}
		else
		{
			maxSize = max(maxSize, curr);
			curr = 0;
		}
	}
	maxSize = max(maxSize, curr);
	cout << maxSize << '\n';
	rep(i,1,n+1)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}