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

const ll MAXN = 1 << 17;
vec degree(MAXN, 0);
vec Xor(MAXN, 0);
ll n;
vec adj[MAXN];
queue<int> qp;

int main()
{
	fastread;
	cin >> n;
	ll edge = 0;
	rep(i,0,n)
	{
		cin >> degree[i] >> Xor[i];
		if(degree[i] == 1)
		{
			qp.push(i);
		}
	}
	while(!qp.empty())
	{
		ll f = qp.front();
		qp.pop();
		if(degree[f] <= 0)
		{
			continue;
		}
		degree[f]--;
		degree[Xor[f]]--;
		adj[f].pb(Xor[f]);
		Xor[Xor[f]] ^= f;
		edge++;
		if(degree[Xor[f]] == 1)
		{
			qp.push(Xor[f]);
		}
	}
	cout << edge << '\n';
	rep(i,0,n)
	{
		for(auto j : adj[i])
		{
			cout << i << ' ' << j << '\n';
		}
	}
	return 0;
}