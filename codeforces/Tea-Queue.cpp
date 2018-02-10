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

bool myFunc(pair<ll, pair<ll, ll> > p1, pair<ll, pair<ll, ll> > p2 )
{
	if(p1.f == p2.f)
	{
		return p1.s.s < p2.s.s;
	}
	return p1.f < p2.f;
}

void solve()
{
	ll n;
	vector< pair<ll ,pair<ll, ll> > > p;
	cin >> n;
	rep(i,0,n)
	{
		ll u, v;
		cin >> u >> v;
		p.pb(mp(u, mp(v, i)));
	}
	sort(p.begin(), p.end(), myFunc);
	ll start = p[0].f;
	vec ans;
	ans.pb(start);
	++start;
	rep(i,1,n)
	{
		if(p[i].s.f < start)
		{
			ans.pb(0);
		}
		else if(p[i].f <= start && p[i].s.f >= start)
		{
			ans.pb(start);
			++start;
		}
		else if(p[i].f > start)
		{
			start = p[i].f;
			ans.pb(start);
			++start;
		}
	}
	rep(i,0,ans.size())
	{
		cout << ans[i] << ' ';
	}
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--){
		solve();
		cout << '\n';
	}
	return 0;
}