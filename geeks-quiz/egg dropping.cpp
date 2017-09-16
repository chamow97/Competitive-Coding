/*
Question:
http://www.geeksforgeeks.org/dynamic-programming-set-11-egg-dropping-puzzle/
*/
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
ll findMinimalFloor(ll eggs, ll floor)
{
    ll dp[eggs+1][floor+1];
    rep(i,0,eggs+1)
    {
        dp[i][1] = 1;
    }
    rep(i,0,eggs+1)
    {
        dp[i][0] = 0;
    }
    rep(j,0,floor+1)
    {
        dp[1][j] = j;
    }
    rep(i,2,eggs+1)
    {
        rep(j,2,floor+1)
        {
            dp[i][j] = INT_MAX;
            rep(k,1,j+1)
            {
                ll currentFloor = 1 + max(dp[i-1][k-1], dp[i][j-k]);
                dp[i][j] = min(dp[i][j], currentFloor);

            }
        }
    }
    return dp[eggs][floor];

}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n>>k;
        cout<<findMinimalFloor(n, k)<<'\n';
    }
    return 0;
}
