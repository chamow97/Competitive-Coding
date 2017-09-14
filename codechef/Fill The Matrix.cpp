//template by chamow
//thanks to gaurav sen for the tutorials
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
#define black 11111
#define white 22222
#define maxn 100010
/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair< ll, ll > > vecpair;

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

vec *g = new vec[maxn];
vecpair v;
ll visited[maxn];
ll n, k, x, y, z;
void getInput()
{
    cin>>n>>k;
    rep(i,1,n+1)
    {
        visited[i] = 0;
        g[i].clear();
    }
    v.clear();
    rep(i,1,k+1)
    {
        cin>>x>>y>>z;
        if(z == 1)
        {
            v.pb(mp(min(x,y), max(x,y)));
        }
        else
        {
            if(x != y)
            {
                g[x].pb(y);
                g[y].pb(x);
            }
        }
    }

    sort(v.begin(), v.end());

}
void dfs(ll s, ll color)
{
    visited[s] = color;
    for(auto i : g[s])
    {
        if(visited[i] == 0)
        {
            dfs(i, color);
        }
    }
}
void solve()
{
    for(auto i : v)
    {
        ll f = i.first;
        ll s = i.second;
        //if both are unvisited, see whether you can reach one from another
        if(visited[f] == 0 && visited[s] == 0)
        {
            dfs(f, white);
            if(visited[s] != 0)
            {
                cout<<"no";
                return;
            }
            dfs(s, black);
        }
        //if both are same and its distance is 1, its not logically possible
        else if(f == s)
        {
            cout<<"no";
            return;
        }
        //if both are already visited, they shld not have same color
        else if(visited[f] != 0 && visited[s] != 0)
        {
            if(visited[f] == visited[s])
            {
                cout<<"no";
                return;
            }
        }
        //if either one is visited
        else
        {
            //f is always visited
            if(visited[s] != 0)
            {
                swap(f,s);
            }
            if(visited[f] == black)
            {
                dfs(s, white);
            }
            else
            {
                dfs(s, black);
            }
        }
    }
    cout<<"yes";
}

int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
	    getInput();
	    solve();
	    cout<<'\n';
    }
	return 0;
}
