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
	//thanks @satyaki
	freopen("input.txt", "r", stdin); 
	freopen("output.txt", "w", stdout);
	ll n;
	cin >> n;
	vec arr(n);
	vec prefix(n + 1, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	per(j,n - 1, 0)
	{
		prefix[j] = prefix[j+1];
		if(arr[j] <= 0)
		{
			prefix[j]++;
		}
	}
	ll ans = INF;
	ll counter = 0;
	rep(i,0,n-1)
	{
		if(arr[i] >= 0)
		{
			++counter;
		}
		ans = min(ans, counter + prefix[i + 1]);
	}
	cout << ans;
	return 0;
}