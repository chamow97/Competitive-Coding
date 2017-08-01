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


/*-------------------------------------------------------- */

typedef long long ll;
typedef vector<bool> boolean;
typedef vector<ll> vec;


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
	char a,b;
	cin>>a>>b;
	ll sec;
	cin>>sec;
	sec = (sec%4);
	if(sec == 0)
	{
		cout<<"undefined";
	}
	else if(sec == 1)
	{
		if(a == '^' && b == '>')
		{
			cout<<"cw";
		}
		if(a == '^' && b == '<')
		{
			cout<<"ccw";
		}
		if(a == '<' && b == '^')
		{
			cout<<"cw";
		}
		if(a == '<' && b == 'v')
		{
			cout<<"ccw";
		}if(a == 'v' && b == '>')
		{
			cout<<"ccw";
		}
		if(a == 'v' && b == '<')
		{
			cout<<"cw";
		}if(a == '>' && b == '^')
		{
			cout<<"ccw";
		}
		if(a == '>' && b == 'v')
		{
			cout<<"cw";
		}
	}
	else if(sec == 2)
	{
		cout<<"undefined";

	}
	else
	{
		if(a == '^' && b == '>')
		{
			cout<<"ccw";
		}
		if(a == '^' && b == '<')
		{
			cout<<"cw";
		}
		if(a == '<' && b == '^')
		{
			cout<<"ccw";
		}
		if(a == '<' && b == 'v')
		{
			cout<<"cw";
		}if(a == 'v' && b == '>')
		{
			cout<<"cw";
		}
		if(a == 'v' && b == '<')
		{
			cout<<"ccw";
		}if(a == '>' && b == '^')
		{
			cout<<"cw";
		}
		if(a == '>' && b == 'v')
		{
			cout<<"ccw";
		}
	}
	return 0;
}