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
	vec arr(n+1);
	vec maximum(n+2, 0);
	vec minimum(n+2, INF);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	rep(i,1,n+1)
	{
		maximum[i] = max(maximum[i-1], arr[i]);
	}
	per(j,n,1)
	{
		minimum[j] = min(minimum[j+1], arr[j]);
	}
	string str;
	cin >> str;
	rep(i,1,n)
	{
		if(str[i-1] == '1')
		{
			continue;
		}
		if(maximum[i] > minimum[i+1])
		{
			cout << "NO";
			return 0;
		}

	}
	cout << "YES";
	return 0;
}