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
        ll current = 0;
        string s;
        cin>>s;
        s.erase(remove(s.begin(), s.end(), '='), s.end());
        ll len = s.length();
        vec ans(len,0);
        if(len == 0)
        {
            cout<<1<<'\n';
        }
        else
        {
            ans[0] = 1;
        rep(i,1,len)
        {
            if(s[i] == s[i-1])
            {
                ans[i] = 1 + ans[i-1];
            }
            else
            {
                ans[i] = 1;
            }
        }
        ll maximum = 0;
        rep(i,0,len)
        {
            maximum = max(maximum, ans[i]);
        }
        cout<<maximum+1<<'\n';
        }


    }
	return 0;
}
