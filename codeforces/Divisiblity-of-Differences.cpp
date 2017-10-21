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
	ll n, k, m;
	cin>>n>>k>>m;
	vec arr(n,0);
	vec brr(n,0);
	rep(i,0,n)
	{
		cin>>arr[i];
		brr[i] = arr[i];
		arr[i] %= m;
	}
	sort(arr.begin(), arr.end());
	ll ans = -1;
	rep(i,0,m)
	{
		ll upperPos = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
		ll lowerPos = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
		ll sizeNow = upperPos - lowerPos;
		if(sizeNow >= k)
		{
			cout<<"Yes\n";
			ll counter = 0;
			rep(j,0,n)
			{
				if(brr[j] % m == i)
				{
					cout<<brr[j]<<" ";
					++counter;
				}
				if(counter == k)
				{
					break;
				}
			}
			ans = 1;
			break;
		} 
	}
			if(ans != 1)
		{
			cout<<"No";
		}

	return 0;
}
