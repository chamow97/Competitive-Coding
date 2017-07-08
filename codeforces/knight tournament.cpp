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

vec arr(300000,0);
vec segTree(4*300000, 0);


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
void construct(ll a, ll b, ll pos)
{
    if(a > b)
    {
        return;
    }
    if(a == b)
    {
        segTree[pos] = -1;
    }
    else
    {
        ll mid = (a+b)/2;
        construct(a, mid, (2*pos)+1);
        construct(mid+1, b, (2*pos)+2);
        segTree[pos] = -1;
    }
}
void queries(ll pos, ll a, ll b, ll i, ll j)
{
    if(a > b || b < i || a > j)
    {
        return;
    }

}
int main()
{
	fastread;
    ll n, m;
    cin>>n>>m;

	return 0;
}
