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
	ll perimeter = 0;
	ll n;
	ll ans = 0;
	cin >> n;
	vec arr(n+1,0);
	vector<ll> prefix;
	prefix.pb(0);
	rep(i,0,n)
	{
		cin >> arr[i];
		perimeter += arr[i];
		if(i != n-1)
		prefix.pb(perimeter);
	}
	if(perimeter % 3 != 0)
	{
		cout << 0;
		return 0;
	}
	ll val1 = perimeter/3;
	ll val2 = (perimeter/3)*2;
	for(auto i : prefix)
	{
		if(binary_search(prefix.begin(), prefix.end(),val1 + i) == true && binary_search(prefix.begin(), prefix.end(),val2 + i) == true)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;

}
