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
	ll n, m;
	cin >> n >> m;
	map<ll, ll> m1;
	vec arr(n+1, 0);
	set<ll> s;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		m1[arr[i] % m]++;
	}
	rep(i,0,m)
	{
		if(m1[i] < n/m)
		{
			s.insert(i);
			s.insert(i+m);
		}
	}
	ll answer = 0;
	rep(i,1,n+1)
	{
		if(m1[arr[i] % m] > n/m)
		{
			m1[arr[i] % m]--;
			auto val = s.lower_bound(arr[i] % m);
			m1[(*val) % m]++;
			ll now = (*val - (arr[i] % m));
			arr[i] += now;
			answer += (now);
			ll temp = *val;
			if(m1[(*val) % m] == n/m)
			{
				s.erase(temp % m);
				s.erase((temp % m) + m);
			}
		}
	}
	cout << answer << '\n';
	rep(i,1,n+1)
	{
		cout << arr[i] << ' ';
	}
	return 0;
}