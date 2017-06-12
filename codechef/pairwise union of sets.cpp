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
 
/*-------------------------------------------------------- */
 
typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
 
 
/*-------------------------------------------------------- */
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, k, m, temp;
    cin>>t;
    while(t--)
    {
    	ll ans = 0;
    	cin>>n>>k;
    	vec *adj = new vec[n];
    	ll sizeOfArray[n];
    	vec newArr;
    	boolean visited(n, false);
    	rep(i,0,n)
    	{
    		cin>>m;
    		rep(j,0,m)
    		{
    			cin>>temp;
    			adj[i].pb(temp);
    		}
    		sizeOfArray[i] = m;
    	}
    	ll soln = 0;
    	rep(i,0,n)
    	{
    		if(sizeOfArray[i] == k)
    		{
    			
    			soln++;
    			ans += (n-soln);
    			visited[i] = true;
    		}
    		else
    		{
    			newArr.pb(i);
    		}
    	}
    	rep(i,0,newArr.size())
    	{
    		rep(j,i+1,newArr.size())
    		{
    			if(sizeOfArray[newArr[i]] + sizeOfArray[newArr[j]] < k)
    			{
    				//do nothing
    			}
    			else if(sizeOfArray[newArr[i]] + sizeOfArray[newArr[j]] == (2*k))
    			{
    				ans++;
    			}
    			else
    			{
    				ll counter = 0;
    				boolean vis(n, false);
    				rep(l,0,sizeOfArray[newArr[i]])
    				{
    					if(vis[adj[newArr[i]][l]] == false)
    					{
    						vis[adj[newArr[i]][l]] = true;
    						++counter;
    					}
    				}
    				rep(l,0,sizeOfArray[newArr[j]])
    				{
    					if(vis[adj[newArr[j]][l]] == false)
    					{
    						vis[adj[newArr[j]][l]] = true;
    						++counter;
    					}
    				}
    				if(counter == k)
    				{
    					++ans;
    				}
    			}
    		}
    	}
    	cout<<ans<<'\n';
    }
	return 0;
}