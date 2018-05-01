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
	ll n, s;
	cin >> n >> s;
	vecpair p;
	vec seq(200000);
	rep(i,0,n)
	{
		ll h, m;
		cin >> h >> m;
		ll time = h * 60 + m;
		seq[time] = 1;
	}
	rep(i,1,200000)
	{
		seq[i] += seq[i-1];
	}
	if(seq[0] == seq[s] && seq[0] == 0)
	{
		cout << 0 / 60 << ' ' << 0 % 60;
		return 0;
	}
	rep(i,0,200000)
	{
		if(i - s < 0)
		{
			continue;
		}
		if(i + s >= 200000)
		{
			continue;
		}
		if(seq[i] == seq[i-s-1] && seq[i] == seq[i+s])
		{
			cout << i / 60 << ' ' << i % 60;
			return 0;
		}
	}
	return 0;
}