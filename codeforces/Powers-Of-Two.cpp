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
	ll n, k;
	cin >> n >> k;
	if(k > n)
	{
		cout << "NO";
		return 0;
	}
	vec binary;
	while(n > 0)
	{
		binary.pb(n % 2);
		n /= 2;
	}
	multiset<ll> ms;
	rep(i,0,binary.size())
	{
		if(binary[i] == 1)
		{
			ms.insert(pow(2, i));
		}
	}
	ll currSize = ms.size();
	while(currSize < k)
	{
		auto it = ms.end();
		--it;
		ll bigNumber = *it;
		ms.erase(it);
		ms.insert(bigNumber / 2);
		ms.insert(bigNumber / 2);
		currSize = ms.size();
	}
	if(ms.size() != k)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES\n";
	for(auto i : ms)
	{
		cout << i << ' ';
	}
	return 0;
}