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
ll n;
const int maxn = 2e5+10;
map<ll, ll> m;
pair<ll, ll> arr[maxn];
ll position = 0;
void solve()
{
	set<ll> s;
	rep(i,1,n+1)
	{
		ll val = arr[i].second;
		// cout<<val<<" ";
		s.insert(val);
		set<ll> :: iterator it = s.lower_bound(val);
		if(it == s.begin())
		{
			++position;
			arr[i].first = position;
		} 
		else
		{
			--it;
			arr[i].first = arr[m[*it]].first;
			s.erase(it);
		}
	}
}	
int main()
{
	fastread;
	cin>>n;
	rep(i,1,n+1)
	{
		cin>>arr[i].second;
		arr[i].first = -1;
		m[arr[i].second] = i;
	}
	if(n == 1)
	{
		cout<<arr[1].second;
		return 0;
	}
	solve();
	sort(arr+1, arr+1+n);
	ll counter = 1;
	ll position = 1;
	// rep(i,0,n)
	// {
	// 	cout<<arr[i].first<<" "<<arr[i].second<<'\n';
	// }
	while(counter <= n)
	{
		while(arr[counter].first == position)
		{
			cout<<arr[counter].second<<" ";
			++counter;
		}
		cout<<'\n';
		++position;
	}
	return 0;
}
