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


ll n, k;
string str;
void solve()
{
	//for a
	ll left = 0, right = 0, ans = 0, counter = 0;
	while(right < n)
	{
		if(str[right] == 'a')
		{
			++counter;
		}
		while(counter > k)
		{
			if(str[left] == 'a')
			{
				--counter;
			}
			++left;
			
		}
		ans = max(ans, right - left + 1);
		++right;
	}
	//for b
	left = 0, right = 0, counter = 0;
	while(right < n)
	{
		if(str[right] == 'b')
		{
			++counter;
		}
		while(counter > k)
		{
			if(str[left] == 'b')
			{
				--counter;
			}
			++left;
			
		}
		ans = max(ans, right - left + 1);
		++right;
	}
	cout<<ans;
}

int main()
{
	fastread;
	cin>>n>>k;
	cin>>str;
	solve();
	return 0;
}
