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
	cin >> n;
	string str;
	cin >> str;
	vector<string> a;
	rep(i,0,26)
	{
		rep(j,0,26)
		{
			string now = "";
			now += char(i + 'A');
			now += char(j + 'A');
			a.pb(now);	
		}
	}
	ll maximum = 0;
	string ans = "";
	rep(i,0,a.size())
	{
		ll now = 0;
		rep(j,0,n-1)
		{
			if(str[j] == a[i][0] && str[j+1] == a[i][1])
			{
				++now;
			}
		}
		if(maximum < now)
		{
			maximum = now;
			ans = a[i];
		}
	}
	cout << ans;
	return 0;
}