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
const ll maxn = 3e6 + 1000;
vec arr(maxn, 0);
vec prefix(maxn, 0);
vec ans(maxn, 0);
ll findVal(ll i)
{
	ll even = 0, odd = 0;
	while(i)
	{
		ll temp = i % 10;
		if(temp % 2 == 0)
		{
			even += temp;
		}
		else
		{
			odd += temp;
		}
		i /= 10;
	}
	return abs(odd - even);
}
int main(int argc, char const *argv[])
{
	rep(i,2,maxn)
	{
		arr[i] = findVal(i);
		prefix[i] = arr[i] + prefix[i-1];	
	}
	ans[2] = 2;
	ans[4] = 12;
	rep(i,6,maxn-10)
	{
		ans[i] = (ans[i-2]) + 2*(prefix[i] - prefix[i/2] - arr[i]) + arr[i];
		i++;
	}
	ll t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		cout << ans[n * 2] << '\n';
	}

	return 0;
}
