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

ll func(ll mid)
{
	ll sum = mid;
	while(mid)
	{
		sum += (mid%10);
		mid /= 10;
	}
	return sum;
}

int main()
{
	fastread;
	ll n;
	cin>>n;
	vec ans;
	ll val = max(0ll,n-100);
	rep(i,val,n+1)
	{
		if(func(i) == n)
		{
			ans.pb(i);
		}
	}
	if(ans.size() == 0)
	{
		cout<<0;
	}
	else
	{
		cout<<ans.size()<<'\n';
		sort(ans.begin(), ans.end());
		rep(i,0,ans.size())
		{
			cout<<ans[i]<<" ";
		}
	}

	return 0;
}
