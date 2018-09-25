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

ll ans = 0;
ll n, m;
vec arr(101, 0);
		
void binarySearch(ll low, ll high)
{
	if(high < low)
	{
		return;
	}
	ll mid = (low + high) / 2;
	ll curr = 0;
	rep(i,1,101)
	{
		curr += (arr[i] / mid);
	}
	if(curr >= n)
	{
		ans = mid;
		binarySearch(mid + 1, high);
	}
	else
	{
		binarySearch(low, mid - 1);
	}
}

int main()
{
	cin >> n >> m;
	rep(i,0,m)
	{
		int val;
		cin >> val;
		arr[val]++;
	}
	binarySearch(1, 100);
	cout << ans;
	return 0;
}