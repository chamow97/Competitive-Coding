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

const ll maxn = 1e5+100;
vec prime(maxn, 0);
vec maxCount(maxn, 0);

void seive()
{
	for(ll i = 2; i * i < maxn; i++)
	{
		if(!prime[i])
		{
			for(ll j = i * i; j < maxn; j += i)
			{
				prime[j] = i;
			}
		}
	}
	for(ll i = 2; i < maxn; i++)
	{
		if(!prime[i])
		{
			prime[i] = i;
		}
	}
}

ll n;
ll largestGCDSubsequence(vec arr)
{
	ll ans = 0;
	seive();
	rep(i,0,arr.size())
	{
		ll now = arr[i];
		while(now > 1)
		{
			ll spf = prime[now];
			++maxCount[spf];
			ans = max(ans, maxCount[spf]);
			while(now % spf == 0)
			{
				now /= spf;
			}
		}
	}
	return ans;
}


int main()
{
	fastread;
	cin >> n;
	vec arr(n, 0);
	ll ones = 0;
	rep(i,0,n)
	{
		cin >> arr[i];
		if(arr[i] == 1)
		{
			++ones;
		}
	}
	if(ones > 0 && n == 1 || ones == n)
	{
		cout << 1;
		return 0;
	}
	ll ans = largestGCDSubsequence(arr);
	cout << ans;
	return 0;
}
