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

ll n, m, k;
const ll maxn = 1e5 + 10;
vec rangeDiff(maxn, 0);
vector< pair< pair<ll, ll>, ll> > series(maxn);
vec arr(maxn, 0);
vec rangeArr(maxn, 0);
vec diff(maxn, 0);
int main()
{
	fastread;
	cin >> n >> m >> k;
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	rep(i,1,m+1)
	{
		ll l, r, d;
		cin >> l >> r >> d;
		series[i] = mp(mp(l, r), d);
	}
	rep(i,0,k)
	{
		ll l, r;
		cin >> l >> r;
		rangeDiff[l]++;
		rangeDiff[r+1]--;
	}
	rep(i,1,m+1)
	{
		rangeArr[i] = rangeDiff[i] + rangeArr[i-1];
	}
	rep(i,1,n+1)
	{
		diff[i] = arr[i] - arr[i-1];
	}
	rep(i,1,m+1)
	{
		auto curr = series[i];
		ll totalVal = curr.s * rangeArr[i];
		diff[curr.f.f] += totalVal;
		diff[curr.f.s + 1] -= totalVal; 	
	}
	rep(i,1,n+1)
	{
		arr[i] = arr[i-1] + diff[i];
		cout << arr[i] << ' ';	
	}

	return 0;
}