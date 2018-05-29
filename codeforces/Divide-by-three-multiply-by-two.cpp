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
const ll MAXN = 200;
ll ans = 0;
vec arr(MAXN+1);
vec adj[MAXN+1];
boolean visited(MAXN, false);

void dfs(ll s)
{
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
	++ans;
}

void printAns(ll s)
{
	cout << arr[s] << ' ';
	visited[s] = true;
	for(auto i : adj[s])
	{
		if(!visited[i])
		{
			printAns(i);
		}
	}
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(arr[i] * 2 == arr[j])
			{
				adj[i].pb(j);
				// cout << i << ' ' << j << '\n';
			}
			if(arr[i] % 3 == 0 && arr[i] / 3 == arr[j])
			{
				adj[i].pb(j);
				// cout << i << ' ' << j << '\n';
			}
		}
	}
	rep(i,1,n+1)
	{
		if(adj[i].size() == 1)
		{
			ans = 0;
			fill(visited.begin(), visited.end(), false);
			dfs(i);
			// cout << ans << '\n';
			if(ans == n)
			{
				fill(visited.begin(), visited.end(), false);
				printAns(i);
				return 0;
			}
		}
	}
	return 0;
}