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

string str;
ll a, b;
ll ka, kb;
ll kiwis = 0;

void regenerate()
{
	a = 0, b = 0, ka = 0, kb = 0, kiwis = 0;
	str = "";
}
void solve()
{
	regenerate();
	cin>>str;
	cin>>ka>>kb;
	ll len = str.length();
	ll counter = 0;
	rep(i,0,len)
	{
		if(str[i] == 'a')
		{
			a++;
		}
		else
		{
			b++;
		}
	}
	char stra, strb;
	if(b > a)
	{
		swap(a,b);
		swap(ka,kb);
		stra = 'b';
		strb = 'a';
	}
	else
	{
		stra = 'a';
		strb = 'b';
	}
	ll currenta = 0, currentb = 0;
	string ans = "";
	ll curr = -1;
	char prev = '!';
	while(a != b)
	{
		rep(i,0,min(a,min(ka,a-b)))
		{
			cout<<stra;
			++counter;
		}
		prev = stra;
		a -= min(a,min(ka,a-b));
		if(b > 0 && a != b)
		{
			cout<<strb;
			prev = strb;
			--b;
			++counter;
		}			

		else if(b == 0 && a != b)
		{
			cout<<'*';
		}
		if(b > a)
		{
			swap(a,b);
			swap(stra,strb);
		}

	}
	if(a == b && a > 0 && b > 0)
	{
		if(prev == 'a')
		{
			curr = 1;
		}
		else
		{
			curr = -1;
		}
		rep(i,0,a+b)
		{
			if(curr == -1)
			{
				cout<<'a';
			}
			else
			{
				cout<<'b';
			}
			curr *= (-1);
		}
		a = 0, b = 0;
	}
	cout<<'\n';
}


int main()
{
	fastread;
	ll t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}
