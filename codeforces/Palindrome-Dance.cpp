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
	fastread
	ll n, a, b;
	cin >> n >> a >> b;
	vec arr(n, 0);
	ll ans = 0;
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	rep(i,0,(n + 1)/2)
	{
		if(arr[i] == 2 && arr[n-i-1] == 2)
		{
			if(i != (n - i - 1))
			ans += (2 * min(a, b));
			else
				ans += (min(a, b));
		}
		else if(arr[i] == arr[n-1-i] && arr[i] != 2)
		{
			continue;
		}
		else if(arr[i] == 1 && arr[n-1-i] == 2)
		{
			ans += b;
		}
		else if(arr[i] == 2 && arr[n-1-i] == 1)
		{
			ans += b;
		}
		else if(arr[i] == 0 && arr[n-1-i] == 2)
		{
			ans += a;
		}
		else if(arr[i] == 2 && arr[n-1-i] == 0)
		{
			ans += a;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}