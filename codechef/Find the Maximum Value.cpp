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
	ll t;
	cin>>t;
	rep(l,0,t+1)
	{
		vec numbers;
		ll n;
		std::string line;
		getline(std::cin, line);
		std::istringstream iss(line);
		while (iss >> n)
		{
    		numbers.push_back(n);
		}
		ll maximum = 0;
		rep(i,0,numbers.size())
		{
			if(numbers[i] == numbers.size() - 1)
			{
				numbers[i] = 0;
				break;				
			}
		}
		rep(i,0,numbers.size())
		{
				maximum = max(maximum, numbers[i]);
		
		}
		if(l == 0)
		{
			continue;
		}
		cout<<maximum<<'\n';
	}
	return 0;
}