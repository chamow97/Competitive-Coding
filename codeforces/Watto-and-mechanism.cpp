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
	ll n, m1;
	map<string, ll> m;
	cin>>n>>m1;
	rep(i,0,n)
	{
		string str;
		cin>>str;
		rep(j,0,str.length())
		{
			rep(k,0,3)
			{
				string temp = str;
				temp[j] = k + 'a';
				m[temp]++;
			}
		}
	}
	rep(i,0,m1)
	{
		string str;
		cin>>str;
		if(m[str])
		{
			cout<<"YES";
		}
		else
		{
			cout<<"NO";
		}
		cout<<'\n';
	}
	return 0;
}
