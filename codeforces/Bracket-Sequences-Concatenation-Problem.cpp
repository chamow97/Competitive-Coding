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

int main()
{
	fastread;
	ll n;
	map<ll, ll> m;
	cin >> n;
	vec arr(n, 0);
	vec brr(n, 0);
	vector<string> str(n);
	rep(i,0,n)
	{
		cin >> str[i];
		ll curr = 0, minimum = 0;
		for(auto j : str[i])
		{
			if(j == '(')
			{
				curr++;
			}
			else
			{
				curr--;
			}
			minimum = min(minimum, curr);
		}
		arr[i] = curr;
		brr[i] = minimum;
	}
	rep(i,0,n)
	{
		if(arr[i] == brr[i])
		{
			m[arr[i]]++;
		}
	}
	ll ans = 0;
	rep(i,0,n)
	{
		if(brr[i] == 0)
		{
			ans += m[-arr[i]];
		}
	}
	cout << ans;
	return 0;
}