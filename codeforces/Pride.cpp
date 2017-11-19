//template by chamow
// not during contest saw editorial
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
ll n;
vec arr(3000,0);

bool check()
{
	ll nowGcd = arr[0];
	rep(i,1,n)
	{
		nowGcd = __gcd(nowGcd, arr[i]);
	}
	return (nowGcd != 1);
}	

int main()
{
	fastread;
	cin>>n;
	ll ones = 0;
	rep(i,0,n)
	{
		cin>>arr[i];
		if(arr[i] == 1)
		{
			++ones;
		}
	}
	if(check() == true)
	{
		cout<<-1;
		return 0;
	}
	if(ones > 0)
	{
		cout<<n - ones;
		return 0;
	}
	ll ans = INF;
	rep(i,0,n)
	{
		ll currGCD = 0;
		rep(j,i,n)
		{
			currGCD = __gcd(currGCD, arr[j]);
		
			if(currGCD == 1)
			{
				ans = min(ans, (j - i  + n - 1));
				break;
			}
		}
	}
	cout<<ans;

	return 0;
}
