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

int main()
{
	fastread;
	ll t;
	cin >> t;
	while(t--)
	{
		map<string, ll> m;
		ll n;
		cin >> n;
		if(n == 0)
		{
			cout << "Draw\n";
			continue;
		}
		set<string> s;
		rep(i,0,n)
		{
			string str;
			cin >> str;
			s.insert(str);
			m[str]++;
		}
		string winner = "#";
		vector<string> v1;
		for(auto u:s)
		{
			v1.pb(u);
		}
		if(v1.size() == 1)
		{
			cout << v1[0] << '\n';
			continue;
		}
		if(m[v1[0]] > m[v1[1]])
		{
			winner = v1[0];
		}
		else if(m[v1[0]] < m[v1[1]])
		{
			winner = v1[1];
		}
		else
		{
			winner = "Draw";
		}
		cout << winner;
		cout << '\n';
	}
	return 0;
}
