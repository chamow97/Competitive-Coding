//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

const ll maxn = 2e5 + 10;
vec adj[maxn];
boolean visited(maxn, false);
vec arr(maxn, 0);
vec order(maxn, 0);

bool comp(int &a, int &b)
{
	return order[a] < order[b];
}

int main()
{
	fastread
	ll n;
	cin >> n;
	rep(i,1,n)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	rep(i,1,n+1)
	{
		cin >> arr[i];
		order[arr[i]] = i;
	}
	rep(i,1,n+1)
	{
		sort(adj[i].begin(), adj[i].end(), comp);
	}
	queue<int> q;
	q.push(1);
	vec ans;
	while(!q.empty())
	{
		ll top = q.front();
		// cout << top << ' ';
		visited[top] = true;
		ans.pb(top);
		q.pop();
		for(auto i : adj[top])
		{
			if(!visited[i])
			{
				q.push(i);
			}
		}
	}
	rep(i,0,n)
	{
		if(ans[i] != arr[i+1])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}