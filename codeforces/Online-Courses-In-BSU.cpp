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
const ll maxn = 2e5;

vec *adj = new vec[maxn];
vec visited(maxn, 0);
vec ans;
bool possible = true;

void dfs(ll s)
{
	visited[s] = 1;
	for(auto i : adj[s])
	{
		if(visited[i] == 0)
		{
			dfs(i);
		}
		else if(visited[i] == 1)
		{
			possible = false;
		}
	}
	visited[s] = 2;
	ans.pb(s);
}

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec ip(k,0);
	rep(i,0,k)
	{
		cin >> ip[i];
	}
	rep(i,1,n+1)
	{
		ll counter;
		cin >> counter;
		rep(j,0,counter)
		{
			ll val;
			cin >> val;
			adj[i].pb(val);
		}
	}
	ll totalSize = 0;
	vector< vec > answer;
	rep(i,0,k)
	{
		if(visited[ip[i]] == 0)
		{
			ans.resize(0);
			dfs(ip[i]);
			totalSize += (ans.size());
			answer.pb(ans);
		}
	}
	if(!possible)
	{
		cout << -1;
		return 0;
	}
	cout << totalSize << '\n';
	rep(i,0,answer.size())
	{
		rep(j,0,answer[i].size())
		{
			cout << answer[i][j] << ' ';
		}
	}

	return 0;
}
