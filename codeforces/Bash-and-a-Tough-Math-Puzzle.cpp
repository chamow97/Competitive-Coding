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

	const ll maxn = 6e5 + 100;
	ll arr[maxn];
	ll segTree[5*maxn];
	ll ctr = 0;

	void constructTree(ll position, ll low, ll high)
	{
		if(low == high)
		{
			segTree[position] = arr[low];
		}
		else
		{
			ll mid = (low + high)/2;
			constructTree((2*position)+1, low, mid);
			constructTree((2*position)+2, mid+1, high);
			segTree[position] = __gcd(segTree[(2*position)+1], segTree[(2*position)+2]);
		}
	}

	void updateTree(ll position, ll a, ll b, ll i, ll j, ll value)
	{
	    //if the ith node is to be updated
	    if(a > b)
	    {
	        return;
	    }
	     if(a > b || b < i || a > j)
	    {
	        return;
	    }
	    if(a >= i && b <= j)
	    {
	    	segTree[position] = (value);
	        return;
	    }
	    ll mid = (a + b)/2;
	   	updateTree((position*2)+1, a, mid, i, j, value);
	   	updateTree((position*2)+2, mid+1, b, i, j, value);
	    segTree[position] = __gcd(segTree[(position*2)+1], segTree[(position*2)+2]);
	}

	void rangeQuery(ll position, ll i, ll j, ll a, ll b, ll x)
	{
		if(j < a || i > b || ctr > 1) // no overlap
		{
			return;
		}
		if(a == b)
		{
			if(segTree[position] % x != 0)
			{
				++ctr;
			}
			return;
		}
		if(i <= a && j >= b) //complete overlap
		{
			if(segTree[position] % x != 0)
			{
				ll mid = (a + b)/2;
				rangeQuery((2*position)+1, i, j, a, mid, x);
				rangeQuery((2*position)+2, i, j, mid + 1, b, x);
			
			}
		}
		else //partial overlap
		{
			ll mid = (a + b)/2;
			rangeQuery((2*position)+1, i, j, a, mid, x);
			rangeQuery((2*position)+2, i, j, mid + 1, b, x);	
		}
	}

	int main()
	{
		fastread;
		ll n;
		cin >> n;
		rep(i,0,n)
		{
			cin >> arr[i];
		}
		constructTree(0ll, 0ll, n-1);
		ll q;
		cin >> q;
		while(q--)
		{
			ll cases;
			cin >> cases;
			if(cases == 1)
			{
				ctr = 0;
				ll l, r, val;
				cin >> l >> r >> val;
				--l;
				--r;
				rangeQuery(0ll, l, r, 0ll, n-1, val);
				if(ctr <= 1)
				{
					cout << "YES";
				}
				else
				{
					cout << "NO";
				}
				cout << '\n';
			}
			else
			{
				ll pos, val;
				cin >> pos >> val;
				--pos;
				updateTree(0ll, 0ll, n-1, pos, pos, val);
			}
		}
		return 0;
	}
