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

void dfs(ll s, vec *adj, boolean &visited, ll &counter)
{
    visited[s] = true;
    vec :: iterator it;
    for(it = adj[s].begin(); it != adj[s].end(); it++)
    {
        if(visited[*it] == false)
        {
            dfs(*it, adj, visited, ++counter);
        }
    }
}

int main()
{
    ll n, m, u, v, maximum = 0;
    n = read_int();
    m = read_int();
    vec *adj = new vec[n];
    rep(i,0,m)
    {
        u = read_int();
        v = read_int();
        --u;--v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    boolean visited(n, false);
    rep(i, 0, n)
    {
        if(visited[i] == false){
        ll val = 0;
        dfs(i, adj, visited, val);maximum = max(maximum, val);
        }

    }
    cout<<maximum+1;
	return 0;
}
