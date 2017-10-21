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
ll counter = 0;
void computeLPS(vec pattern, vec &lps, ll m);

void KMP(vec text, vec pattern)
{
    ll n = text.size();
    ll m = pattern.size();
    m -= 2;
    n -= 2;
    vec lps(m,0);
    computeLPS(pattern, lps, m);

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
            //uncomment this to get a list of starting positions
            //if exists of the pattern string in the original
            // cout<<"Pattern found at: "<<i-j<<'\n';
            ++counter;
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
void computeLPS(vec pattern, vec &lps, ll m)
{
    ll len = 0;
    lps[0] = 0;
    ll i = 1;
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
	ll n, m;
	cin>>n>>m;
	vec arr(n+1, 0);
	vec brr(m+1, 0);
	rep(i,0,n)
	{
		cin>>arr[i];
	}
	rep(i,0,m)
	{
		cin>>brr[i];
	}
	if(m == 1)
	{
		cout<<n;
		return 0;
	}
	rep(i,0,n-1)
	{
		arr[i] -= arr[i+1];
	}
	rep(i,0,m-1)
	{
		brr[i] -= brr[i+1];
	}
	KMP(arr, brr);
	cout<<counter;

	return 0;
}
