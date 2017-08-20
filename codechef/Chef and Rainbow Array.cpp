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
		ll n;
		cin>>n;
		vec arr(n,0);
		rep(i,0,n)
		{
			cin>>arr[i];
		}
		bool flag = true;
		boolean isPresent(11,false);
		rep(i,0,(n/2)+1)
		{
			if(arr[i] != arr[n-1-i])
			{
				cout<<"no\n";
				flag = false;
				break;
			}
			isPresent[arr[i]];

		}
		if(flag == false)
		{
			continue;
		}
		else
		{
			rep(i,1,11)
			{
				if(isPresent[arr[i]] == false && i <= 7)
				{
					cout<<"no\n";
					flag = false;
					break;
				}
				else if(isPresent[arr[i]] == true && i > 7)
				{
					cout<<"no\n";
					flag = false;
					break;
				}
			}
			if(flag == false)
			{
				continue;
			}
		}
		cout<<"yes\n";
	}
	return 0;
}