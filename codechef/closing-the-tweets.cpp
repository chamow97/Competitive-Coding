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
const ll maxn = 1e4;
vec segTree(maxn*5, 0);
vec lazyTree(maxn*5, 0);

void updateTree(ll position, ll a, ll b, ll i, ll j, ll value)
{
    //if the ith node is to be updated
    if(a > b)
    {
        return;
    }
    if(lazyTree[position] != 0)
    {
        lazyTree[(position*2)+1] = 1;
        lazyTree[(position*2)+2] = 1;
        segTree[(position*2)+1] = 0;
        segTree[(position*2)+2] = 0;
        lazyTree[position] = 0;
    }
    if(a > b || b < i || a > j)
    {
        return;
    }
    if(a >= i && b <= j)
    {
        segTree[position] = value;
    	return;
    }
    ll mid = (a+b)/2;
    updateTree((position*2)+1, a, mid, i, j, value);
    updateTree((position*2)+2, mid+1, b, i, j, value);
    segTree[position] = segTree[(position*2)+1] + segTree[(position*2)+2];
}

ll queryTree(ll position, ll a, ll b, ll i, ll j)
{
    if(a > b || b < i || a > j)
    {
        return 0;
    }
    if(lazyTree[position] != 0)
    {
       lazyTree[(position*2)+1] = 1;
        lazyTree[(position*2)+2] = 1;
        segTree[(position*2)+1] = 0;
        segTree[(position*2)+2] = 0;
        lazyTree[position] = 0;

    }
    if(a >= i && b <= j)
    {
        return segTree[position];
    }
    ll mid = (a+b)/2;
    return queryTree((2*position)+1, a, mid, i, j) + queryTree((2*position)+2, mid+1, b, i, j);
}


int main()
{
	fastread;
	ll n, k;
	cin>>n>>k;
	rep(i,0,k)
	{
		string str;
		ll pos;
		cin>>str;
		if(str[2] == 'O')
		{
			lazyTree[0] = 1;
			segTree[0] = 0;			
			cout<<0<<'\n';
		}
		else
		{
			cin>>pos;
			--pos;
			ll currVal = queryTree(0, 0, n-1, pos, pos);
			if(currVal == 1)
			{
				currVal = 0;
			}
			else
			{
				currVal = 1;
			}
			updateTree(0, 0, n-1, pos, pos, currVal);
			cout<<segTree[0]<<'\n';
		}

	}
	return 0;
}
