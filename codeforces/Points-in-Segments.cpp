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
	vec arr(m + 10, 0);
	rep(i,0,n)
	{
		ll a, b;
		cin >> a >> b;
		arr[a]++;
		arr[b+1]--;
	}
	rep(i,1,m+1)
	{
		arr[i] += arr[i-1];
	}
	vec ans;
	rep(i,1,m+1)
	{
		if(arr[i] == 0)
		{
			ans.pb(i);
		}
	}
	cout << ans.size() << '\n';
	rep(i,0,ans.size())
	{
		cout << ans[i] << ' ';
	}
	return 0;
}
