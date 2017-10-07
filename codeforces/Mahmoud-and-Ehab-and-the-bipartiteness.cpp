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
vec colorCounter(2,0);
vec *adj = new vec[100010];
boolean visited(100010, false);
void dfs(ll node, ll prevNode, ll color)
{
    visited[node] = true;
    colorCounter[color]++;
    for(auto i : adj[node])
    {
        if(visited[i] == false)
        {
            dfs(i, node, !color);
        }
    }
}


int main()
{
	fastread;
    ll n;
    cin>>n;
    rep(i,0,n-1)
    {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(1,0,0);
    cout<<(colorCounter[0] * colorCounter[1])-n+1;
	return 0;
}
