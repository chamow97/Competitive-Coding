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
	vec arr(n,0);
	set<ll> s1;
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	if(n == 1)
	{
		cout << -1;
		return 0;
	}
	sort(arr.begin(), arr.end());
	rep(i,1,n)
	{
		s1.insert(arr[i] - arr[i-1]);
	}
	if(arr[0] == arr[n-1])
	{
		cout << 1 << '\n' << arr[0];
		return 0;
	}
	if(s1.size() == 1)
	{
		ll d = *s1.begin();
		if(n == 2)
		{
			if(d % 2 == 0)
			{
				cout << 3 << '\n' << arr[0] - d << ' ' << arr[0] + (d/2) << ' ' << arr[n-1] + d;
			}
			else
			{
				cout << 2 << '\n' << arr[0] - d << ' ' << arr[n-1] + d;
			}
		}
		else
		{
			cout << 2 << '\n' << arr[0] - d << ' ' << arr[n-1] + d;
		}
	}
	else if(s1.size() == 2)
	{
		ll possibility1 = *s1.begin();
		ll possibility2 = *s1.rbegin();
		ll counter2 = 0;
		//if one is a multiple of the other, then it might be possible
		if(possibility1*2 == possibility2)
		{
			rep(i,1,n)
			{
				if(arr[i] - arr[i-1] == possibility2)
				{
					++counter2;
				}
			}
			if(counter2 == 1)
			{
				cout << 1 << '\n';
				rep(i,1,n)
				{
					if(arr[i] - arr[i-1] == possibility2)
					{
						cout << arr[i-1] + possibility1 << ' ';
						break;
					}
				}
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			cout << 0;
		}

	}
	else
	{
		cout << 0;
	}
	return 0;
}
