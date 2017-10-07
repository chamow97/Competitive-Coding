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
	vec frequency(4e6+10, 0);
	ll n;
	cin>>n;
	vec arr1(n+1,0);
	vec arr2(n+1,0);
	rep(i,0,n)
	{
		ll temp;
		cin>>temp;
		arr1[i+1] = temp;
		frequency[temp]++;
	}

	rep(i,0,n)
	{
		ll temp;
		cin>>temp;
		arr2[i+1] = temp;
		frequency[temp]++;
	}
	ll counter = 0;
	rep(i,1,n+1)
	{
		rep(j,1,n+1)
		{
			if(frequency[arr1[i] ^ arr2[j]] >= 1)
			{
				// cout<<i<<" "<<j<<endl;
				++counter;
			}
		}
	}
	// cout<<counter;
	if(counter % 2 == 0)
	{
		cout<<"Karen";
	}
	else
	{
		cout<<"Koyomi";
	}
	return 0;
}
