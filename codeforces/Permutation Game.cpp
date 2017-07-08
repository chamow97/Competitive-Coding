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
	ll n, m;
	cin>>n>>m;
	vec arr(m+1, 0);
	boolean visited(n+1, false);
	rep(i,1,m+1)
	{
		cin>>arr[i];
	}
	vec ans;
	ll current = 0;
	rep(i,1,m)
	{
		current = arr[i];
		 if(current > n)
		{
			current -= n;
		}		
		ans.pb(current);
		if(visited[current] == true)
		{
			cout<<-1;
			return 0;
		}
		visited[current] = true; 
		current += i;
	}
	rep(i,0,n)
	{
		cout<<ans[i]<<" ";
	}

	return 0;
}