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

void solve()
{
	vec mod(5, 0);
	ll n;
	cin >> n;
	ll sum = 0;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		sum += val;
		val %= 4;
		mod[val]++;
	}
	if(sum % 4 != 0)
	{
		cout << -1;
	}
	else
	{
		ll ans = 0;
		ans += (min(mod[1], mod[3]));
		mod[1] -= ans;
		mod[3] -= ans;
		ll extra = max(mod[3], mod[1]);
		extra /= 2;
		mod[2] += extra;
		ans += extra;
		ans += mod[2]/2;
		cout << ans;
	}
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}
