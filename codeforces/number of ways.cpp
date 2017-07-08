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
    ll n, sum = 0, counter = 0;
    n = read_int();
    vec arr(n+1,0), b(n+1,0);
    vec pos;
    vec pos1;
    rep(i,1,n+1)
    {
        arr[i] = read_int();
    }
    rep(i,1,n+1)
    {
    	b[i] = b[i-1] + arr[i];
    }
    if(b[n] % 3 != 0)
    {
        cout<<0;
        return 0;
    }
    ll ans = 0;
    ll temp = 0;
    sum = b[n];
    sum /= 3;
    rep(i,1,n)
    {
    	if(b[i] == (2*sum))
    	{
    		ans += temp;
    	}
    	if(b[i] == sum)
    	{
    		temp += 1;
    	}
    }
    cout<<ans;
	return 0;
}
