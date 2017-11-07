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

ll NChooseK(ll n, ll k)
{
	ll answer = 1;
	rep(i,1,min(n-k, k)+1)
	{
		answer *= (n + 1 - i);
		answer /= i;
	}
	return answer;
}

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n, k;
		cin>>n>>k;
		//1C1 * (n-1)C(k-1)
		cout<<NChooseK(n-1, k-1)<<'\n';
	}
	
	return 0;
}
