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

class BadNeighbors
{
public:
	int maxDonations(vector<int> arr){
		ll n = arr.size();
		ll ans = 0;
		vec dp(n,0);
		if(n == 1)
        {
            return arr[0];
        }
        if(n == 2)
        {
            return max(arr[0], arr[1]);
        }
        if(n == 3)
        {
            return max(arr[0] + arr[2], arr[1]);
        }

        //include first element
        dp[0] = arr[0];
        dp[1] = arr[0];
        rep(i,2,n)
        {
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        if(dp[n-1] != dp[n-2])
        {
            dp[n-1] = dp[n-2];
        }
        ans = max(ans, dp[n-1]);
        dp.resize(n,0);
        dp[0] = arr[1];
        dp[1] = arr[1];
        dp[2] = arr[1];
        rep(i,3,n)
        {
            dp[i] = max(dp[i-1], dp[i-2] + arr[i]);
        }
        ans = max(ans, dp[n-1]);
        return ans;
	}

};


int main()
{
	fastread;
	BadNeighbors b;
	ll n;
	cin>>n;
	vector<int> arr(n,0);
	rep(i,0,n)
	{
		scanf("%d,", &arr[i]);
	}
	cout<<b.maxDonations(arr);
	return 0;
}
