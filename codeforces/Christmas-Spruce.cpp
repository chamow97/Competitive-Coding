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
	ll n;
	cin >> n;
	vec parent(n+1000, -1);
	vec *child = new vec[n+1000];
	rep(i,2,n+1)
	{
		ll val;
		cin >> val;
		parent[i] = val;
		child[val].pb(i);
	}
	boolean isLeaf(n+1000, false);
	rep(i,1,n+1)
	{
		if(!isLeaf[i])
		{

			ll leaf = 0;
			if(child[i].size() == 0)
			{
				isLeaf[i] = true;
			}
			rep(j,0,child[i].size())
			{
				if(child[child[i][j]].size() == 0)
				{
					isLeaf[child[i][j]] = true;
					++leaf;
				}
			}
			if(leaf < 3)
			{
				cout << "No";
				return 0;
			}		
		}
	}
	cout << "Yes";
	return 0;
}
