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
    ll t, n, k, p, temp;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        ll counter = 0;
        boolean flag(k+1,false);
        rep(i,0,n)
        {
            cin>>p;
            bool isRow = false;
            rep(j,0,p)
            {
                cin>>temp;
                if(flag[temp] == false)
                {
                    isRow = true;
                    flag[temp] = true;
                }
            }
            if(isRow == true)
            {
                ++counter;
            }
        }
        bool isAll = true;
        rep(i,1,k+1)
        {
            if(flag[i] == false)
            {
                isAll = false;
                break;
            }
        }
        if(isAll == false)
        {
            cout<<"sad\n";
        }
        else if(isAll == true && counter == n)
        {
            cout<<"all\n";
        }
        else
        {
            cout<<"some\n";
        }


    }
	return 0;
}
