
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
        int n;
        unsigned long long k;
        cin>>n>>k;
        //saw the editorial
        //bit operations
        // we see that number on the right side is 2^i + number on left
        unsigned long long  val, ans = 0, val1;
        rep(i,0,n)
        {
            if(k % 2 == 1)
            {
                ans += (long long int)(1) << (n-i-1);
            }
            k /= 2;
        }
        cout<<ans<<'\n';

    }

	return 0;
}
