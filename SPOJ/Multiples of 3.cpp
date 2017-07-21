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

struct segTree{
	ll rem1, rem2, rem3;
	segTree()
	{
		rem1 = 0, rem2 = 0, rem3 = 0;
	}
}t[400001];
ll lazy[400001];
ll type, l, r;

void makeTree(ll a, ll b, ll value)
{
	if(a == b)
	{
		t[value].rem1 = 0;
		t[value].rem2 = 0;
		t[value].rem3 = 1;
		return;
	}
	ll mid = (a + b)/2;
	makeTree(a, mid, 2*value + 1);
	makeTree(mid+1, b, 2*value + 2);
	t[value].rem1 = t[2*value + 1].rem1 + t[2*value + 2].rem1;
	t[value].rem2 = t[2*value + 1].rem2 + t[2*value + 2].rem2;
	t[value].rem3 = t[2*value + 1].rem3 + t[2*value + 2].rem3; 
}

void update(ll a, ll b, ll value)
{
	if(lazy[value] != 0)
	{
		lazy[value] %= 3;
		if(lazy[value] == 1)
		{
			ll temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
		}
		else if(lazy[value] == 2)
		{
			ll temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
			temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
		}
		if(a != b)
		{	
			lazy[2*value + 1] += lazy[value];
			lazy[2*value + 2] += lazy[value];
		}
		lazy[value] = 0;
	}
	if(a > r || b < l)
	{
		return;
	}
	if(a >= l && b <= r)
	{
		ll temp = t[value].rem1;
		t[value].rem1 = t[value].rem2;
		t[value].rem2 = t[value].rem3;
		t[value].rem3 = temp; 
		if(a != b)
		{
			lazy[2*value + 1]++;
			lazy[2*value + 2]++;
		}
		return;
	}
	ll mid = (a+b)/2;
	update(a, mid, 2*value + 1);
	update(mid+1, b, 2*value + 2);
	t[value].rem1 = t[2*value + 1].rem1 + t[2*value + 2].rem1;
	t[value].rem2 = t[2*value + 1].rem2 + t[2*value + 2].rem2;
	t[value].rem3 = t[2*value + 1].rem3 + t[2*value + 2].rem3; 

}
ll query(ll a, ll b, ll value)
{
	if(lazy[value] != 0)
	{
		lazy[value] %= 3;
		if(lazy[value] == 1)
		{
			ll temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
		}
		else if(lazy[value] == 2)
		{
			ll temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
			temp = t[value].rem1;
			t[value].rem1 = t[value].rem2;
			t[value].rem2 = t[value].rem3;
			t[value].rem3 = temp; 
		}
		if(a != b)
		{	
			lazy[2*value + 1] += lazy[value];
			lazy[2*value + 2] += lazy[value];
		}
		lazy[value] = 0;
	}
	if(a > r || b < l)
	{
		return 0;
	}
	if(a >= l && b <= r)
	{
		return t[value].rem3;
	}
	ll mid = (a+b)/2;
	return query(a, mid, 2*value + 1) + query(mid+1, b, 2*value + 2);
}
int main()
{
	fastread;
	ll n, q;
	cin>>n>>q;
	memset(lazy, 0, sizeof lazy);
	makeTree(0ll, n-1, 0ll);
	while(q--)
	{
		cin>>type>>l>>r;
		if(type == 0)
		{
			update(0ll, n-1, 0ll);
		}
		else
		{
			cout<<query(0ll, n-1, 0ll)<<'\n';
		}
	}
	return 0;
}