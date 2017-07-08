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
	string str;
	ll n, p;
	cin>>n>>p;
	ll p1 = p;
	cin>>str;
	ll minimum = INF, ans = 0;
	ll counter = 0;
	while(counter < n)
	{
		ll diff1 = min(abs(str[p] - str[n-1-p]), min(abs(str[p] - 'a') + abs(str[n-1-p] - 'z'), abs(str[n-1-p] - 'a' + abs(str[p] - 'z'))));
		ans += (diff1);
		p++;
		ans++;
		if(p == n)
		{
			p = 0;
		}
		++counter;
	}
	minimum = min(minimum, ans);
	ans = 0;
	counter = 0;
	p = p1;
	while(counter < n)
	{
		ll diff1 = min(abs(str[p] - str[n-1-p]), min(abs(str[p] - 'a') + abs(str[n-1-p] - 'z'), abs(str[n-1-p] - 'a' + abs(str[p] - 'z'))));
		ans += (diff1);
		--p;
		ans++;
		if(p == -1)
		{
			p = n-1;
		}
		++counter;
	}
	minimum = min(minimum, ans);
	cout<<minimum;


	return 0;
}