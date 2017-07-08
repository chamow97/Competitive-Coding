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
	ll n, a, b;
	cin>>n>>a>>b;
	ll partial = 0;
	ll ans = 0, second = 0;
    rep(i,0,n)
    {
        ll temp;
        cin>>temp;
        if(temp == 1)
        {
            if(a > 0)
            {
                a--;
            }
            else if(b > 0)
            {
                b--;
                partial++;
            }
            else if(partial >= 1)
            {
                partial--;
            }
            else
            {
                ans++;
            }
        }
        else
        {
            if(b > 0)
            {
                --b;
            }
            else
            {
                ans += 2;
            }
        }
    }
    cout<<ans;
    return 0;
}
