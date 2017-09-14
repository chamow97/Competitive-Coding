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

struct eachQuery{
	ll type, start, end, val;
	eachQuery()
	{
		val = 0;
	}
};

vec segmentTree(1e6, 0);
vec lazyTree(1e6, 0);		
void updateTree(ll position, ll a, ll b, ll i, ll j, ll value)
{
    //if the ith node is to be updated
    if(a > b)
    {
        return;
    }
    if(lazyTree[position] != 0)
    {
        segmentTree[position] += (((lazyTree[position] % MODULO)*((b-a+1) % MODULO)) % MODULO);
        segmentTree[position] %= (MODULO);
        if(a != b)
        {
            lazyTree[(position*2)+1] += (lazyTree[position] % MODULO);
            lazyTree[(position*2)+2] += lazyTree[position];
            lazyTree[(position*2)+1] %= MODULO;
            lazyTree[(position*2)+1] %= MODULO;
        }
        lazyTree[position] = 0;
    }
    if(a > b || b < i || a > j)
    {
        return;
    }
    if(a >= i && b <= j)
    {
        segmentTree[position] += (((value % MODULO)*((b-a+1) % MODULO)) % MODULO);
        if(a != b)
        {
            lazyTree[(position*2)+1] += value;
            lazyTree[(position*2)+2] += value;
            lazyTree[(position*2)+1] %= MODULO;
            lazyTree[(position*2)+1] %= MODULO;
        }
        return;
    }
    ll mid = (a+b)/2;
    updateTree((position*2)+1, a, mid, i, j, value);
    updateTree((position*2)+2, mid+1, b, i, j, value);
    segmentTree[position] = segmentTree[(position*2)+1] + segmentTree[(position*2)+2];
    segmentTree[position] %= MODULO;
}

ll queryTree(ll position, ll a, ll b, ll i, ll j)
{
    if(a > b || b < i || a > j)
    {
        return 0;
    }
    if(lazyTree[position] != 0)
    {
        segmentTree[position] += (((lazyTree[position] % MODULO)*((b-a+1) % MODULO)) % MODULO);
        segmentTree[position] %= (MODULO);
        if(a != b)
        {
            lazyTree[(2*position)+1] += (lazyTree[position] % MODULO);
            lazyTree[(2*position)+2] += (lazyTree[position] % MODULO);
            lazyTree[(position*2)+1] %= MODULO;
            lazyTree[(position*2)+1] %= MODULO;
        }
        lazyTree[position] = 0;

    }
    if(a >= i && b <= j)
    {
        return (segmentTree[position] % MODULO);
    }
    ll mid = (a+b)/2;
    return ((queryTree((2*position)+1, a, mid, i, j) % MODULO) + (queryTree((2*position)+2, mid+1, b, i, j) % MODULO))%MODULO;
}

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{

		fill(segmentTree.begin(), segmentTree.end(), 0);

		fill(lazyTree.begin(), lazyTree.end(), 0);
		ll n, m;
		cin>>n>>m;
		eachQuery queries[m];
		rep(i,0,m)
		{
			cin>>queries[i].type>>queries[i].start>>queries[i].end;
			--queries[i].start;
			--queries[i].end;
			queries[i].val = 0;
		}
		rep(i,0,m)
		{
			if(queries[i].type == 2)
			{
				updateTree(0, 0, m-1, queries[i].start, queries[i].end, 1);
			}
		}
		per(i,m-1,0)
		{
			if(queries[i].type == 2)
			{
				ll currentVal = (queryTree(0, 0, m-1, i, i) % MODULO);
				updateTree(0, 0, m-1, queries[i].start, queries[i].end, currentVal);
				updateTree(0, 0, m-1, i, i, 0ll);
			}
		}
		rep(i,0,m)
		{
			queries[i].val = (queryTree(0, 0, m-1, i, i) % MODULO);
			// cout<<queries[i].val<<" ";
		}
		fill(segmentTree.begin(), segmentTree.end(), 0);

		fill(lazyTree.begin(), lazyTree.end(), 0);
		rep(i,0,m)
		{
			if(queries[i].type == 1)
			{
				updateTree(0, 0, n-1, queries[i].start, queries[i].end, queries[i].val + 1);
			}
		}
		rep(i,0,n)
		{
			cout<<(queryTree(0, 0, n-1, i, i) % MODULO)<<" ";
		}
		cout<<'\n';


	}
	return 0;
}