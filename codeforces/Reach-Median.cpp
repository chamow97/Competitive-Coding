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
	ll n, s;
	cin >> n >> s;
	vec arr(n + 1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	ans += abs(s - arr[(n + 1) / 2]);
	arr[(n + 1) / 2] = s;
	rep(i,(n + 1)/2 + 1, n + 1)
	{
		if(arr[i] < arr[i-1])
		{
			ans += (arr[i-1] - arr[i]);
			arr[i] = arr[i - 1];
		}
	}
	per(j,(n + 1) / 2 - 1, 1)
	{
		if(arr[j] > arr[j+1])
		{
			ans += (arr[j] - arr[j+1]);
			arr[j] = arr[j+1];
		}
	}
	cout << ans;
	return 0;
}