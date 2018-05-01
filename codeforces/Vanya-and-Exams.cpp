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
	ll n, r, avg;
	cin >> n >> r >> avg;
	ll sum = 0, total = 0;
	priority_queue<pair<ll, ll>, vecpair, greater<pair<ll, ll> > > q;
	rep(i,0,n)
	{
		ll a, b;
		cin >> a >> b;
		sum += a;
		q.push(mp(b, a));
	}
	ll cost = 0;
	ll want = avg * n;
	while(sum < want && !q.empty())
	{
		pair<ll, ll> p1 = q.top();
		q.pop();
		ll available = r - p1.s;
		ll now = want - sum;
		if(available < now)
		{
			sum += (available);
			cost += (available * p1.f);
		}
		else
		{
			cost += (now * p1.f);
			sum = want;
		}
	}
	cout << cost;
	return 0;
}