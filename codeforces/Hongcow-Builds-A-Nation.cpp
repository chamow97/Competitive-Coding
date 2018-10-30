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

const ll MAXN = 2e3;
vec adj[MAXN];
ll n, m, k;
map<ll, ll> cities;
boolean visited(MAXN, false);
bool isAccepted = true;
ll counter = 0;

void dfs(ll s)
{
	visited[s] = true;
	if(cities[s] > 0)
	{
		isAccepted = false;
	} 
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			++counter;
			dfs(i);
		}
	}
}

int main()
{
	fastread;
	cin >> n >> m >> k;
	vec possibleComponents;
	vec notPossibleComponents;
	rep(i,0,k)
	{
		ll val;
		cin >> val;
		cities[val]++;
	}
	rep(i,0,m)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll sum = 0;
	rep(i,1,n+1)
	{
		if(!visited[i])
		{
			isAccepted = true;
			counter = 1;
			dfs(i);
			if(!isAccepted)
			{
				notPossibleComponents.pb(counter);
			}
			else
			{
				sum += counter;
			}
		}
	}
	ll maximum = 0;
	if(notPossibleComponents.size() > 0)
	{
		sort(notPossibleComponents.begin(), notPossibleComponents.end());
		maximum = notPossibleComponents[notPossibleComponents.size() - 1];
		sum += (maximum);
	}
	ll ans = (sum * (sum - 1)) / 2;
	rep(i,0,notPossibleComponents.size() - 1)
	{
		ans += ((notPossibleComponents[i] * (notPossibleComponents[i] - 1)) / 2);
	}
	ans -= m;
	ans = max(ans, 0ll);
	cout << ans;
}