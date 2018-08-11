//template by chamow
#include<bits/stdc++.h>
/*-------------------------------------------------------- */
using namespace std;

/*-------------------------------------------------------- */

#define rep(i,val,n) for(int i=val;i<n;i++)
#define per(j,val,n) for(int j=val;j>=n;j--)
#define pb push_back
#define pi 3.14157
#define mp make_pair
#define MODULO 1000000007
#define INF 1000000000000000
#define fastread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vecit vector<int> :: iterator
#define vecpit vector< pair<int, int> > :: iterator
#define f first
#define s second


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<int> vec;
typedef vector< pair<int, int> > vecpair;


/*-------------------------------------------------------- */

ll counter = 0;


void computeLPS(string pattern, vec &lps, ll m)
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

void KMP(string text, string pattern)
{
    ll n = text.length();
    ll m = pattern.length();
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



int main()
{
	string s, t;
	ll n, m, q;
	cin >> n >> m >> q;
	cin >> s >> t;
	while(q--)
	{
		ll l, r;
		cin >> l >> r;
		string now = s.substr(l - 1, (r - l + 1));
		// cout << now;
		counter = 0;
		KMP(now, t);
		cout << counter << '\n';
	}
	return 0;
}