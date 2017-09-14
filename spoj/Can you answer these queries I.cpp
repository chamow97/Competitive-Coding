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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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

ll arr[50001];
ll segTree[200001];
ll l, r;
void buildTree(ll a, ll b, ll value)
{
	if(a == b)
	{
		segTree[value] = arr[a];
	}
	else
	{
		ll mid = (a+b)/2;
		buildTree(a, mid, 2*value + 1);
		buildTree(mid+1, b, 2*value + 2);
		segTree[value] = segTree[value*2 + 1] + segTree[value*2 + 2];
	}
}
ll query(ll a, ll b, ll value)
{
	if(a > r || b < l)
	{
		return -10000000;
	}
	if(l <= a && r >= b)
	{
		return segTree[value];
	}
	ll mid = (a+b)/2;
	return max(query(a, mid, 2*value + 1), query(mid+1, b, 2*value + 2));
}

int main()
{
	fastread;
	ll n, m;
	cin>>n;
	rep(i,0,n)
	{
		cin>>arr[i];
	}
	memset(segTree, -100000, sizeof segTree);
	buildTree(0ll, n-1, 0ll);
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		--l;
		--r;
		cout<<query(0ll, n-1, 0ll)<<'\n';
	}
	return 0;
}