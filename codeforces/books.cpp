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
	ll n, t, i ,j;
	n = read_int();
	t = read_int();
	ll maximum = 0;
	vec arr(n+1,0);
	vec a(n+1,0);
	rep(i,1,n+1)
	{
		arr[i] = read_int();
		a[i] = arr[i];
		arr[i] += arr[i-1];
	}
	i = 1;
	j = n;
	//reducing maximum
	while(1)
	{
		ll val = (arr[j] - arr[i-1]);
		if(val > t)
		{
			if(a[i] > a[j])
			{
				i++;
			}
			else
			{
				--j;
			}
		}
		else
		{
			maximum = max(maximum, j-i+1);
			break;
		}
	}
	i = 1;
	j = n;
	//reducing maximum
	while(1)
	{
		ll val = (arr[j] - arr[i-1]);
		if(val > t)
		{
			if(a[i] >= a[j])
			{
				i++;
			}
			else
			{
				--j;
			}
		}
		else
		{
			maximum = max(maximum, j-i+1);
			break;
		}
	}
	i = 1;
	j = n;
	while(1)
	{
		ll val = (arr[j] - arr[i-1]);
		if(val > t)
		{
			if(a[i] < a[j])
			{
				i++;
			}
			else
			{
				--j;
			}
		}
		else
		{
			maximum = max(maximum, j-i+1);
			break;
		}
	}
	i = 1;
	j = n;
	while(1)
	{
		ll val = (arr[j] - arr[i-1]);
		if(val > t)
		{
			if(a[i] <= a[j])
			{
				i++;
			}
			else
			{
				--j;
			}
		}
		else
		{
			maximum = max(maximum, j-i+1);
			break;
		}
	}
	cout<<maximum;
	return 0;
}