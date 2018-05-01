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

ll ans = 0;
ll n, k;

void binarySearch(ll low, ll high)
{
	if(low > high)
	{
		return;
	}
	ll mid = (low + high)/2;
	ll val = mid;
	ll currVal = mid;
	ll currA = k;
	while(currVal > 0)
	{
		currVal = mid / currA;
		currA = currA * k;
		val += currVal;
		if(val >= n)
		{
			break;
		}
	}
	if(val >= n)
	{
		ans = mid;
		binarySearch(low, mid-1);
	}
	else
	{
		binarySearch(mid + 1, high);
	}
}

int main()
{
	fastread;
	cin >> n >> k;
	ll low = 0, high = 1e9;
	binarySearch(low, 1e9);
	cout << ans;
	return 0;
}