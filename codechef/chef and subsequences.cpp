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
 
void subsequences(vec &a, ll k, vec &sub1)
{
	ll n = a.size();
	ll counter = 0;
	ll power = pow(2,n);
	rep(i,1,power)
	{
		ll prod = 1;
		ll val = k;
		rep(j,0,n)
		{
			if((i) & (1<<j))
			{
				prod *= a[j];
				val /= a[j];
			}
			
		}
		
		if(val >= 1)
		{
			sub1.pb(prod);
		}
	}
}
 
int main()
{
	ll n, k, mid, ans = 0;
	n = read_int();
	k = read_int();
	vec arr(n,0);
	vec a, b;
	vec sub1;
	vec sub2;
	mid = (n/2);
	rep(i,0,n)
	{
		arr[i] = read_int();
		
	}
	sort(arr.begin(), arr.end());
	rep(i,0,n)
	{
	    if(i < mid)
		{
			a.pb(arr[i]);
		}
		else
		{
			b.pb(arr[i]);
		}
	}
 
	subsequences(a, k, sub1);
	subsequences(b, k, sub2);
	ans += sub1.size();
	ans += sub2.size();
	sort(sub1.begin(), sub1.end());
	sort(sub2.begin(), sub2.end());
	rep(i,0,sub1.size())
	{
		ll pos = upper_bound(sub2.begin(), sub2.end(), (k/sub1[i])) - sub2.begin();
		ans += pos;
	}
	cout<<ans;
	return 0;
}    