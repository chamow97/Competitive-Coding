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
	set<ll> s;
	vec ans(n+1, 0);
	rep(i,1,n+1)
	{
		s.insert(i);
	}
	while(m--)
	{
		ll l, r, x;
		cin >> l >> r >> x;
		auto pos = s.lower_bound(l);
		while(*pos <= r && pos != s.end())
		{
			if(*pos == x)
			{
				++pos;
			}
			else
			{
				ans[*pos] = x;
				s.erase(pos++);
			}
		}
	}
	rep(i,1,n+1)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
