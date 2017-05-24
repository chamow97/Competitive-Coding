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
        ll n;
        bool isPossible = true;
        n = read_int();

        vec arr(n,0);
        rep(i,0,n)
        {
            arr[i] = read_int();

        }
        if(n%2 == 0)
        {
            cout<<"no\n";
            isPossible = false;
            continue;
        }
        rep(i,0,n)
        {
            if(i == 0 && arr[i] != 1)
            {
                //cout<<"no\n";
                isPossible = false;
                break;
            }
            else if(i != 0)
            {
                if(i <= (n/2))
                {
                    if(arr[i]-arr[i-1] != 1)
                    {
                        isPossible = false;
                        break;
                    }
                }
                else
                {
                    if(arr[i] - arr[i-1] != -1)
                    {
                        isPossible = false;
                        break;
                    }
                }
            }
        }
        if(isPossible == true){
        cout<<"yes\n";
        }
        else
        {
            cout<<"no\n";
        }

    }
	return 0;
}
