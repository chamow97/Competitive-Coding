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

void solve()
{
	ll n;
	cin >> n;
	vector< vec > adj;
	rep(i,0,n)
	{
		vec arr(n,0);
		rep(j,0,n)
		{
			cin >> arr[j];
		}
		sort(arr.begin(), arr.end());
		adj.pb(arr);
	}
	ll sum = 0;
	sum += adj[n-1][n-1];
	ll val = adj[n-1][n-1];
	per(j,n-2,0)
	{
		bool possible = false;
		per(i,n-1,0)
		{
			if(adj[j][i] < val)
			{
				sum += adj[j][i];
				val = adj[j][i];
				possible = true;
				break;
			}
		}
		if(!possible)
		{
			cout << -1;
			return;
		}

	}
	cout << sum;

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
