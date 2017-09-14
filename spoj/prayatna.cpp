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

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
/*-------------------------------------------------------- */


void dfs(vec *adj, ll n, ll i, boolean &visited)
{
	visited[i] = true;
	vec :: iterator it;
	for(it = adj[i].begin(); it != adj[i].end(); it++)
	{
		if(visited[*it] == false)
		{
			dfs(adj, n, *it, visited);
		}
	}
}

int main()
{
	ll t, n, m, u, v, counter;
	t = read_int();
	while(t--)
	{
	    counter = 0;
		n = read_int();
		m = read_int();
		vec *adj = new vec[n];
		rep(i,0,m)
		{
			u = read_int();
			v = read_int();
			adj[u].pb(v);
			adj[v].pb(u);
		}
		boolean visited(n, false);
		rep(i,0,n)
		{
			if(visited[i] == false)
			{
				++counter;
				dfs(adj, n, i, visited);
			}

		}
		printf("%lld\n", counter);
	}
	return 0;
}