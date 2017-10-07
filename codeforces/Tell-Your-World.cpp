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

void dfs(ll s, vec *adj, boolean &visited)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(visited[i] == false)
		{
			dfs(i, adj, visited);
		}
	}

}
int main()
{
	fastread;
	map<double,ll> m;
	ll maximum = 0;
	double val = 0.0;
	ll n;
	cin>>n;

	pair<ll, ll> p[n];
	rep(i,1,n+1)
	{
		ll y;
		cin>>y;
		p[i].first = i;
		p[i].second = y;
	}
	if(n == 3)
	{
		set<double> s;
		rep(i,1,4)
		{
			rep(j,i+1,4)
			{
				double slope = 0.0;
				slope = (p[j].second - p[i].second)*1.00;
				slope /= ((p[j].first - p[i].first)*1.00);
				s.insert(slope);
			}
			
		}

		if(s.size() == 1)
		{
			cout<<"No";
			return 0;
		}
		cout<<"Yes";
		return 0;
	}
	
	rep(i,1,n+1)
	{
		rep(j,i+1,n+1)
		{
			double slope = 0.0;
			slope = (p[j].second - p[i].second)*1.00;
			slope /= ((p[j].first - p[i].first)*1.00);
			m[slope]++;
			if(maximum < m[slope])
			{
				maximum = m[slope];
				val = slope;
			}
		}
	}
	// if(maximum < n-1)
	// {
	// 	cout<<"No";
	// }
	// else
	// {
		vec *adj = new vec[n+1];
		rep(i,1,n+1)
		{
			rep(j,i+1,n+1)
			{
				double slope = 0.0;
				slope = (p[j].second - p[i].second)*1.00;
				slope /= ((p[j].first - p[i].first)*1.00);
				if(val == slope)
				{
					adj[i].pb(j);
					adj[j].pb(i);					
				}
			}
		}
		boolean visited(n+1, false);
		ll dfsCount = 0;
		rep(i,1,n+1)
		{
			if(visited[i] == false)
			{
				dfs(i, adj, visited);
				++dfsCount;
			}
		}
		if(dfsCount == 2)
		{
			cout<<"Yes";
		}
		else
		{
			cout<<"No";
		}
	// }
	return 0;
}
