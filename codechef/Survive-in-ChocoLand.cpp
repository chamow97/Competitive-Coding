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

void solve()
{
	ll n, k, s;
	cin >> n >> k >> s;
	ll ans = 0;
	if(n < k)
	{
		cout << -1;
		return;
	}
	ll counter = 0;
	ll p = n, r = s;
	ans = 1;
	while(r--)
	{
		++counter;
		if(p < k)
		{
			if(counter % 7 == 0)
			{
				ll maximumPossible = counter - ans - 1;
				ll newAns = maximumPossible * n;
				if(newAns < k)
				{
					cout << -1;
					return;
				}
				else
				{
					ll div = k/n;
					if((div * n) < k)
					{
						div++;
					}
					p += (n * div);
					p -= k;
					ans += (div);
				}
			}
			else
			{
				++ans;
				p += n;
				p -= k;
			}
		}
		else
		{
			p -= k;
		}
	}
	cout << ans;
}

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		solve();
		cout << '\n';
	}
	return 0;
}
