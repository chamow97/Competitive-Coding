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
ll n;
const ll maxn = 1e6;
vec *adj = new vec[maxn];
boolean visited(maxn, false);
vec arr(maxn + 1, 0);

void dfs(ll i, ll &ctr)
{
	visited[i] = true;
	++ctr;
	for(auto it : adj[i])
	{
		if(visited[it] == false)
		{
			dfs(it, ctr);
		}
	}
}

int main()
{
	fastread;
	cin >> n;
	rep(i, 1, n + 1)
	{
		cin >> arr[i];
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	rep(i, 1, n + 1)
	{
		visited[i] = true;
		ll ptr = i;
		while(arr[ptr] <= n && visited[arr[ptr]] == false)
		{
			adj[ptr].pb(arr[ptr]);
			adj[arr[ptr]].pb(ptr);
			visited[arr[ptr]] = true;
			ptr = arr[ptr];
		}
	}
	ll ctr = 0;
	vec ans;
	fill(visited.begin(), visited.end(), false);
	rep(i, 1, n + 1)
	{
		if(visited[i] == false)
		{
			ctr = 0;
			dfs(i, ctr);
			ans.pb(ctr);
		}
	}
	n = ans.size();
	sort(ans.begin(), ans.end());
	ll soln = 0;
	rep(i, 0, n)
	{
		ll t;
		t = ans[i];
		soln += (pow(t, 2));
	}
	ll temp = 0;
	if(n > 1)
	{
		temp = pow((ans[n-2] + ans[n-1]), 2);
	}
	per(i, n - 3, 0)
	{
		temp += (pow(ans[i], 2));
	}
	soln = max(soln, temp);
	cout << soln;
	return 0;
}
