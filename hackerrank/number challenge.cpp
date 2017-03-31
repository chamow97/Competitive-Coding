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
ll counter = 0;

void recursive(ll from, ll to, ll last, vector<bool> &visited)
{
    if(from == 1)
    {
        rep(i,1,10)
        {
            visited[i] = true;
            recursive(2, to, (last * 10) + i, visited);
            visited[i] = false;
        }
    }
    else if(from == to)
    {
        rep(i,0,10)
        {
            if(((last * 10) + i) % to == 0 && visited[i] == false)
            {
                ++counter;
                if(counter == 1)
                {
                    cout<<(last * 10)+i<<" ";
                }
            }
        }
    }
    else
    {
        rep(i,0,10)
        {if(((last*10)+i) % from == 0 && visited[i] == false)
        {
            visited[i] = true;
            recursive(from + 1, to, (last*10)+i, visited);
            visited[i] = false;
        }
        }
    }
}

int main()
{
    ll n;
    cin>>n;
    vector<ll> dp(11);
    vector<ll> arr(11);
    dp[1] = 0;
    arr[1] = 10;
    vector<bool> visited(n,false);
    if(n == 1)
    {
        cout<<0<<" "<<10;
    }
    else
    {
        recursive(1ll,n,0ll,visited);

    cout<<counter;
    }

	return 0;
}
