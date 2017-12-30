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

vector<string> v;
vec *adj = new vec[1100];
ll n;
vec visited(26, 0);
bool notPossible;
string answer = "";
vec topSort;
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
			notPossible = true;
		}
	} 
	visited[s] = 2;
	topSort.pb(s);

}
int main()
{
	fastread;
	cin >> n;
	rep(i,0,n)
	{
		string str;
		cin >> str;
		v.pb(str);
	}

	rep(i,0,n-1)
	{
		bool possible = false;
		ll minimum = min(v[i].length(), v[i+1].length());
		rep(j,0,minimum)
		{
			if(v[i][j] != v[i+1][j])
			{
				adj[v[i + 1][j] - 'a'].pb(v[i][j] - 'a');
				possible = true;
				break;
			}
		}
		if(!possible)
		{
			if(v[i].length() > minimum)
			{
				cout << "Impossible\n";
				return 0;
			}
		}
	}
	rep(i,0,26)
	{
		if(visited[i] == 0)
		{
			dfs(i);
		}
	}
	if(notPossible)
	{
		cout << "Impossible";
		return 0;
	}
	rep(j,0,26)
	{
		cout << char(topSort[j] + 'a');
	}
	return 0;
}
