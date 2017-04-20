
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
	ll n, m;
	n = read_int();
	vec freq(10001,0);
	vec freq1(10001,0);
	vec a(n,0);
	rep(i,0,n)
	{
		a[i] = read_int();
		freq1[a[i]]++;
	}
	m = read_int();
	vec b(m,0);
	rep(i,0,m)
	{
		b[i] = read_int();
		freq[b[i]]++;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	rep(i,0,m)
	{
		if(freq1[b[i]] == 0)
		{
			while(freq[b[i]] > 0)
			{
				cout<<b[i]<<" ";
				--freq[b[i]];
			}
		}
		else
		{
			if(freq[b[i]] - freq1[b[i]] > 0)
			{
				cout<<b[i]<<" ";
			}
			freq[b[i]] = 0;
			freq1[b[i]] = 0;
		}
	}
	return 0;
}