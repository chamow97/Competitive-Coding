//template by chamow
//thx to PrashantM's logic 
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

vec patternArray;
/*-------------------------------------------------------- */
vec lps(1e6,0);
vec counter(1e6,0);

void computeLPS(string pattern, ll m);

void KMP(string text, string pattern)
{
    ll n = text.length();
    ll m = pattern.length();
    
    computeLPS(pattern, m);
    ll i = 0, j = 0;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
    		// cout<<"Pattern found at: "<<i-j<<'\n';            pattern.pb(i-j);
            patternArray.pb(i-j);
            j = lps[j-1];
        }
        else if(i < n && pattern[j] != text[i])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
            {
                i = i + 1;
            }
        }
        
    }
}

void computeLPS(string pattern, ll m)
{
    ll len = 0;
    lps[0] = 0;
    lps[1] = 0;
    ll i = 1;
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i+1] = len;
            i++;
        }
        else if(pattern[i] != pattern[len] && len != 0)
        {
            len = lps[len];
        }
        else
        {
            lps[i+1] = 0;
            ++i;
        }
    }
}



int main()
{
	fastread;
	string str;
	cin>>str;
	ll n = str.length();
	KMP(str, str);
	rep(i,0,n)
	{
		counter[lps[i]]++;
	}
	ll now = lps[n];
	while(now)
	{
		if(counter[now])
		{
			cout<<str.substr(0,now);
			return 0;
		}
		else
		{
			now = lps[now];
		}
	}
	cout<<"Just a legend";
	
	return 0;
}