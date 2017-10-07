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

ll n, m;
ll maxn = 200;
vector< vec > connections;
vec *adj = new vec[maxn];
boolean visited(maxn,false);

void dfs(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(visited[i] == false)
		{
			dfs(i);
		}
	}
}

void solve()
{
	cin>>n>>m;
	ll kzero = 0;
	rep(i,0,n)
	{
		vec employee;
		ll k;
		cin>>k;
		if(k == 0)
		{
			++kzero;
			employee.pb(-1);
		}
		rep(j,0,k)
		{
			ll temp;
			cin>>temp;
			employee.pb(temp);
		}
		sort(employee.begin(), employee.end());
		connections.pb(employee);
	}
	rep(i,0,connections.size())
	{
		rep(k,i+1,connections.size())
		{
			rep(j,0,connections[i].size())
			{
				if(*lower_bound(connections[k].begin(), connections[k].end(), connections[i][j]) == connections[i][j] && connections[i][j] != -1)
				{
					ll pos = lower_bound(connections[k].begin(), connections[k].end(), connections[i][j]) - connections[k].begin();
					if(pos < connections[k].size() && pos >= 0)
					{
						adj[i].pb(k);
						adj[k].pb(i);
						break;
					}
					
				}
			}
		}
	}
	ll counter = 0;
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			// cout<<i<<" ";
			++counter;
			dfs(i);
		}
	}
	if(kzero == n)
	{
		cout<<counter;
		return;
	}
	cout<<counter-1;
}

int main()
{
	fastread;
	solve();
	return 0;
}
