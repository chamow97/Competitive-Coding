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
const ll maxn = 1e5+100;
vec lps(maxn, 0);
ll m;
void computeLPS(string pattern)
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
	string str;
	cin >> str;
	m = str.length();
	computeLPS(str);
	vec pos(m+1, 0);
	vecpair ans;
	ll counter = 0;
	// rep(i,0,m)
	// {
	// 	cout << lps[i] << ' ';
	// }
	// cout << '\n';
	per(j,m,1)
	{
		pos[j] += 1;
		pos[lps[j-1]] += pos[j];
	}
	// rep(i,1,m+1)
	// {
	// 	cout << pos[i] << ' ';
	// }
	// cout << '\n';
	for(ll j = m; j > 0;)
	{
		ans.pb(mp(j, pos[j]));
		j = lps[j-1];
	}
	cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	rep(i,0,ans.size())
	{
		cout << ans[i].f << ' ' << ans[i].s << '\n';
	}
	return 0;
}
	