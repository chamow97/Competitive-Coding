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
typedef vector<ll> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

const ll maxn = 2e5 + 100;
vec cost(maxn, 0);
ll n;
vec arr(maxn);
boolean visited(maxn, false);
vec color(maxn, 0);
ll start = -1;

void dfs(ll s)
{
	color[s] = 1;
	visited[s] = true;
	if(!visited[arr[s]])
	{
		dfs(arr[s]);
	}
	else if(color[arr[s]] == 1)
	{
		start = s;
	}
	color[s] = 2;
}


int main()
{
	//thanks Akshay aka @panipuri8!! THALA!! /\

	fastread
	cin >> n;
	rep(i,1,n+1)
	{
		cin >> cost[i];
	}
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	ll sum = 0;
	boolean cycleVisited(maxn, false);
	rep(i,1,n+1)
	{
		if(!visited[i])
		{
			start = -1;
			dfs(i);
			if(start != -1)
			{
				ll minimum = INF;
				while(!cycleVisited[start])
				{
					minimum = min(minimum, cost[start]);
					cycleVisited[start] = true;
					start = arr[start];
				}
				if(minimum != INF)
				sum += (minimum);
			}

		}
	}
	cout << sum;
	return 0;
}