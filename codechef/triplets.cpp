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
	ll t;
	t = read_int();
	while(t--)
	{
		ll p, q, r, ans = 0;
		p = read_int();
		q = read_int();
		r = read_int();
		vec arr(p, 0);
		vec brr(q, 0);
		vec crr(r, 0);
		vec prefix_p(p, 0);
		vec prefix_r(r, 0);
		rep(i,0,p)
		{
			arr[i] = read_int();
		} 
		rep(i,0,q)
		{
			brr[i] = read_int();
		}
		rep(i,0,r)
		{
			crr[i] = read_int();
		}
		sort(arr.begin(), arr.end());
		sort(brr.begin(), brr.end());
		sort(crr.begin(), crr.end());
		prefix_p[0] = arr[0];
		prefix_r[0] = crr[0];
		rep(i,1,p)
		{
			prefix_p[i] = prefix_p[i-1] + arr[i];
		}
		rep(i,1,r)
		{
			prefix_r[i] = prefix_r[i-1] + crr[i];
		}
		ll no_of_p, no_of_r, size_of_p, size_of_q;
		rep(i,0,q)
		{
			ll dummy = 1;
			no_of_p = upper_bound(arr.begin(), arr.end(), brr[i]) - arr.begin();
			no_of_p--;
			no_of_r = upper_bound(crr.begin(), crr.end(), brr[i]) - crr.begin();
			no_of_r--;
			if(no_of_r != -1)
			dummy = (prefix_r[no_of_r] + ((no_of_r+1) * brr[i]));
			if(dummy > MODULO)
			{
				dummy -= MODULO;
			}
			if(no_of_p != -1)
			dummy *= (prefix_p[no_of_p] + ((no_of_p+1) * brr[i]));
			if(dummy > MODULO)
			{
				dummy -= MODULO;
			}
			if(no_of_p == -1 && no_of_r == -1)
			{
				ans += 0;
			}
			else
			ans += dummy;
			if(ans > MODULO)
			{
				ans -= MODULO;
			}

		}
		cout<<ans<<"\n";
	}
	return 0;
}