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

int main()
{
	fastread;
    ll n, m, k;
    cin>>n>>m>>k;
    ll i = 0;
    vector< pair<ll, ll> > arr;
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            if(i % 2 == 0)
            {
                arr.pb(mp(i+1, j+1));
            }
            else
            {
                arr.pb(mp(i+1, m-j));
            }
        }
    }
    ll part = (arr.size()/k);
    ll ptr = 0;
    rep(i,0,k-1)
    {
        cout<<part<<" ";
        ll j = 0;
        while(j < part)
        {
            cout<<arr[ptr].first<<" "<<arr[ptr].second<<" ";
            ptr++;
            j++;
        }
        cout<<'\n';
    }
//    cout<<ptr;
    if((arr.size()-ptr) > 0)
    {
        cout<<arr.size()-ptr<<" ";
    while(ptr < arr.size())
    {
        cout<<arr[ptr].first<<" "<<arr[ptr].second<<" ";
        ptr++;
    }

    }

	return 0;
}
