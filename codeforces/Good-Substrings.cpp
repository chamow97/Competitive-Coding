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

ll n, k, ans = 0;
string str;
string allowedString;

struct node{
	node *next[27];
	node()
	{
		rep(i,0,26)
		{
			next[i] = NULL;
		}
	}
};

node *root = new node();

void insert(ll pos)
{
	ll currCount = 0;
	node *current = root;
	rep(i,pos,n)
	{
		if(allowedString[str[i] - 'a'] == '0')
		{
			++currCount;
		}
		if(currCount > k)
		{
			return;
		}
		if(current -> next[str[i] - 'a'] == NULL)
		{
			current -> next[str[i] - 'a'] = new node();
			++ans;
		}
		current = current -> next[str[i] - 'a'];
	}
}

int main()
{
	fastread;
	cin >> str;
	cin >> allowedString;
	cin >> k;
	n = str.length();
	rep(i,0,n)
	{
		insert(i);
	}
	cout << ans;
	return 0;
}