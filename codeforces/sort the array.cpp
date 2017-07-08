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
    ll n, pos1, pos2, first, last, firstpos, lastpos;
    ll counter = 0;
    cin>>n;
    vector<ll> arr(n), brr(n);
	rep(i,0,n)
	{
	    cin>>arr[i];
	}
    rep(i,0,n-1)
    {
        if(arr[i] > arr[i+1])
        {
            first = arr[i];
            firstpos = i;
            while(arr[i] > arr[i+1] && i <= n-2)
            {
                i++;
            }
            lastpos = i;
            last = arr[i];
            ++counter;
        }
    }
    if(counter == 0)
    {
        cout<<"yes\n";
        cout<<1<<" "<<1;
        return 0;
    }
    if(counter == 2)
    {
        cout<<"no\n";
    }
    else
    {
        if(firstpos == 0 && lastpos == n-1)
        {
            cout<<"yes\n";
            cout<<1<<" "<<n;
        }
        else if(firstpos == 0)
        {
            if(first < arr[lastpos + 1])
            {
                cout<<"yes\n";
                cout<<firstpos+1<<" "<<lastpos+1;
            }
            else
            {
                cout<<"no\n";
            }
        }
        else if(lastpos == n-1)
        {
            if(last > arr[firstpos - 1])
            {
                cout<<"yes\n";
                cout<<firstpos+1<<" "<<lastpos+1;
            }
            else
            {
                cout<<"no\n";
            }
        }
        else
        {
            if(first < arr[lastpos + 1] && last > arr[firstpos - 1] )
            {
                cout<<"yes\n";
                cout<<firstpos+1<<" "<<lastpos+1;
            }
            else
            {
                cout<<"no\n";
            }
        }
    }


	return 0;
}
