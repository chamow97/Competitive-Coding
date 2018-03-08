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

ll fastpow(ll a,ll b){
	if(b==0)
		return 1LL;
	ll temp=(fastpow(a,b/2) % MODULO);
	temp=((temp % MODULO)*(temp % MODULO)) % MODULO;
	if(b%2==1)
		temp=((temp % MODULO)*(a % MODULO))%MODULO;
	return temp % MODULO;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	ll temp = 3 * n;
	ll total = fastpow(3, temp);
	ll extra = fastpow(7, n);
	cout << (total - (extra - MODULO)) % MODULO;
	return 0;
}