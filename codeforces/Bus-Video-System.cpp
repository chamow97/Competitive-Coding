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
const ll MAXN = 2000;
ll n, w;
ll ans;
vec arr(MAXN, 0);

void binarySearch(ll low, ll high)
{
	if(high < low)
	{
		return;
	}
	ll mid = (low + high)/2;
	ll now = mid;
	bool possible = true;
	rep(i,1,n+1)
	{
		now += arr[i];
		if(now > w)
		{
			possible = false;
			break;
		}		
	}
	if(possible)
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
	fastread;
	cin >> n >> w;
	ll minimum = 0, sum = 0;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		sum += arr[i];
		if(sum > w)
		{
			cout << 0;
			return 0;
		}
		minimum = min(minimum, sum);
	}	
	binarySearch(0, w);
	cout << max(0LL, ans + minimum + 1);
	return 0;
}