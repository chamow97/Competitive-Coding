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

// ll findBase(ll n, ll b)
// {
// 	ll ans = 0;
// 	vec arr;
// 	while(n)
// 	{
// 		arr.pb(n % b);
// 		n /= b;
// 	}
// 	reverse(arr.begin(), arr.end());
// 	for(auto i : arr)
// 	{
// 		ans = (ans * 10)  + i;
// 	}
// 	return ans;
// }

bool isDivisible(ll x, ll y)
{
    if (y == 1)
        return true;
 
    if (__gcd(x, y) == 1)
        return false;
    return isDivisible(x, y / __gcd(x, y));
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		ll p, q, b;
		cin >> p >> q >> b;
		ll GCD = __gcd(p, q);
		q /= GCD;
		b = __gcd(q, b);
		while(b != 1)
		{
			while(q % b == 0)
			{
				q /= b;
			}
			b = __gcd(q, b);
		}
		if(q == 1)
		{
			cout << "Finite";
		}
		else
		{
			cout << "Infinite";
		}
		cout << '\n';	
	}
	return 0;
}