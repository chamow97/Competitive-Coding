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
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] += 5e5;
	}
	vecpair ans;
	ans.pb(mp(n, 5e5));
	rep(i,1,n+1)
	{
		ll now = arr[i];
		now -= i;
		rep(k,1,i+1)
		{
			arr[k] %= now;
		}
		ans.pb(mp(i, now));
	}
	cout << ans.size() << '\n';
	ll ptr = 0;
	for(auto i : ans)
	{
		if(ptr == 0)
		{
			cout << 1 << ' ';
		}
		else
		{
			cout << 2 << ' ';
		}
		cout << i.f << ' ' << i.s << '\n';	
		ptr++;
	}
	return 0;
}