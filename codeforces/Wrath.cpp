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
	cin>>n;
	vec arr(n+100,0);
	rep(i,1,n+1)
	{
		cin>>arr[i];
	}
	boolean killed(n+100,false);
	ll ptr = n-1;
	per(j,n,2)
	{
		ptr = min(ptr, j-1);
		while(ptr >= (j-arr[j]) && ptr >= 1)
		{
			killed[ptr--] = true;
		}
	}
	ll ctr = 0;
	rep(i,1,n+1)
	{
		if(!killed[i])
		{
			ctr++;
		}
	}
	cout<<ctr;
	return 0;
}
