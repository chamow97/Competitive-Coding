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
	ll t, n, m;
	cin>>t;
	while(t--)
	{
		ll c;
		cin>>n>>m>>c;
		vec arr(c,0);
		rep(i,0,c)
		{
			cin>>arr[i];
		}
		ll l = 0;
		ll ans[n][m] = {0};
		rep(i,0,n)
		{
			if(i%2 == 0)
			{
				rep(j,0,m)
				{
					while(arr[l] == 0 && l < c)
					{
						l++;
					}
					ans[i][j] = (l+1);
					arr[l]--;
				}
			}
			else
			{
				per(j,m-1,0)
				{
					while(arr[l] == 0 && l < c)
					{
						++l;
					}
					ans[i][j] = (l+1);
					arr[l]--;

				}
			}
		}
		rep(i,0,n)
		{
			rep(j,0,m)
			{
				cout<<ans[i][j]<<" ";
			}
			cout<<'\n';
		}	
		
	}
	return 0;
}