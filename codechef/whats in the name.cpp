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
    t++;
	rep(l,0,t)
	{
    char s[1000];
    scanf("%10[0-9a-zA-Z ]", s);
    ll len = s.length();
    ll gap = 0;
    rep(i,0,len)
    {
        if(s[i] == ' ')
        {
            ++gap;
        }
    }
    if(gap == 0)
    {
        cout<<char(toupper(s[0]));
        rep(i,1,len)
        {
            cout<<char(tolower(s[i]));
        }
    }
    else if(gap == 1)
    {
        cout<<char(toupper(s[0]))<<". ";
        string s2 = "";
        per(i, len, 0)
        {
            if(s[i] == ' ')
            {
                break;
            }
            else
            {
                s2 = s[i] + s2;
            }
        }
        cout<<char(toupper(s2[0]));
        rep(i,1,s2.length())
        {
            cout<<char(tolower(s2[i]));
        }
    }
    else
    {
        cout<<char(toupper(s[0]))<<". ";
        ll i = 0;
        while(s[i] != ' ')
        {
            i++;
        }
        i++;
        cout<<char(toupper(s[i]))<<". ";
        string s2 = "";
        per(i, len, 0)
        {
            if(s[i] == ' ')
            {
                break;
            }
            else
            {
                s2 = s[i] + s2;
            }
        }
        cout<<char(toupper(s2[0]));
        rep(i,1,s2.length())
        {
            cout<<char(tolower(s2[i]));
        }

    }
    if(l!=0)
    cout<<'\n';
	}
	return 0;
}
