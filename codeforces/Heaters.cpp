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
	ll n, r;
	cin >> n >> r;
	vec arr(n + 1, 0);
	vec difference(3000, 0);
	vec pos;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		if(arr[i] == 1)
		{
			pos.pb(i);
		}
	}
	if(pos.size() == 0)
	{
		cout << -1;
		return 0;
	}
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	if(r == 1)
	{
		if(pos.size() == n)
		{
			cout << n;
			return 0;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	rep(i,0,pos.size())
	{
		rep(j,pos[i] - r + 1, pos[i] + r)
		{
			if(j == pos[i])
			{
				continue;
			}
			if(j <= 0)
			{
				continue;
			}
			if(j > n)
			{
				break;
			}
			arr[j]++;
		}
	}
	ll ans = 0;
	rep(i,0,pos.size())
	{
		bool yes = true;
		rep(j,pos[i] - r + 1, pos[i] + r)
		{
			if(j <= 0)
			{
				continue;
			}
			if(j > n)
			{
				break;
			}
			arr[j]--;
		}
		rep(j,1,n+1)
		{
			if(arr[j] <= 0)
			{
				yes = false;
				break;
			}
		}
		if(!yes)
		{
			rep(j,pos[i] - r + 1, pos[i] + r)
			{
				if(j <= 0)
				{
					continue;
				}
				if(j > n)
				{
					break;
				}
				arr[j]++;
			}
		}
		else
		{
			ans++;
		}
		
	}
	rep(i,1,n+1)
	{
		if(arr[i] == 0)
		{
			cout << -1;
			return 0;
		}
	}
	cout << pos.size() - ans;
	return 0;
}