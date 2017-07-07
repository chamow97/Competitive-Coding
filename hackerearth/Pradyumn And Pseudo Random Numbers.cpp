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

vec values;
void generateNumbers()
{
    ll m1 = 2017, m2 = 2027, ln = 0, sln = 1, range = 1000000007, msf = 0;
    rep(i,0,1000000)
    {
        ll nn = (ln*m1)%range;
        nn += ((sln*m2)%range);
        nn += ((msf)%range);
        nn %= range;
        nn += 1;
        sln = ln;
        ln = nn;
        msf = max(msf, nn);
        values.pb(nn);
    }
}

int main()
{
	fastread;
    ll n, q;
    cin>>n;
    cin>>q;
    generateNumbers();
    sort(values.begin(), values.end());
    while(q--)
    {
        ll key;
        cin>>key;
        if(*lower_bound(values.begin(), values.end(), key) == key)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
	return 0;
}
