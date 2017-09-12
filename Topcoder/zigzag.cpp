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

class ZigZag{
public: 
	int longestZigZag(vector<int> arr)
	{
		ll counter;
		ll dp[51];
		ll solution[51];
		ll n = arr.size();
		rep(i,0,51)
		{
			solution[i] = -1;
			dp[i] = 0;
		}
		dp[0] = 1;
		solution[0] = -1;
		rep(i,1,n)
		{
			rep(j,0,i)
			{
				if(solution[j] == -1)
				{
					if(dp[i] < dp[j] + 1)
					{
						dp[i] = dp[j] + 1;
						solution[i] = j;
					}
				}
				else
				{
					if(arr[j] > arr[solution[j]])
					{
						if(arr[i] < arr[j])
						{
							if(dp[i] < dp[j] + 1)
							{
								dp[i] = dp[j] + 1;
								solution[i] = j;
							}
						}
					}
					else if(arr[j] < arr[solution[j]])
					{
						if(arr[i] > arr[j])
						{
							if(dp[i] < dp[j] + 1)
							{
								dp[i] = dp[j] + 1;
								solution[i] = j;
							}
						}
					}
				}
			}
		}
		return dp[n-1];
	}
};

int main()
{
	ZigZag z;
	int n;
	cin>>n;
	vector<int> arr;
	rep(i,0,n)
	{
		ll temp;
		cin>>temp;
		arr.pb(temp);
	}
	cout<<z.longestZigZag(arr);
	return 0;
}