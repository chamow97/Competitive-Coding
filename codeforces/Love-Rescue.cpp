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

ll n;
const ll maxn = 1e5 + 100;
struct subset{
	ll parent;
	ll rank;
};

vector<subset> s(maxn);

ll Find(ll x)
{
	if(s[x].parent == x)
	{
		return s[x].parent;
	}
	return Find(s[x].parent);
}

void Union(ll a, ll b)
{
	ll x = Find(a);
	ll y = Find(b);
	if(s[x].rank < s[y].rank)
	{
		s[x].parent = y;
	}
	else if(s[y].rank < s[x].rank)
	{
		s[y].parent = x;
	}
	else
	{
		s[x].parent = y;
		s[y].rank++;
	}
}

int main()
{
	fastread;
	rep(i,0,maxn)
	{
		s[i].parent = i;
		s[i].rank = 0;
	}
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	vecpair ans;
	rep(i,0,n)
	{
		ll pos1 = str1[i] - 'a';
		ll pos2 = str2[i] - 'a';
		if(Find(pos1) == Find(pos2))
		{
			continue;
		}
		ans.pb(mp(pos1, pos2));
		Union(pos1, pos2);
	}
	cout << ans.size() << '\n';
	for(auto i : ans)
	{
		cout << char(i.first + 'a') << ' ' << char(i.second + 'a') << '\n';
	}
	return 0;
}