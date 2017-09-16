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

unsigned long int choose(ll n, ll k)
{
	unsigned long int result = 1;
	if(k > (n/2))
	{
		k = n-k;
	}
	rep(i,0,k)
	{
		result *= (n-i);
		result /= (i+1);
	}
	return result;
}
int main()
{
	fastread;
	unsigned long int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		unsigned long int numerator = choose(2*n, n);
		// cout<<numerator;
		numerator /= (n+1);
		cout<<numerator<<'\n';
	}
	return 0;
}