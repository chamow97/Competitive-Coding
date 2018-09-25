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
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


/*-------------------------------------------------------- */
int main()
{
	fastread
	ll n;
	cin >> n;
	vec arr(n, 0);
	ll ans = 0;
	bool positive = false;
	bool negative = false;
	ll minimum = INF;
	ll maximum = -INF;
	rep(i,0,n)
	{
		cin >> arr[i];
		if(arr[i] < 0)
		{
			negative = true;
		}
		if(arr[i] >= 0)
		{
			positive = true;
		}
		minimum = min(minimum, arr[i]);
		maximum = max(maximum, arr[i]);
		ans += abs(arr[i]);
	}
	if(n == 1)
	{
		cout << arr[0];
	}
	else if(negative && positive)
	{
		cout << ans;
	} 
	else if(positive)
	{
		cout << ans - 2 * minimum;
	}
	else if(negative)
	{
		cout << ans + 2 * maximum;
	}
	return 0;
}