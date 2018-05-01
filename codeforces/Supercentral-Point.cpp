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

int main()
{
	fastread;
	ll n;
	ll ans = 0;
	cin >> n;
	vec xP[2100];
	vec yP[2100];
	vecpair p;
	rep(i,0,n)
	{
		ll x, y;
		cin >> x >> y;
		x += 1000;
		y += 1000;
		p.pb(mp(x, y));
		xP[x].pb(y);
		yP[y].pb(x);
	}
	rep(i,0,n)
	{
		ll x = p[i].f;
		ll y = p[i].s;
		ll ctr = 0;
		rep(i,0,xP[x].size())
		{
			if(xP[x][i] < y)
			{
				ctr++;
				break;
			}
		}
		rep(i,0,xP[x].size())
		{
			if(xP[x][i] > y)
			{
				ctr++;
				break;
			}
		}
		rep(i,0,yP[y].size())
		{
			if(yP[y][i] < x)
			{
				ctr++;
				break;
			}
		}
		rep(i,0,yP[y].size())
		{
			if(yP[y][i] > x)
			{
				ctr++;
				break;
			}
		}
		if(ctr >= 4)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}