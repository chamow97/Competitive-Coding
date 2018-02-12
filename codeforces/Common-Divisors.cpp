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
const ll maxn = 1e5 + 100;
string str1, str2;
ll len1, len2;
vec lps(maxn, 0);
ll counter = 0;
void computeLPS()
{
	ll len = 0;
	lps[0] = 0;
	ll i = 1;
	while(i < len1)
	{
		if(str1[i] == str1[len])
		{
			++len;
			lps[i] = len;
			i++;
		}
		else if(str1[i] != str1[len] && len != 0)
		{
			len = lps[len-1];
		}
		else
		{
			lps[i] = 0;
			i++;
		}
	}
}

void kmp()
{
	ll i = 0, j = 0;
	++counter;
	while(i < len2)
	{
		if(str2[i] == str1[j])
		{
			++i;
			++j;
		}
		if(j == len1)
		{
			++counter;
			j = lps[j-1];
		}
		else if(i < len2 && str1[j] != str2[i])
		{
			if(j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
}

int main()
{
	fastread;
	cin >> str1 >> str2;
	len1 = str1.length();
	len2 = str2.length();
	if(len2 % len1 != 0)
	{
		cout << 1;
		return 0;
	}
	computeLPS();
	kmp();
	cout << counter << ' ';
	rep(i,0,len1)
	{
		cout << lps[i] << ' ';
	}
	return 0;
}