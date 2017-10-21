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

ll maxn = 600;
ll n, m, k;
char maze[600][600];
ll dots = 0;
vec *adj = new vec[600*600];
boolean visited(600*600, false);
ll counter = 0;
vec s1;

void dfs(ll s)
{

	if(counter >= (dots - k))
	{
		s1.pb(s);
	}
	// cout<<s<<" "<<counter<<'\n';
	visited[s] = true;
	counter++;
	for(auto i : adj[s])
	{
		if(visited[i] == false)
		{
			dfs(i);
		}
	}
}
void input()
{
	cin>>n>>m>>k;
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			cin>>maze[i][j];
			if(maze[i][j] == '.')
			{
				dots++;
			}
		}
	}
	if(k == 0)
	{
		rep(i,1,n+1)
		{
			rep(j,1,m+1)
			{
				cout<<maze[i][j];
			}
			cout<<'\n';
		}
		return;
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(maze[i][j] == '.')
			{
				if((i+1) <= n)
				{
					if(maze[i+1][j] == '.')
					{
						ll current = (i-1)*m + j;
						ll next = current + m;
						adj[current].pb(next);
						adj[next].pb(current);
					}
				}
				if((j+1) <= m)
				{
					if(maze[i][j+1] == '.')
					{
						ll current = (i-1)*m + j;
						ll next = current + 1;
						adj[current].pb(next);
						adj[next].pb(current);
					}
				}
			}
		}
	}
	bool done = false;
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			if(maze[i][j] == '.')
			{
				ll current = (i-1)*m + j;
				dfs(current);
				done = true;
				break;
			}
		}
		if(done)
		{
			break;
		}
	}
	sort(s1.begin(), s1.end());
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			ll current = ((i-1)*(m)) + j;
			// cout<<current<<" ";
			if(*lower_bound(s1.begin(), s1.end(), current) == current)
			{
				ll pos = lower_bound(s1.begin(), s1.end(), current) - s1.begin();
				if(pos >= 0 && pos < (s1.size()))
					maze[i][j] = 'X';
			}
		}
	}
	rep(i,1,n+1)
	{
		rep(j,1,m+1)
		{
			cout<<maze[i][j];
		}
		cout<<'\n';
	}
	// for(auto i : s1)
	// {
	// 	cout<<i<<" ";
	// }
}

int main()
{
	fastread;
	input();
	return 0;
}
