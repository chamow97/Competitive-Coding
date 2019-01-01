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

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	vec adj[m + 1];
	vec ans(n + 10, 0);
	rep(i,0,n)
	{
		ll s, r;
		cin >> s >> r;
		adj[s].pb(r);
	}
	rep(i,1,m+1)
	{
		sort(adj[i].begin(), adj[i].end(), greater<ll>());
	}
	rep(i,1,m+1)
	{
		ll currSum = 0;
		rep(j,0,adj[i].size())	
		{
			currSum += adj[i][j];
			if(currSum < 0)
			{
				break;
			}
			ans[j + 1] += currSum;
		}
	}
	cout << *max_element(ans.begin(), ans.end());
	return 0;
}