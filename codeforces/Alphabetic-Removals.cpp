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
	ll n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	map<ll, ll> m;
	vec ctr(30, 0);
	rep(i,0,str.length())
	{
		m[str[i] - 'a']++;
		ctr[str[i] - 'a']++;
	}
	ll counter = 0;
	while(counter <= k)
	{
		rep(i,0,26)
		{
			if(m[i] > 0)
			{
				m[i]--;
				++counter;
				break;
			}
		}
		if(counter >= k)
		{
			break;
		}
	}
	rep(i,0,n)
	{
		if(ctr[str[i] - 'a'] <= m[str[i] - 'a'])
		{
			cout << str[i];
			ctr[str[i] - 'a']--;
		}
		else
		{
			ctr[str[i] - 'a']--;
		}
	}
	return 0;
}