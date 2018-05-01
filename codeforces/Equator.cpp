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
	ll n, sum = 0, half = 0;
	cin >> n;
	vec arr(n, 0);
	rep(i,0,n)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	half = (sum + 1)/2;
	sum = 0;
	rep(i,0,n)
	{
		sum += arr[i];
		if(sum >= half)
		{
			cout << i + 1;
			return 0;
		}
	}
	return 0;
}