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
 
int main()
{
	fastread;
	ll n, k;
	cin >> n >> k;
	vec arr(n), diff;
	ll ans = 0;
	rep(i,0,n) {
	    cin >> arr[i];
	}
	ans = arr[n - 1] - arr[0];
	rep(i,1,n) {
	    diff.pb(arr[i] - arr[i - 1]);
	}
	sort(diff.begin(), diff.end());
	reverse(diff.begin(), diff.end());
	k--;
	rep(i,0,k) {
	    ans -= diff[i];
	}
	cout << ans;
	return 0;
}