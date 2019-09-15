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
	// Best problem I have done in a long time
	// Say we select AAAAABBBCCCCC
	// where A represents prefix and C represents suffix, all the Bs are unchanged
	// let x be sum of unchanged
	// let y be sum of all the numbers
	// (y - x) is sum of changing number
	// since its going to be negated, its -(y - x)
	// so we have to maximize x - (y - x)
	// let F = x - (y - x)
	// task is to maximize
	// since y is constant, we have to maximize 2 * x or simply, x
	// so its KADANE's ALGORITHM 
	// let get started! 
	ll n;
	cin >> n;
	vec arr(n + 1);
	ll sum = 0;
	rep(i,1,n+1)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	ll maxSoFar = 0, maximimum = 0;
	rep(i,1,n+1)
	{
		maxSoFar += arr[i];
		if(maxSoFar < 0)
		{
			maxSoFar = 0;
		}
		maximimum = max(maximimum, maxSoFar);
	}
	ll ans = (2 * maximimum) - sum;
	cout << ans;
	return 0;
}