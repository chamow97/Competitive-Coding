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

ll gcd(ll a, ll b)
{
	if(b == 0)
	{
		return a;
	}
	return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}

/*-------------------------------------------------------- */

ll ans = 0;

void binarySearch(ll low, ll high, vec &arr, ll totalMoney, ll n)
{
	if(low > high)
	{
		return;
	}
	ll mid = (low + high) / 2;
	vec newArr(n, 0);
	rep(i,0,n)
	{
		newArr[i] = arr[i] + ((i + 1) * mid);
	}
	sort(newArr.begin(), newArr.end());
	ll newSum = 0;
	rep(i,0,mid)
	{
		newSum += newArr[i];
	}
	if(newSum <= totalMoney)
	{
		ans = mid;
		low = mid + 1;
	}
	else
	{
		high = mid - 1;
	}
	binarySearch(low, high, arr, totalMoney, n);
}

int main()
{
	ll n, s;
	cin >> n >> s;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	binarySearch(0ll, n, arr, s, n);
	vec newArr(n);
	rep(i,0,n)
	{
		newArr[i] = arr[i] + ((i + 1) * ans);
	}
	sort(newArr.begin(), newArr.end());
	ll finalAns = 0;
	rep(i,0,ans)
	{
		finalAns += newArr[i];
	}
	cout << ans << ' ' << finalAns;
	return 0;
}