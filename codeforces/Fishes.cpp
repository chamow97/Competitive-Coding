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

const ll maxn = 1e5+100;
ll n, m, r, k;
queue<ll> q;
ll value = 0;
ll getVal(ll x, ll y)
{
	ll a = min(n+1, x+r) - max(x, r);
	ll b = min(m+1, y+r) - max(y, r);
	a *= b;
	return a;
}

set< pair< ll,  pair<ll, ll> > > s1; 
set< ll > visited[maxn];

ll bfs()
{
	s1.insert(mp(getVal((n+1)/2, (m+1)/2), mp((n+1)/2, (m+1)/2)));
	visited[(n+1)/2].insert((m+1)/2);
	rep(i,0,k)
	{
		auto it = s1.end();
		--it;
		s1.erase(it);
		ll x = (*it).s.f;
		ll y = (*it).s.s;
		// cout << x << ' ' << y << '\n';
		value += getVal(x, y);
		if(x + 1 <= n)
		{
			if(visited[x+1].find(y) == visited[x+1].end())
			{
				s1.insert(mp(getVal(x+1, y), mp(x+1, y)));
				visited[x+1].insert(y);
			}
		}
		if(x - 1 >= 1)
		{
			if(visited[x-1].find(y) == visited[x-1].end())
			{
				s1.insert(mp(getVal(x-1, y), mp(x-1, y)));
				visited[x-1].insert(y);
			}
		}
		if(y + 1 <= m)
		{
			if(visited[x].find(y+1) == visited[x].end())
			{
				s1.insert(mp(getVal(x, y+1),mp(x, y+1)));
				visited[x].insert(y+1);
			}
		}
		if(y - 1 >= 1)
		{
			if(visited[x].find(y-1) == visited[x].end())
			{
				s1.insert(mp(getVal(x, y-1), mp(x, y-1)));
				visited[x].insert(y-1);
			}
		}
	}	
	return value;
}

int main()
{
	fastread;
	//saw editorial
	cin >> n >> m >> r >> k;
	ll ans = bfs();	 
	double total = (1.00 * ans)/((n - r + 1) * (m - r + 1) * 1.00);
	cout << setprecision(10) << total;
	return 0;
}