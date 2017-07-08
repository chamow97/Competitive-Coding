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

int main()
{
	fastread;
	ll n, q, c, x, y, s;
	cin>>n>>q>>c;
	ll ans[11][101][101];
	rep(i,0,11)
	{
		rep(j,0,101)
		{
			rep(k,0,101)
			{
				ans[i][j][k] = -1;
			}
		}
	}
	rep(i,0,n)
	{
		cin>>x>>y>>s;
		ans[0][x][y] = s;
	}
	rep(i,1,c+1)
	{
		rep(j,1,101)
		{
			rep(k,1,101)
			{
				if(ans[i-1][j][k] != -1)
				{
					ll val = ans[i-1][j][k] + 1;
					if(val > c)
					{
						val = 0;
					}
					ans[i][j][k] = val;
				}
				
			}
		}
	}
	vector< vector< pair<ll, pair<ll, ll> > > > v;
	rep(i,0,c+1)
	{
		vector< pair< ll, pair<ll, ll> > > v1;
					
		rep(j,1,101)
		{
			rep(k,1,101)
			{
				if(ans[i][j][k] != -1)
				{
					v1.pb(mp(ans[i][j][k],mp(j,k)));
				}
			}
		}
		v.pb(v1);
	}
	while(q--)
	{
		ll instant, x1, y1, x2, y2;
		cin>>instant>>x1>>y1>>x2>>y2;
		if(instant > c)
		{
			instant = (instant)%(c+1);
		}
		ll answer = 0;
		rep(i,0,v[instant].size())
		{
			ll val = v[instant][i].first;
			ll x3 = v[instant][i].second.first;
			ll y3 = v[instant][i].second.second;
			// cout<<x3<<" "<<y3<<" "<<val<<'\n';
			if(x3 >= x1 && y3 >= y1 && x3 <= x2 && y3 <= y2)
			{
				answer += val;
			}
		}
		// rep(i,0,c+1)
		// {
		// 	rep(j,0,v[i].size())
		// 	{
		// 		cout<<v[i][j].second.first<<" "<<v[i][j].second.second<<" "<<v[i][j].first<<'\n';
		// 	}
		// }
		cout<<answer<<'\n';
	}
	return 0;
}