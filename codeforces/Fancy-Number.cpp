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
	ll n, m, minimum = INF;
	string str, now, ans;
	cin >> n >> m;
	cin >> str;
	rep(i,0,10)
	{
		now = str;
		ll nowSize = 0, counter = 0;
		//already i
		for(ll j = 0; j < n && counter < m; j++)
		{
			if(now[j] == '0' + i)
			{
				++counter;
			}
		}
		for(ll k = 1; k < 10 && counter < m; k++)
		{
			for(ll j = 0; j < n && counter < m; j++)
			{
				if(now[j] == '0' + i + k)
				{
					now[j] = '0' + i;
					nowSize += k;
					counter++;
				}
			}
			for(ll j = n-1; j >= 0 && counter < m; j--)
			{
				if(now[j] == '0' + i - k)
				{
					now[j] = '0' + i;
					nowSize += k;
					counter++;
				}
			}
		}
		if(nowSize < minimum || (nowSize == minimum && now < ans))
		{
			minimum = nowSize;
			ans = now;
		}

	}
	cout << minimum << '\n' << ans;
	return 0;
}