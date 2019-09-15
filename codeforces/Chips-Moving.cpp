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
	ll n;
	cin >> n;
	vec arr(n);
	rep(i,0,n)
	{
		cin >> arr[i];
	}
	ll minimum = INF;
	rep(i,0,n)
	{
		ll ans = 0;
		rep(j,0,i)
		{
			ll currDiff = abs(arr[i] - arr[j]);
			currDiff %= 2;
			if(currDiff == 1)
			{
				ans++;
			}
		}
		rep(k,i+1,n)
		{
			ll currDiff = abs(arr[k] - arr[i]);
			currDiff %= 2;
			if(currDiff == 1)
			{
				ans++;
			}
		}
		minimum = min(minimum, ans);
	}
	cout << minimum;
	return 0;
}