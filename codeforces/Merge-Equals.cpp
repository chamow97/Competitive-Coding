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

bool myFunc(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
	return p1.s < p2.s;
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	vecpair ans;
	multiset< pair<ll, ll> > ms;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		ms.insert(mp(val, i));
	}
	while(!ms.empty())
	{
		auto val1 = *ms.begin();
		ms.erase(ms.begin());
		if(ms.empty())
		{
			ans.pb(val1);
			break;
		}
		auto val2 = *ms.begin();
		ms.erase(ms.begin());
		if(val1.f == val2.f)
		{	
			ms.insert(mp((2 * val1.f), val2.s));
		}
		else
		{
			ms.insert(val2);
			ans.pb(val1);
		}
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end(), myFunc);
	rep(i,0,ans.size())
	{
		cout << ans[i].f << ' ';
	}
	return 0;
}