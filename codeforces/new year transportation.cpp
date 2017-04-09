
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

bool dfs(ll s,vector<ll> *adj, ll d, vector<bool> &visited)
{
    visited[s] = true;
    if(s == d)
    {
        return true;
    }
    vector<ll>::iterator i;
    for(i = adj[s].begin(); i != adj[s].end(); i++)
    {
        if(visited[*i] == false)
        {
            return dfs(*i, adj, d, visited);
        }
    }
    return false;
}


int main()
{
    ll n, d;
    cin>>n>>d;
    vector<ll> a(n);
    vector<ll> *adj = new vector<ll>[(2*n)+2];
    boolean visited((2*n)+1,false);
    rep(i,0,n-1)
    {
        cin>>a[i];
        adj[i+1].pb(a[i] + i + 1);
    }
    if(dfs(1ll, adj, d, visited) == true)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }


	return 0;
}
