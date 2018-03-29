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
	ll n, m;
	cin >> n >> m;
	vec arr(n+100, 0), brr(m+100, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
		arr[i] += arr[i-1];
	}
	rep(i,1,m+1)
	{
		cin >> brr[i];
		brr[i] += brr[i-1];
	}
	ll counter = 0;
	ll ptr1 = 1, ptr2 = 1;
	while(ptr1 <= n && ptr2 <= m)
	{
		if(arr[ptr1] == brr[ptr2])
		{
			++counter;
			ptr1++;
			ptr2++;
		}
		else if(arr[ptr1] < brr[ptr2])
		{
			++ptr1;
		}
		else
		{
			++ptr2;
		}
	}
	cout << counter;
	return 0;
}