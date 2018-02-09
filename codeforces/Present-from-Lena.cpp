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
	ll counter = 1;
	bool q = false;
	rep(i,0,2*n+1)
	{
		rep(j,0,abs(n - i))
		{
			cout << "  ";
		}
		ll ptr = 0;
		bool p = false;
		rep(k,0,counter)
		{
			if(k == counter - 1)
			{
				cout << ptr;
			}
			else
			cout << ptr << ' ';
			if(!p)
			{
				ptr++;
			}
			else
			{
				ptr --;
			}
			if(ptr > n - abs(n - i))
			{
				p = true;
				ptr = (n - abs(n - i)) - 1;
			} 
			
		}
		if(!q)
		{
			counter += 2;
		}
		else
		{
			counter -= 2;
		}
		if(counter > (2*n + 1))
		{
			counter = 2*n + 1 - 2;
			q = true;
		}
		cout << '\n';
	}
	return 0;
}
