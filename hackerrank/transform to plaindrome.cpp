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
struct sub{
    ll r, p;
};
ll findF(sub sets[], ll i)
{
    if(sets[i].p != i)
    {
        sets[i].p = findF(sets, sets[i].p);
    }
    return sets[i].p;
}
void unionF(sub sets[], ll x, ll y)
{
    ll xroot = findF(sets, x);
    ll yroot = findF(sets, y);
    if(sets[xroot].r < sets[yroot].r)
    {
        sets[xroot].p = yroot;
    }
    else if(sets[xroot].r > sets[yroot].r)
    {
        sets[yroot].p = xroot;
    }
    else
    {
        sets[yroot].p = xroot;
        sets[xroot].r++;
    }
}
ll LPS(vec &arr, sub sets[], ll m)
{
    ll dp[m+1][m+1];
    rep(i,0,m)
    {
        dp[i][0] = 1;
    }
    rep(j,1,m)
    {
        for(ll i = 0; i+j < m; i++)
        {
            if(findF(sets, arr[i]) == findF(sets,arr[i+j]))
            {
                dp[i][j] = (j>1)?(2 + dp[i+1][j-2]):2;
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j-1]);
            }
        }
    }
    return dp[0][m-1];
}
int main()
{
    fastread;
    ll n, k, m, u, v;
    cin>>n>>k>>m;
    struct sub *sets =
        (struct sub*) malloc( (n+1) * sizeof(struct sub) );
    rep(i,1,n+1)
    {
        sets[i].p = i;
        sets[i].r = 0;
    }

//    vec *adj = new vec[n+1];
    vec arr(m,0);
    rep(i,0,k)
    {
        cin>>u>>v;
//        adj[u].pb(v);
//        adj[v].pb(u);
        unionF(sets, u, v);
    }
    rep(i,0,m)
    {
        cin>>arr[i];
    }
    ll counter = 0;
    counter = LPS(arr, sets, m);
    cout<<counter;


	return 0;
}
