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

ll getSubsequence(string str)
{
	ll subsequence = 0;
	ll counter = 0;
	rep(i,0,str.length())
	{
		if(str[i] == 's')
		{
			++counter;
		}
		else
		{
			subsequence += counter;
		}
	}
	return subsequence;
}

bool myFunc(const string &a, const string &b)
{
	return getSubsequence(a+b) > getSubsequence(b+a);
}
string now;
ll n;
const ll maxn = 1e5+10;
vector<string> arr;

int main()
{
	fastread;
	cin >> n;
	rep(i,0,n)
	{
		cin >> now;
		arr.pb(now);
	}
	sort(arr.begin(), arr.end(), myFunc);
	string final = "";
	rep(i,0,arr.size())
	{
		final += arr[i];
	}
	ll ans = getSubsequence(final);
	cout << ans;
	return 0;
}