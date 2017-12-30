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
	ll k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	vec arr;
	arr.pb(k1);
	arr.pb(k2);
	arr.pb(k3);
	sort(arr.begin(), arr.end());
	if(arr[0] == 1 || (arr[0] == 2 && arr[1] == 2) || (arr[0] == 3 && arr[1] == 3 && arr[2] == 3) || (arr[0] == 2 && arr[1] == 4 && arr[2] == 4))
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
