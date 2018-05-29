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

vector<long long> dp(5e6, 0);
int main()
{
	fastread;
	long long r, g;
	cin >> r >> g;
	if(r > g)
	{
		swap(r, g);
	}
	long long maxHeight = 0;
	long long ans = 0;
	long long totalBlocks = r + g;
	while(maxHeight * (maxHeight + 1) <= 2 * totalBlocks)
	{
		maxHeight++;
	}
	maxHeight -= 1;
	long long totalPossible = (maxHeight * (maxHeight + 1)) / 2;
	dp[0] = 1;
	for(long long i = 1; i <= maxHeight; i++)
	{
		for(long long j = totalBlocks; j >= 0; j--)
		{
			if(j - i >= 0)
			{
				dp[j] += dp[j-i];
				if(dp[j] >= MODULO)
				{
					dp[j] -= MODULO;
				}
			}
		}
	}		
	for(long long i = 0; i <= g; i++)
	{
		long long value = totalPossible - i;
		if(value >= 0 && value <= r)
		{
			ans = ((ans % MODULO) + (dp[value] % MODULO)) % MODULO;
		}
	}
	cout << ans;
	return 0;
}