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
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll remaining = pow(2,32);
		ll sum = 0;
		cout<<1<<" "<<2<<" ";
		remaining -= 5;
		sum += 5;
		ll i = 2;
		while(i < n)
		{
			if(remaining > 1e5)
			{
				cout<<1e5<<" ";
				sum += 1e5;
				remaining -= 1e5;
				i++;
			}
			else
			{
				break;
			}
		}
		rep(k,i,n-1)
		{
			cout<<1<<" ";
			sum += 1;
			remaining -= 1;
		}
		cout<<remaining;
		sum += remaining;
		// cout<<"ASDA"<<sum;

		cout<<'\n';
	}
	return 0;
}
