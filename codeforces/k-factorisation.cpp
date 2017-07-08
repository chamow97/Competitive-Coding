//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(ll i=val;i<n;i++)
#define per(j,val,n) for(ll j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;

/*-------------------------------------------------------- */
vector<ll> ans;
void seive(ll arr, boolean &visited)
{
    for(ll i = 2; i <= sqrt(arr); i++)
    {
        if(visited[i] == false)
        for(ll j = i*2; j <= arr; j+=i)
        {
            visited[j] = true;
        }
    }
}

ll func(ll n, vector<ll> &factor, ll k)
{
    if(k == 0)
    {
        return 0;
    }
    if(k == 1)
    {
        rep(i,0,factor.size())
        {
            if(n % factor[i] == 0)
            {
                ans.pb(n);
                return func(1, factor, 0);
            }
        }
        return -1;
    }
    else
    {
        bool isPossible = false;
        rep(i,0,factor.size())
        {
            if(n % factor[i] == 0)
            {
                isPossible = true;
                ans.pb(factor[i]);
                return func(n/factor[i], factor, --k);
            }
        }
        if(isPossible == false)
        return -1;
    }
}
int main()
{
    ll n,k;
    cin>>n>>k;
    boolean visited(n+1,false);
    seive(n, visited);
    vector<ll> factor;
    rep(i,2,n+1)
    {
        if(visited[i] == false)
        {
            factor.pb(i);
        }
    }
    if(func(n,factor,k) == -1)
    {
        cout<<-1;
        return 0;
    }
    rep(i,0,ans.size())
    {
        cout<<ans[i]<<" ";
    }

	return 0;
}
