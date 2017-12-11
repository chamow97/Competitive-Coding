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
#define f first
#define s second


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
void computeLPS(string pattern, vec &lps, int m);

void KMP(string text, string pattern)
{
    int n = text.length();
    int m = pattern.length();
    vec lps(m,0);
    
    computeLPS(pattern, lps, m);
    int i = 0, j = 0;
    while(i < n)
    {
        if(text[i] == pattern[j])
        {
            i++;
            j++;
        }
        if(j == m)
        {
            //uncomment this to get a list of starting positions
            //if exists of the pattern string in the original
            cout<<i-j<<'\n';
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

void computeLPS(string pattern, vec &lps, int m)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m)
    {
        if(pattern[i] == pattern[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else if(pattern[i] != pattern[len] && len != 0)
        {
            len = lps[len-1];
        }
        else
        {
            lps[i] = 0;
            ++i;
        }
    }
}
int main()
{
	fastread;
	ll x;
	while(cin >> x)
	{
		string text, pattern;
		cin >> pattern >> text;
		KMP(text, pattern);
		cout << '\n';
	}
	return 0;
}
