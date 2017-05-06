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

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
/*-------------------------------------------------------- */

int main()
{
	ll n,m;
	n = read_int();
	m = read_int();
	ll arr[m+1];
	arr[0] = 0;
	rep(i,1,m+1)
	{
		arr[i] = read_int();
	}
	ll dp[m+1][n+1];
	sort(arr, arr+m);
	rep(i,0,m+1)
	{
		dp[i][0] = 1;
	}
	rep(j,1,n+1)
	{
		dp[0][j] = 0;
	}
	rep(i,1,m+1)
	{
		rep(j,1,n+1)
		{
			if(j < arr[i])
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]];
			}
		}
	}
	cout<<dp[m][n];
	return 0;
}
