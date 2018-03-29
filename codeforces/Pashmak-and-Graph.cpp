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
	ll n, m;
	cin >> n >> m;
	vector< pair<ll, pair<ll, ll> > > p;
	vec dp(n + 10, 0);
	rep(i,0,m)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		p.pb(mp(w, mp(u, v)));
	}
	sort(p.begin(), p.end());
	rep(i,0,m)
	{
		vecpair thisVal;
		ll ptr = i;
		while(p[ptr].f == p[i].f)
		{
			thisVal.pb(mp(dp[p[ptr].s.f], p[ptr].s.s));
			ptr++;
		}
		rep(i,0,thisVal.size())
		{
			dp[thisVal[i].s] = max(dp[thisVal[i].s], 1 + thisVal[i].f);
		}
		i = ptr;
		i--;
	}
	ll maximum = 0;
	rep(i,1,n+1)
	{
		maximum = max(maximum, dp[i]);
	}
	cout << maximum;
	return 0;
}