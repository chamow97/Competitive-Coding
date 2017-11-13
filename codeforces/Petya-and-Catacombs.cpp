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

bool cmp(const pair<ll, ll> &p1, const pair<ll, ll> &p2)
{
	return p1.first < p2.first;
}

int main()
{
	fastread;
	ll n;
	cin>>n;
	vecpair arr;
	rep(i,1,n+1)
	{
		ll a;
		cin>>a;
		arr.pb(mp(a, i));
	}
	sort(arr.begin(), arr.end());
	boolean visited(n,false);
	ll counter = 0;
	rep(i,0,n)
	{
		if(visited[i] == false)
		{
			++counter;
			visited[i] = true;
			ll next = (lower_bound(arr.begin(), arr.end(), pair<ll, ll>(arr[i].second, 0), cmp) - arr.begin());
			while(next != n)
			{
				visited[next] = true;
				next = (lower_bound(arr.begin(), arr.end(), pair<ll, ll>(arr[next].second, 0), cmp) - arr.begin());
			
			}
		}
		
	}
	cout<<counter;
	return 0;
}
