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
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    boolean visited(n,false);
    ll last = n;
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    rep(i,0,n)
    {
        visited[arr[i]] = true;
        if(arr[i] == last)
        {
            while(visited[last] == true && last > 0)
            {
                visited[last] = false;
                cout<<last<<" ";
                --last;
            }
            cout<<endl;
        }
        else
        {
            cout<<endl;
        }
    }
    return 0;
}
