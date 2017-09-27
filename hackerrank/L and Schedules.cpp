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
#define vecit vector<ll> :: iterator
#define vecpit vector< pair<ll, ll> > :: iterator

/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;
typedef vector< pair<ll, ll> > vecpair;


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
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
int main()
{
	fastread;
    ll t;
    cin>>t;
    rep(l,0,t)
    {
        ll n;
        cin>>n;
        ll temp;
        ll ans = 0;
        rep(i,0,n)
        {
            cin>>temp;
            ans = ans | temp;
        }
        ll digitLen = 0;
        ll temp1 = ans;
        ll soln = 0;
        rep(i,0,32)
        {
            soln += CHECK_BIT(ans,i);
        }
        cout<<"Day "<<l+1<<": "<<soln<<'\n';
    }
	return 0;
}
