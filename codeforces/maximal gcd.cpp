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
    ll n, k, maximum = -1;
    vec factors;
    n = read_int();
    k = read_int();
    if(k > (1e7))
    {
        cout<<-1;
        return 0;
    }
    if(k == 1)
    {
        cout<<n;
        return 0;
    }
    rep(i,1,sqrt(n)+1)
    {
        if(n%i == 0)
        {
            factors.pb(i);
            factors.pb(n/i);
        }

    }
    rep(i,0,factors.size())
    {
        ll sum = 0;
        sum =((factors[i]*(k-1)*(k))/2);

        if((n-sum) > ((k-1)*factors[i]) && ((factors[i] * k) <= 1e10))
        {
            maximum = max(maximum, factors[i]);
        }
    }
    if(maximum == -1 || maximum == n)
    {
        cout<<-1;
        return 0;
    }
    ll sum1 = 0;
    rep(i,0,k-1)
    {
        sum1 += (maximum*(i+1));
        cout<<maximum*(i+1)<<" ";
    }
    cout<<n-sum1;
	return 0;
}
