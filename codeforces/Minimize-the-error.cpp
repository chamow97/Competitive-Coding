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
	ll n, k1, k2;
	cin >> n >> k1 >> k2;
	vec arr(n, 0);
	vec brr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	rep(i,0,n)
	{
		cin >> brr[i];
	}
	multiset< pair<ll, ll >, greater< pair<ll, ll >  > > ms;
	rep(i,0,n)
	{
		ll error = pow(arr[i] - brr[i], 2);
		ms.insert(mp(error, i));
	}
	while(k1 > 0 || k2 > 0)
	{
		auto it = *ms.begin();
		ll pos = it.s;
		ll val = it.f;
		if(k1 > k2)
		{
			if(arr[pos] > brr[pos])
			{
				arr[pos] -= 1;
			}
			else
			{
				arr[pos] += 1;
			}
			--k1;
		}	
		else
		{
			if(arr[pos] > brr[pos])
			{
				brr[pos] += 1;
			}
			else
			{
				brr[pos] -= 1;
			}
			--k2;
		}
		ms.erase(ms.begin());
		ll newVal = pow(arr[pos] - brr[pos], 2);
		ms.insert(mp(newVal, pos));
	}
	ll newVal = 0;
	rep(i,0,n)
	{
		newVal += (pow(arr[i] - brr[i], 2));
	}
	cout << newVal;	
	return 0;
}