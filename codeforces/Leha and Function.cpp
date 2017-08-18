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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

bool myFunc(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
	return p1.first < p2.first;
}

int main()
{
	ll m;
	cin>>m;
	vec arr(m,0);
	vector< pair<ll, ll> > brr;
	rep(i,0,m)
	{
		cin>>arr[i];
	}
	rep(i,0,m)
	{
		ll temp;
		cin>>temp;
		brr.pb(mp(temp, i));
	}
	
	sort(arr.rbegin(), arr.rend());
	sort(brr.begin(), brr.end(), myFunc);
	vec crr(m,0);
	ll i = 0;
	rep(j,0,m)
	{
		crr[(brr[j]).second] = arr[j];
	}
	rep(i,0,m)
	{
		cout<<crr[i]<<" ";
	}
	return 0;
}