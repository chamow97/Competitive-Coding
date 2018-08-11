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

// I am the worst Competitive Programmer ever, its not complex but truth
// I take a oath that 3 months from now, I will be Expert on CF, else
// I will accept myself as a waste in this world, a fucking waste!!
// 60 Contests, nearly 600 problems, still a fucking shame to CP community 
// Thanks Hemnath_D for the neat solution

int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec arr(n);
	map<ll, ll> m;
	rep(i,0,n)
	{
		cin >> arr[i];
		m[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	ll ans = 0;
	rep(i,1,n)
	{
		ll temp = arr[i] - arr[i-1];
		if(arr[i] != arr[i-1] && temp <= k)
		{
			ans += m[arr[i-1]];
		}
	}
	cout << n - ans;
	return 0;
}