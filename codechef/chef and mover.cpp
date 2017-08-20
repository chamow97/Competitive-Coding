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
	while(t--)
	{
		ll n, d, sum = 0;
		cin>>n>>d;
		ll solution = 0;
		vec arr(n,0);
		rep(i,0,n)
		{
			cin>>arr[i];
			sum += arr[i];
		}
		if(sum % n != 0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			ll ans = 0;
			bool possible = true;
			sum /= n; 
			ll i = 0;
			rep(i,0,n)
			{
				arr[i] -= sum;
			}
			rep(i,0,d)
			{
				ll localSum = 0, j = i;
				while(j < n)
				{
					localSum += arr[j];
					if((j+d) > n)
					{
						break;
					}
					j += d;
				}
				if(localSum)
				{
					cout<<-1<<'\n';
					possible = false;
					break;
				}
			}
			if(possible == false)
			{
				continue;
			}
			rep(i,0,d)
			{
				ll j = i;
				while(j < n)
				{
					ans = ans + abs(arr[j]);
					if((j+d) > n)
					{
						break;
					}
					arr[j+d] += arr[j];
					j += d;
				}
			}
			cout<<ans<<'\n';
	
		}
	}
	return 0;
}