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

bool myComp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
	if(p1.first == p2.first)
	{
		return p1.second < p2.second;
	}
	return p1.first < p2.first;
}

vec *adj = new vec[100+100];
boolean visited(100+100, false);
void dfs(ll s)
{
	visited[s] = true;
	for(auto u : adj[s])
	{
		if(!visited[u])
		{
			dfs(u);
		}
	}	
}

int main()	
{
	fastread;
	ll n, m;
	cin >> n >> m;
	vecpair p;
	rep(i,0,n)
	{
		ll a,b;
		cin >> a >> b;
		rep(j,a+1,b+1)
		{
			adj[a].pb(j);
		}
	}
	dfs(0);
	if(visited[m] == false)
	{
		cout << "NO";
	}
	else
	{
		cout << "YES";
	}

	

	return 0;
}
