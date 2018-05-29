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

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec arr(n+1, 0);
	rep(i,1,n+1)
	{
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	if(k == 0)
	{
		if(arr[1] == 1)
		{
			cout << -1;
		}
		else
		{
			cout << 1;
		}
		return 0;
	}
	if(k == n)
	{
		cout << arr[n];
		return 0;
	}
	ll val = arr[k];
	if(val == arr[k+1])
	{
		cout << -1;
		return 0;
	}
	cout << val;
	return 0;
}