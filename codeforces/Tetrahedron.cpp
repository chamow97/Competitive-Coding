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

ll dp[2][10000001];
int main()
{
	fastread;
	ll n;
	cin >> n;
	dp[1][1] = 0;
	dp[0][1] = 1;
	rep(i,2,n+1)
	{
		dp[1][i] = (3 * dp[0][i-1]) % MODULO;
		dp[0][i] = ((2 * dp[0][i-1]) % MODULO + (dp[1][i-1]) % MODULO) % MODULO;
	}
	cout << dp[1][n];
	return 0;
}