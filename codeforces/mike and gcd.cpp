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
	ll n, g, counter = 0;
	n = read_int();
	vec arr(n,0); 
	rep(i,0,n)
	{
		arr[i] = read_int();
		if(i == 0)
		{
			g = arr[i];
		}
		else
		{
			g = gcd(g, arr[i]);
 		}
	}
	if(g > 1)
	{
		cout<<"YES\n0";
	}
	else
	{
		rep(i,0,n-1)
		{
		
			ll x = arr[i];
			ll y = arr[i+1];
			bool isOdd = arr[i] & 1;
			if(isOdd == true)
			{
				arr[i] = x - y;
				arr[i+1] = x + y;
				++counter;
				--i;
			}
		}
		if(arr[n-1] % 2 == 1)
		{
			counter += 2;
		}
		cout<<"YES\n"<<counter;

	}
	return 0;
}