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

ll ans = 0;

bool isSubsequence(string &a, string &b, vec &pos, ll mid)
{
	string dummy = a;
	rep(i,0,mid)
	{
		dummy[pos[i] - 1] = '$';
	}
	string dummy1 = "";
	for(auto c : dummy)
	{
		if(c != '$')
		{
			dummy1 += c;
		}
	}
	ll i = 0, j = 0;
	while(i < dummy1.length() && j < b.length())
	{
		if(dummy1[i] == b[j])
		{
			i++;
			j++;
		}
		else
		{
			i++;
		}
	}
	if(j == b.length())
	{
		return true;
	}
	return false;
}

void binarySearch(ll low, ll high, string &a, string &b, vec &pos)
{
	if(high < low)
	{
		return;
	}
	ll mid = (low + high) / 2;
	if(isSubsequence(a, b, pos, mid))
	{
		ans = mid;
		low = mid + 1;
	}
	else
	{
		high = mid - 1;
	}
	binarySearch(low, high, a, b, pos);
}

int main()
{
	fastread;
	string a, b;
	cin >> a >> b;
	ll n = a.length();
	ll m = b.length();
	vec pos(n);
	rep(i,0,n)
	{
		cin >> pos[i];
	}
	binarySearch(0, n - 1, a, b, pos);
	cout << ans;	
	return 0;
}