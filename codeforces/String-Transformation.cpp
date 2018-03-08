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
	string str;
	cin >> str;
	ll len = str.length();
	bool possible[len+100][30];
	rep(i,0,len)
	{
		rep(j,0,26)
		{
			possible[i][j] = false;
		}
		rep(j,str[i] - 'a',26)
		{
			possible[i][j] = true;
		}
	}
	ll now = 0;
	rep(i,0,len)
	{
		if(possible[i][now] == true)
		{
			str[i] = char(now + 'a');
			now++;
		}
		if(now == 26)
		{
			break;
		}
	}
	if(now < 26)
	{
		cout << -1;
		return 0;
	}
	cout << str;
	return 0;
}