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

ll dfs(vec *adj, boolean &visited, ll s, vec &v1)
{
	v1.pb(s);
	visited[s] = true;
	vec::iterator it;
	for(it = adj[s].begin(); it != adj[s].end(); it++)
	{
		if(visited[*it] == false)
		{
			dfs(adj, visited, *it, v1);
		}
	}
}

int main()
{
	fastread;
	ll n, m, u, v;
	cin>>n>>m;
	vec *adj = new vec[n];
	rep(i,0,m)
	{
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	boolean visited(n, false);
	vector< vec > v_one, v_two, v_three;
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			vec v1;
			dfs(adj, visited, i, v1);
			if(v1.size() == 1)
			{
				v_one.pb(v1);
			}
			else if(v1.size() == 2)
			{
				v_two.pb(v1);
			}
			else if(v1.size() == 3)
			{
				v_three.pb(v1);
			}
			else
			{
				cout<<-1;
				return 0;
			}
		}
	}
	ll three = 0, two = 0, one = 0;
	if(v_one.size() < v_two.size())
	{
		cout<<-1;
		return 0;
	}
	else
	{
		if((v_one.size() - v_two.size())%3 != 0)
		{
			cout<<-1;
			return 0;
		}
		else
		{
			rep(i,0,v_three.size())
			{
				rep(j,0,v_three[i].size())
				{
					cout<<v_three[i][j]+1<<" ";
				}
				cout<<'\n';
			}
			ll k = 0;
			rep(i,0,v_two.size())
			{
				rep(j,0,v_two[i].size())
				{
					cout<<v_two[i][j]+1<<" ";
				}
				cout<<v_one[k][0]+1<<" ";
				cout<<'\n';
				k++;
			}
			rep(i,k,v_one.size())
			{
				cout<<v_one[i][0]+1<<" ";
				cout<<'\n';
			}
		}
	}

	return 0;
}