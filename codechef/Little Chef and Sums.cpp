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
#define INF 1000000000000000000
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
        ll minimum = INF;
        ll pos = -1;
        cin>>n;
        vec arr(n+1,0);
        vec prefix(n+1,0);
        rep(i,1,n+1)
        {
            cin>>arr[i];
            prefix[i] = arr[i];
        }
        rep(i,2,n+1)
        {
            prefix[i] += prefix[i-1];
        }
        rep(i,1,n+1)
        {
            if(prefix[i] + (prefix[n] - prefix[i-1]) < minimum)
            {
                minimum = prefix[i] + prefix[n] - prefix[i-1];
                pos = i;
            }
        }
        cout<<pos<<'\n';
    }

	return 0;
}
