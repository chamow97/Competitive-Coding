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

ll n;
string str;
map<ll, ll> m;
ll ans = 0;
ll x = 0, y = 0;
void solve()
{
	m[0] = -1;
	rep(i,0,n)
	{
		if(str[i] == '0')
		{
			++x;
		}
		else
		{
			++y;
		}
		if(m.count(y-x))
		{
			ans = max(ans, ll(i-m[y-x]));
		}
		else
		{
			m[y-x] = i;
		}
	}
	cout<<ans;
}

int main()
{
	fastread;
	cin>>n;
	cin>>str;
	solve();
	return 0;
}
