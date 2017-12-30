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
vec *adj = new vec[100];

int main()
{
	fastread;
	string start, end;
	cin >> start >> end;
	ll starting = (start[0] - 'a') * 8 + (start[1] - '0');
	ll ending = (end[0] - 'a') * 8 + (end[1] - '0');
	cout << max(abs(start[0] - end[0]), abs(start[1] - end[1])) << '\n';
	while(start != end)
	{
		string current = "";
		if(start[0] < end[0])
		{
			current += "R";
			start[0]++;
		}
		else if(start[0] > end[0])
		{
			current += "L";
			start[0]--;
		}
		if(start[1] < end[1])
		{
			current += "U";
			start[1]++;
		}
		else if(start[1] > end[1])
		{
			current += "D";
			start[1]--;
		}
		cout << current << '\n';
	}
	return 0;
}
