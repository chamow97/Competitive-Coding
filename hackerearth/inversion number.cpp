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
#define MAXN 1000000

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
vec smallestPrimeFactor(MAXN + 1, 0);
void seive()
{
    rep(i,0,MAXN+1)
    {
        smallestPrimeFactor[i] = i;
    }
    smallestPrimeFactor[1] = 1;
    for(ll i = 2; i <= MAXN; i += 2)
    {
        smallestPrimeFactor[i] = 2;
    }
    for(ll i = 3; i <= sqrt(MAXN); i += 2)
    {
        if(smallestPrimeFactor[i] == i)
        {
            for(ll j = i*i; j <= MAXN; j += i)
            {
                if(smallestPrimeFactor[j] == j)
                {
                    smallestPrimeFactor[j] = i;
                }
            }
        }
    }
}



int main()
{
	fastread;
    ll t;
    vec ifInverse(MAXN+1, 1);
    cin>>t;
    seive();
    ifInverse[0] = 0;
    rep(i,2,MAXN+1)
    {
        ll counter = 0;
        set<ll> s;
        ll temp = i;
        while(temp != 1)
        {
            s.insert(smallestPrimeFactor[temp]);
//            cout<<smallestPrimeFactor[temp]<<" ";
            temp /= smallestPrimeFactor[temp];
            ++counter;
        }
        if(counter != s.size())
        {
            ifInverse[i] = 0;
        }
    }
    rep(i,2,MAXN+1)
    {
//        cout<<ifInverse[i]<<" ";
        ifInverse[i] += ifInverse[i-1];
    }
    while(t--)
    {
        ll l, r;
        cin>>l>>r;
        cout<<ifInverse[r] - ifInverse[max(l-1,0ll)]<<'\n';
    }
	return 0;
}
