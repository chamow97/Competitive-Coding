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
    ll t, n;
    t = read_int();
    while(t--)
    {
        n = read_int();
        ll maximum = 0;
        vec arr(2*n, 0);
        rep(i,0,2*n)
        {
            arr[i] = read_int();
        }
        sort(arr.begin(), arr.end());
        ll pos = n + ((n/2)+1);
        ll val = arr[pos-1];
        printf("%lld\n", val);
        ll i = 0;
        ll j = n;
        while(i<n)
        {
            printf("%lld %lld ", arr[i], arr[j]);
            i++;
            j++;
        }
        printf("\n");

    }
	return 0;
}
