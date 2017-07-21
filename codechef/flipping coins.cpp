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
ll segTree[400004];
bool lazy[400004];
ll type, l, r;

void flip(ll a, ll b, ll current)
{
    if(a > b)
    {
        return;
    }
    if(lazy[current] == true)
    {
        segTree[current] = b-a+1 - segTree[current];
        if(a != b)
        {
            lazy[(2*current)+1] = (!lazy[(2*current)+1]);
            lazy[(2*current)+2] = (!lazy[(2*current)+2]);
        }
        lazy[current] = false;
    }
    if(l > b || r < a)
    {
        return;
    }
    if(a >= l && b <= r)
    {
        segTree[current] = b - a + 1 - segTree[current];
        if(a != b)
        {
            lazy[(2*current)+1] = (!lazy[(2*current)+1]);
            lazy[(2*current)+2] = (!lazy[(2*current)+2]);
        }
        return;
    }
    ll mid = (a + b)/2;
    flip(a, mid, (2*current)+1);
    flip(mid+1, b, (2*current)+2);
    segTree[current] = segTree[(2*current)+1] + segTree[(2*current)+2];
}

ll query(ll a, ll b, ll current)
{
    if(a > b)
    {
        return 0;
    }
    if(lazy[current] == true)
    {
        segTree[current] = b-a+1 - segTree[current];
        if(a != b)
        {
            lazy[(2*current)+1] = (!lazy[(2*current)+1]);
            lazy[(2*current)+2] = (!lazy[(2*current)+2]);
        }
        lazy[current] = false;
    }
    if(l > b || r < a)
    {
        return 0;
    }
    if(a >= l && b <= r)
    {
        return segTree[current];
    }
    ll mid = (a+b)/2;
    return query(a, mid, (2*current)+1) + query(mid+1, b, (2*current)+2);
}

int main()
{
	fastread;
	ll n, q;
	memset(segTree, 0, sizeof segTree);
	memset(lazy, false, sizeof lazy);
	cin>>n>>q;
    while(q--)
    {
        cin>>type>>l>>r;
        if(type == 0)
        {
            flip(0ll, n-1, 0ll);
        }
        else
        {
            cout<<query(0ll, n-1, 0ll)<<'\n';
        }
    }
	return 0;
}
