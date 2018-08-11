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
	ll sum = 0;
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, pair<ll, ll> > > arr(n);
	multiset<ll> s1;
	rep(i,0,n)
	{
		cin >> arr[i].f;
		arr[i].s.f = i;
	}
	rep(i,0,n)
	{
		cin >> arr[i].s.s;
	}
	sort(arr.begin(), arr.end());
	vec ans(n+1, 0);
	rep(i,0,n)
	{
		while(s1.size() > k)
		{
			ll val = *s1.begin();
			sum -= val;
			s1.erase(s1.begin());
		}
		ans[arr[i].s.f] = arr[i].s.s + sum;
		// cout << arr[i].s.s + sum << ' ';
		s1.insert(arr[i].s.s);
		sum += arr[i].s.s;
	}
	rep(i,0,n)
	{
		cout << ans[i] << ' ';
	}
	return 0;
}