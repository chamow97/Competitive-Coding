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
	ll n, k, steps = 0;
	n = read_int();
	k = read_int();
	vec arr(n+1,0);
	vec counter(k+1,0);
	vec temp(k+1,0);
	rep(i,1,n+1)
	{
		arr[i] = read_int();
		counter[arr[i]]++;
	}
	if(n == 1)
	{
		cout<<(k-arr[1]);
		return 0;
	}
	while(counter[k] < n)
	{
		rep(i,0,k+1)
		{
			temp[i] = counter[i];
		}
		rep(i,1,k)
		{
			if(((temp[i] > 1) || (temp[i] == 1 && temp[i-1] == counter[i-1])) && temp[i] > 0)
			{
				temp[i]--;
				temp[i+1]++;
			}
		
		}
		++steps;
		rep(i,0,k+1)
		{
			counter[i] = temp[i];
		}
	}
	cout<<steps;
	return 0;
}