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

void solve(ll n, ll m,ll counter,ll counter1)
{
    if(n==0 && m==0)
    {
        return;
    }
    if( m > n && counter < 2 )
    {
        cout<<1;
        m--;
        ++counter;
        counter1 = 0;
        solve(n,m,counter,counter1);
    }
    else if(n > m && counter1 < 1)
    {
        counter = 0;
        counter1 += 1;
        cout<<0;
        --n;
        solve(n,m,counter,counter1);
    }
    else
    {
        if(counter1 < 1)
        {
            counter = 0;
            counter1 += 1;
            cout<<0;
            --n;
            solve(n,m,counter,counter1);
        }
        else
        {
            counter1 = 0;
            counter += 1;
            cout<<1;
            --m;
            solve(n,m,counter,counter1);
        }
    }
}


int main()
{
    ll n,m;
    cin>>n>>m;

    if(((n*2) + 2) < m)
    {
        cout<<"-1";
    }
    else if((n-1) > m)
    {
        cout<<"-1";
    }
    else
    {
        solve(n,m,0,0);
    }
	return 0;
}
