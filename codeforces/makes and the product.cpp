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
	ll n;
	n = read_int();
	vec arr(n,0);
	rep(i,0,n)
	{
		arr[i] = read_int();
	}
	sort(arr.begin(), arr.end());
	ll ub = upper_bound(arr.begin(), arr.end(), arr[0]) - arr.begin();
	ll lb = lower_bound(arr.begin(), arr.end(), arr[0]) - arr.begin();
	ll pos1 = ub - lb;
	ll ans = 0;
	if(pos1 >= 3)
	{
		ans = (pos1*(pos1-1)*(pos1-2))/6;
	}
	else if(pos1 == 2)
	{
		ub = upper_bound(arr.begin(), arr.end(), arr[2]) - arr.begin();
		lb = lower_bound(arr.begin(), arr.end(), arr[2]) - arr.begin();
		ll pos2 = ub - lb;
		if(pos2 == 1)
		{
			ans = 1;
		}
		else
		{
			ans = pos2;
		}
	}
	else
	{
		ub = upper_bound(arr.begin(), arr.end(), arr[1]) - arr.begin();
		lb = lower_bound(arr.begin(), arr.end(), arr[1]) - arr.begin();
		ll pos3 = ub - lb;
		if(pos3 == 1)
		{
			ub = upper_bound(arr.begin(), arr.end(), arr[2]) - arr.begin();
			lb = lower_bound(arr.begin(), arr.end(), arr[2]) - arr.begin();
			ll pos2 = ub - lb;			
			ans = pos2;
		}
		else
		{
			ans = (pos3*(pos3-1))/2;
		}
	}
	cout<<ans;

	return 0;
}