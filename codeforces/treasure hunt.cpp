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
	ll x1, y1, x2, y2, x, y;
	x1 = read_int();
	y1 = read_int();
	x2 = read_int();
	y2 = read_int();
	x = read_int();
	y = read_int();

	if(abs(x1 - x2) % x != 0 || abs(y1 - y2) % y != 0)
	{
		cout<<"NO\n";
	}
	else
	{
		if((abs(x1 - x2)/x) % 2 == (abs(y1 - y2)/y) % 2)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}

	return 0;
}