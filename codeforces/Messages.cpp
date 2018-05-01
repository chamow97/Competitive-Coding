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
	ll n, a, b, c, t;
	cin >> n >> a >> b >> c >> t;
	vec arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll choice1 = a * n;
	ll choice2 = 0;
	rep(i,0,n)
	{
		choice2 += (a - b * (t - arr[i]) + c * (t - arr[i]));
	}
	cout << max(choice2, choice1);
	return 0;
}