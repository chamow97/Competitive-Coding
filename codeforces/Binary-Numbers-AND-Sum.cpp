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
#define MODULO 998244353
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

ll powerMod(ll x, ll y, ll p) 
{ 
    ll res = 1; 
  
    x = x % p;  
    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
  
        y = y>>1; 
        x = (x*x) % p;   
    } 
    return res; 
} 

int main()
{
	fastread;
	ll n, m;
	cin >> n >> m;
	string str1, str2;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	string extra = "";
	rep(i,0,max(n, m) - min(n, m))
	{
		extra += '0';
	}
	if(str1.length() < max(n, m))
	{
		str1 += extra;
	}
	else
	{
		str2 += extra;
	}
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	vec prefix(str1.length() + 100, 0);
	if(str2[0] == '1')
	{
		prefix[0] = 1;
	}
	rep(i,1,str2.length())
	{
		if(str2[i] == '1')
		{
			prefix[i] = 1 + prefix[i - 1];
		}
		else
		{
			prefix[i] += prefix[i-1];
		}
	}
	ll ans = 0;
	ll now = str1.length() - 1;
	per(j,str1.length() - 1, 0)
	{
		if(str1[j] == '1')
		{
			ll curr = (powerMod(2, now - j, MODULO));
			ll prod = ((prefix[j] % MODULO) * (curr % MODULO)) % MODULO;
			ans += prod;
			if(ans >= MODULO)
			{
				ans -= MODULO;
			}
		}
	}
	cout << ans;
	return 0;
}