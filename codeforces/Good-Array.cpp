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
	vecpair arr(n);
	ll sum = 0;
	rep(i,0,n)
	{
		ll val;
		cin >> val;
		sum += val;
		arr[i].f = val;
		arr[i].s = i;
	}
	vec ans;
	sort(arr.begin(), arr.end());
	//without last element
	ll curr = sum - arr[n - 1].f;
	per(j, n - 2, 0)
	{
		if(curr - arr[j].f == arr[j].f)
		{
			ans.pb(arr[n - 1].s + 1);
			break;
		}
	}
	curr = sum;
	per(j,n - 2, 0)
	{
		if(curr - arr[j].f - arr[n - 1].f == arr[n - 1].f)
		{
			ans.pb(arr[j].s + 1);
		}
	} 
	cout << ans.size() << '\n';
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}