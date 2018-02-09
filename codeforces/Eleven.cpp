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

vec febonacci(20, 0);
void f()
{
	febonacci[0] = 1;
	febonacci[1] = 1;
	rep(i,2,20)
	{
		febonacci[i] = febonacci[i-1] + febonacci[i-2];
	}
}

int main()
{
	fastread;
	ll n;
	cin >> n;
	f();
	string ans = "";
	rep(i,1,n+1)
	{
		if(*lower_bound(febonacci.begin(), febonacci.end(), i) == i)
		{
			ans += 'O';
		}
		else
		{
			ans += 'o';
		}

	}
	cout << ans;
	return 0;
}
