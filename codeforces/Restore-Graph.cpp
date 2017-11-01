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

#define maxn 500000
ll n, k;
vecpair arr(maxn);
vec *adj = new vec[maxn];
ll pos = -1;
vec capacity(maxn, 0);
// boolean connected(maxn, false);


void solve()
{
	ll ptr = 0;
	rep(i,1,n)
	{
		while(arr[ptr].f + 1 < arr[i].f || capacity[arr[ptr].s] >= k)
		{
			ptr++;
		}
		if(arr[ptr].f + 1 != arr[i].f)
		{
			cout<<-1;
			return;
		}
		adj[arr[ptr].s].pb(arr[i].s);
		capacity[arr[ptr].s]++;
		capacity[arr[i].s]++;	
	}
	cout<<n-1<<'\n';
	rep(i,0,n)
	{
		rep(j,0,adj[i].size())
		{
			cout<<i+1<<" "<<adj[i][j]+1<<'\n';
		}
	}

}
void input()
{
	cin>>n>>k;
	ll zeroes = 0, ones = 0;
	rep(i,0,n)
	{
		cin>>arr[i].f;
		arr[i].s = i;
		if(arr[i].f == 0)
		{
			pos = arr[i].s;
			++zeroes;
		}
		else if(arr[i].f == 1)
		{
			++ones;
		}

	}
	if(zeroes == 0 || zeroes > 1)
	{
		cout<<-1;
		return;
	}
	if(ones > k)
	{
		cout<<-1;
		return;
	}

	sort(arr.begin(), arr.begin()+n);
	solve();
}


int main()
{
	fastread;
	input();
	return 0;
}
