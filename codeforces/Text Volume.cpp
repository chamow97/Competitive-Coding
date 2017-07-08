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
	ll n;
	cin>>n;
	string str;
		// scanf("%200[0-9a-zA-Z ]", str);
	getline(cin, str);
	if(str.size()==0){
		getline(cin,str);
	}

	ll caps = 0;
	ll maximum = 0;
	rep(i,0,n)
	{
		if(str[i] >= 65 && str[i] <= 90)
		{
			++caps;
		}
		else if(str[i] == ' ')
		{
			maximum = max(maximum, caps);
			caps = 0;
		}
	}
	// cout<<str;
	maximum = max(maximum, caps);
	cout<<maximum;
	return 0;
}