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
const ll maxn = 2e6 + 100;
boolean visited(maxn, false);
boolean used(maxn, false);
vec factors[maxn];

void seive()
{
	for(ll i = 2; i < maxn; i++)
	{
		if(!visited[i])
		{
			for(ll j = i; j < maxn; j += i)
			{
				factors[j].pb(i);
				visited[j] = true;
			}
		}
	}
}

bool isOkay(ll n)
{
	for(auto it : factors[n])
	{
		if(used[it])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	fastread;
	//saw editorial
	seive();
	ll n;
	cin >> n;
	bool isFirst = true;
	ll curr, out = 2;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		curr = val;
		if(isFirst)
		{
			while(!isOkay(curr))
			{
				curr++;
			}
			if(curr != val)
			{
				isFirst = false;
			}
		}
		else
		{
			while(!isOkay(out))
			{
				out++;
			}
			curr = out;
		}
		cout << curr << ' ';
		for(auto j : factors[curr])
		{
			used[j] = true;
		}
	}
	return 0;
}