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
	vector< pair<char, string> > p;
	fastread;
	ll n, ans = 0;
	cin >> n;
	vec safe(40, 1);
	rep(i,0,n)
	{
		char type;
		string str;
		cin >> type >> str;
		p.pb(mp(type, str));
	}
	//mark safe letters
	rep(i,0,n)
	{
		if(p[i].f == '!')
		{
			ll counter = 0;
			rep(j,0,26)
			{
				if(safe[j] == 1)
				{
					++counter;
				}
			}
			// cout << counter << '\n';
			if(counter == 1)
			{
				ans++;
			}
			vec temp(30, 0);
			rep(j,0,p[i].s.length())
			{
				temp[p[i].s[j] - 'a'] = 1;
			}
			rep(j,0,26)
			{
				safe[j] = safe[j] && temp[j];
			}
		}
		if(p[i].f == '.')
		{
			rep(j,0,p[i].s.length())
			{
				safe[p[i].s[j] - 'a'] = 0;
			}
		}
		if(p[i].f == '?')
		{
			ll counter = 0;
			rep(j,0,26)
			{
				if(safe[j] == 1)
				{
					++counter;
				}
			}
			if(counter == 1 && i < n - 1)
			{
				ans++;
			}
			safe[p[i].s[0] - 'a'] = 0;

		}
	}
	cout << ans;
	return 0;
}