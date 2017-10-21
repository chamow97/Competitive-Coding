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

ll n;
map<string, ll> m;
vector<string> arr;
set<string> s;
void solve()
{
	rep(i,0,n)
	{
		string temp = arr[i];
		ll len = temp.length();
		bool now = false;
		while(now == false)
		{
			now = true;
			ll newlen = temp.length();
			rep(j,0,newlen-1)
			{
				
				if(temp[j] == 'k' && temp[j+1] == 'h')
				{
					temp[j] = 'h';
					temp[j+1] = '%';
					now = false;
				}
			}
			string dummy = "";
			rep(j,0,newlen)
			{
				if(temp[j] != '%')
				{
					dummy += temp[j];
				}
			}
			temp = "";
			temp = dummy;
		}
		string dummy = "";
		rep(i,0,temp.length())
		{
			if(temp[i] == 'u')
			{
				dummy += "oo";
			}
			else
			{
				dummy += temp[i];
			}
		}
		temp = dummy;
		// cout<<temp<<'\n';
		s.insert(temp);
		
	}
		// cout<<temp<<'\n';
}

int main()
{
	fastread;
	cin>>n;
	rep(i,0,n)
	{
		string temp;
		cin>>temp;
		arr.pb(temp);
	}
	solve();
	cout<<s.size();
	return 0;
}
