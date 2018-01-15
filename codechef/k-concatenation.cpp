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


ll kadaneAlgorithm(ll n, vector<ll> &inputArray)
{
    ll maxSoFar = -1e18;
    ll maxEndingHere = 0;
    rep(i,0,n)
    {
        maxEndingHere = maxEndingHere + inputArray[i];
        if(maxSoFar < maxEndingHere)
        {
            maxSoFar = maxEndingHere;
        }
        if(maxEndingHere < 0)
        {
            maxEndingHere = 0;
        }
    }
    return maxSoFar;
}

void solve()
{
	ll n, k;
	ll negativeSum = 0, positiveSum = 0;
	cin >> n >> k;
	vec arr(n, 0);
	vec prefix(n, 0);
	vec suffix(n, 0);
	//compute sum
	rep(i,0,n)
	{
		cin >> arr[i];
		if(i == 0)
		{
			prefix[i] = arr[i];
		}
		else
		{
			prefix[i] = prefix[i-1] + arr[i];
		}
		if(arr[i] < 0)
		{
			negativeSum += (arr[i] * (-1));
		}
		else
		{
			positiveSum += arr[i];
		}
	}
	per(j,n-1,0)
	{
		if(j == n-1)
		{
			suffix[j] = arr[j];
		}
		else
		{
			suffix[j] = suffix[j+1] + arr[j];
		}
	}
	//k = 1 case
	if(k == 1)
	{
		cout << kadaneAlgorithm(n, arr);
	}
	else if(k == 2 || negativeSum > positiveSum)
	{
		rep(i,0,n)
		{
			arr.pb(arr[i]);
		}
		cout << kadaneAlgorithm(2*n, arr);
	}
	else
	{
		ll curr = (positiveSum - negativeSum);
		curr *= (k - 2);
		ll maxSuffix = 0, maxPrefix = 0;
		per(j,n-1,0)	
		{
			maxSuffix = max(maxSuffix, suffix[j]);
		}	
		rep(i,0,n)
		{
			maxPrefix = max(maxPrefix, prefix[i]);
		}
		cout << maxSuffix + curr + maxPrefix;
	}
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}
