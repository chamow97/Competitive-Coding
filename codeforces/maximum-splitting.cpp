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
	ll q, n;
	cin>>q;
	while(q--)
	{
		cin>>n;
		if(n == 1 || n == 2 || n == 3)
		{
			cout<<-1<<'\n';
		}
		else if(n % 2 == 0)
		{
			cout<<n/4<<'\n';
		}
		else
		{
			if(n == 5 || n == 7 || n == 11)
			{
				cout<<-1<<'\n';
			}
			else
			{
				cout<<1 + (n-9)/4<<'\n';
			}

		}
	}
	return 0;
}
