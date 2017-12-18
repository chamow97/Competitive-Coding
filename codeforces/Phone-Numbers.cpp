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
vec patternArr;
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
            patternArr.pb(i-j);
            // cout<<"Pattern found at: "<<i-j<<'\n';
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
	ll n;
	cin >> n;
	map<string, set<string> > m;
	map<string, set<string> > ans;
	vector<string> names;
	set<string> aa;
	rep(i,0,n)
	{
		string name;
		cin >> name;
		names.pb(name);
		ll counter;
		cin >> counter;
		rep(j,0,counter)
		{
			string val;
			cin >> val;
			m[name].insert(val);
		}
	}
	rep(l,0,names.size())
	{
		vector<string> temp;
		for(auto j : m[names[l]])
		{
			temp.pb(j);
		}
		rep(i,0,temp.size())
		{
			rep(j,0,temp.size())
			{
				patternArr.resize(0);
				if(i != j && temp[j].length() < temp[i].length())
				{
					KMP(temp[i], temp[j]);
					if(patternArr.size() == 0)
					{
						continue;
					}
					ll nowVal = patternArr[patternArr.size()-1];
					if(temp[j].length() + nowVal == temp[i].length())
					{
						temp[j] = "###";
					}
				}
			}
		}
		aa.insert(names[l]);
		rep(k,0,temp.size())
		{
			if(temp[k][0] != '#')
				ans[names[l]].insert(temp[k]);
		}
	}
	cout << aa.size() << '\n';
	for(auto i : aa)
	{
		cout << i <<' ' << ans[i].size() << ' ';
		for(auto j : ans[i])
		{
			cout << j << ' ';
		}
		cout << '\n';
	}


	return 0;
}
