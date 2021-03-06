
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
    ll t, a, b;
    t = read_int();
    while(t--)
    {
        ll cur = 1;
        ll loser = -1;
        a = read_int();
        b = read_int();
        while(1)
        {
            if((cur & 1))
            {
                if((a-cur)<0)
                {
                    loser = 1;
                    break;
                }
                else
                {
                    a -= cur;
                }
                ++cur;
            }
            else
            {
                if((b-cur) < 0)
                {
                    loser = 2;
                    break;
                }
                else
                {
                    b -= cur;
                }
                ++cur;
            }
        }
        if(loser == 2)
        {
            cout<<"Limak\n";
        }
        else
        {
            cout<<"Bob\n";
        }
    }
	return 0;
}
