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
	vec arr(n + 1,0);
	vec prefix(n + 1,0);
	vec suffix(n + 2,0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	if(n == 1)
	{
		cout << 1 << ' ' << 0;
		return 0;
	}
	rep(i,1,n+1)
	{
		prefix[i] = prefix[i-1] + arr[i];
	}
	per(j,n,1)
	{
		suffix[j] = suffix[j+1] + arr[j];
	}
	ll ptr1 = 1, ptr2 = n;
	while(ptr1 < ptr2 - 1)
	{
		// cout << ptr1 << ' ';
		if(prefix[ptr1] <= suffix[ptr2])	 	
		{
			++ptr1;
		}
		else 
		{
			--ptr2;
		}
	}
	cout << ptr1 << ' ' << (n - ptr2 + 1);
	return 0;
}
