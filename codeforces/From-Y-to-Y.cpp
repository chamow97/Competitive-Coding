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
	ll counter = 0;
	ll k;
	cin>>k;
	if(k == 0)
	{
		cout<<"a";
		return 0;
	}
	string ans = "";
	rep(i,0,26)
	{
		ll temp = 0;
		while((temp*(temp+1))/2 <= k)
		{
			++temp;
		}
		k -= ((temp * (temp - 1))/2);
		rep(j,0,temp)
		{
			ans = ans + char(97 + i);
		}
	}
	cout<<ans;
	
	return 0;
}