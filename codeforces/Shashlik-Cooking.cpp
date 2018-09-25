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
	// ll dp[1100][1100];
int main()
{
	fastread
	ll n, k;
	ll steps = 0;
	cin >> n >> k;
	ll last;
	if(n <= (k) + 1)
	{
		cout << 1 << '\n';
		cout << n;
		return 0;
	}
	else if(n <= (2 * k) + 1)
	{
		cout << 1 << '\n';
		cout << k + 1;
		return 0;
	}
	vec ans;
	ll j = k;
	while((j + 1 + k) <= n)
	{
		j++;
		ans.pb(j);
		last = j + k;
		j += k;
		j += k;
		++steps;
	}
	if(last < n)
	{
		if(last + k + 1 <= n)
		ans.pb(last + k + 1);
		else
		{
			ll extra = last + k + 1 - n;
			rep(i,0,ans.size())
			{
				ans[i] = ans[i] - extra;
			}
			ans.pb(n);
		}
		++steps;
	}
	
	cout << steps << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i] << ' ';
	}
	return 0;
}