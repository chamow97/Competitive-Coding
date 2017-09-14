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
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(!(n&1))
        {
            ll counter = 0;
            ll first = 2;
            ll last = 1;
            while(counter < n/2)
            {
                cout<<first<<" "<<last<<" ";
                first += 2;
                last += 2;
                ++counter;
            }
        }
        else
        {
            ll counter = 0;
            ll first = 2;
            ll last = 1;
            while(counter <= ((n/2) - 2))
            {
                cout<<first<<" "<<last<<" ";
                first += 2;
                last += 2;
                ++counter;
            }
            if(counter == 0)
            {
                cout<<2<<" "<<3<<" "<<1;
            }
            else
            {
                cout<<first<<" "<<first+1<<" "<<first-1;
            }
        }
        cout<<'\n';
    }
	return 0;
}
