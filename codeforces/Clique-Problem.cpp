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

bool myComp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
	return ((p1.first + p1.second) < (p2.first + p2.second));
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	vecpair p;
	int arr[1000];
	cout << arr;
	//nice question
	//if st has a "graph" word, the pb need 
	//not be solved using graphs :P
	rep(i,0,n)
	{
		ll x, val;
		cin >> x >> val;
		p.pb(mp(x,val));
	}
	//greedy
	sort(p.begin(), p.end(), myComp);
	ll last = 0;
	ll ans = 1;
	rep(i,1,n)
	{
		if(p[i].first - p[i].second >= (p[last].first + p[last].second))
		{
			ans++;
			last = i;
		}
	}
	cout << ans;
	return 0;
}
