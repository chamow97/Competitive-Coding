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
#define MODULO 100000000
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
const ll maxn = 1e5 + 10;
vecpair arr(maxn);
vec dp(maxn, 0);
ll n;
bool comp(pair<ll, ll> &p1, const ll h)
{
	return p1.first < h;
}
void solve()
{
	dp[n-1] = 1;
	per(j,n-2,0)
	{
		ll pos = lower_bound(arr.begin() + j, arr.begin() + n, arr[j].second, comp) - arr.begin();
		dp[j] = 1 + dp[j+1] % MODULO;
		if(pos != n)
			dp[j] = ((dp[j] % MODULO) + (dp[pos] % MODULO))%MODULO; 	
	}
	ll temp = dp[0] % MODULO;
	string ans = "";
	ll counter = 0;
	while(temp)
	{
		temp /= 10;
		++counter;
	}
	while(counter < 8)
	{
		cout<<0;
		++counter;
	}
	cout<<(dp[0] % MODULO);
	cout<<'\n';
}

int main()
{
	fastread;
	while(1)
	{
		arr.clear();
		dp.clear();
		cin>>n;
		if(n == -1)
		{
			break;
		}
		rep(i,0,n)
		{
			cin>>arr[i].first>>arr[i].second;
		}
		sort(arr.begin(), arr.begin()+n);
		solve();
	}
	return 0;
}
