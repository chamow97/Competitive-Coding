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

bool myFunc(const pair< pair<ll, ll>, ll> &p1, const pair< pair<ll, ll>, ll> &p2)
{
	if(p1.f.f == p2.f.f)
	{
		return p1.f.s > p2.f.s;
	}
	return p1.f.f < p2.f.f;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	vector<pair< pair<ll, ll>, ll> > p(n);
	rep(i,0,n)
	{
		cin >> p[i].f.f >> p[i].f.s;
		p[i].s = i + 1;
	}
	sort(p.begin(), p.end(), myFunc);
	rep(i,1,n)
	{
		if(p[i].f.f >= p[i-1].f.f && p[i].f.s <= p[i-1].f.s)
		{
			cout << p[i].s << ' ' << p[i-1].s;
			return 0; 
		}
	}
	cout << -1 << ' ' << -1;
	return 0;
}	