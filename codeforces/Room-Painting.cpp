//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	ll n, m;
	cin >> n >> m;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll ans = 0;
	sort(arr.begin(), arr.end());
	rep(i,0,m)
	{
		ll now;
		cin >> now;
		ll extra = *lower_bound(arr.begin(), arr.end(), now);
		ans += (extra - now);
	}
	cout << ans;
	return 0;
}