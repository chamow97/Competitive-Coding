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
    ll l1, r1, l2, r2;
    l1 = read_int();
	r1 = read_int();
	l2 = read_int();
	r2 = read_int();
	if((r1 == 1 && l2 == 4) || (r2 == 4 && l1 == 1))
    {
        cout<<"YES";
        return 0;
    }
    if(l1 > r2)
    {
        if((l1-r2)>=2)
        {
           if(l2 > r1)
           {
               if((l2-r1)>=3)
               {
                   cout<<"NO";
                   return 0;
               }
           }
           else
           {
               if((r1-l2)>=2)
               {
                   cout<<"NO";
                   return 0;
               }
           }
        }

    }
    else if(l1 <= r2)
    {
        if((r2-l1) >= 3)
        {
            if(l2 > r1)
           {
               if((l2-r1)>=3)
               {
                   cout<<"NO";
                   return 0;
               }
           }
           else
           {
               if((r1-l2)>=2)
               {
                   cout<<"NO";
                   return 0;
               }
           }
        }
    }
    cout<<"YES";
	return 0;
}
