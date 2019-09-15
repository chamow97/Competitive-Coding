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
	vec arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	multiset< pair<ll, ll> > ms;
	rep(i,0,n)
	{
		ms.insert(mp(i + 1, arr[i]));
	}
	ll m;
	cin >> m;
	while(m--)
	{
		ll q;
		cin >> q;
		if(q == 1)
		{
			ll p, x;
			cin >> p >> x;
			auto it = ms.lower_bound(mp(p, -INF));
			while(it != ms.end() && x > 0)
			{
				ll val = (*it).s;
				ll index = (*it).f;
				ms.erase(it);
				val -= x;
				if(val <= 0)
				{
					x = abs(val);
					it = ms.lower_bound(mp(index + 1, -INF));
				}
				else
				{
					ms.insert(mp(index, val));
					break;
				}
			}
		}
		else
		{
			ll k;
			cin >> k;
			auto it = ms.lower_bound(mp(k, -INF));
			if((*it).f != k)
			{
				cout << arr[k - 1];
			}
			else
			{
				cout << arr[k - 1] - (*it).s;
			}
			cout << '\n';
		}
	}
	return 0;
}