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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
#define maxn 300000
vector<pair< ll, ll > > open[maxn], close[maxn];
multiset<ll> best[maxn];

int main()
{
	fastread;
	ll ans = INF;
	ll n, x;
	cin>>n>>x;
	rep(i,0,n)
	{
		ll l, r, cost, d;
		cin>>l>>r>>cost;
		d = r-l+1;
		open[l].pb(mp(d, cost));
		close[r].pb(mp(d, cost));
		best[d].insert(cost);
	}
	rep(i,0,maxn)
	{
		best[i].insert(INF);
	}
	rep(i,0,maxn)
	{
		vector< pair<ll, ll> > :: iterator v;
		for(v = open[i].begin(); v != open[i].end(); v++)
		{
			ll c = (*v).second;
			ll d = (*v).first;
			best[d].erase(best[d].find(c));
		}
		for(v = close[i].begin(); v != close[i].end(); v++)
		{
			ll c = (*v).second;
			ll d = (*v).first;
			if(d > x)
			{
				continue;
			}
			ans = min(ans, c + *best[x-d].begin());
		}
	}
	if(ans >= INF)
	{
		ans = -1;
	}
	cout<<ans;
	return 0;
}