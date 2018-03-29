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
const ll maxn = 1e5 + 10;
ll n, m;
vec arr(maxn, 0);
vec brr(maxn, 0);

ll func(ll val)
{
	ll currVal = 0;
	rep(i,1,n+1)
	{
		if(arr[i] < val)
		{
			currVal += (val - arr[i]);
		}
	}
	rep(i,1,m+1)
	{
		if(brr[i] > val)
		{
			currVal += (brr[i] - val);
		}
	}
	return currVal;
}

ll ternary_search(ll l, ll r)
{
	while(r-l>=3)
	{
		ll mid1 = l + (r-l)/3;
		ll mid2 = r - (r-l)/3;
		if(func(mid1) < func(mid2))
		{
			r = mid2;
		}
		else
		{			 
			l = mid1;
		}	
	}
	if(l==r)
	{	
		return func(l);
	}	
	else if ((l+1)==r)
	{
		return min(func(l),func(r));
	}
	else
	{
		return min(func(l),min(func(l+1),func(l+2)));
	}
}

int main()
{
	fastread;
	//my first ternary :P
	cin >> n >> m;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	//think the problem as [1..L] [M..N]
	//we see that as we out some values, it decreases and then increases 
	//we have to find that low point, so we use ternary search
	//the logic here is we have to increase A[i] and decrease B[i] to a value
	//such that cost is less
	rep(i,1,m+1)
	{
		cin >> brr[i];
	}
	cout << ternary_search(0, 1e9);
	return 0;
}