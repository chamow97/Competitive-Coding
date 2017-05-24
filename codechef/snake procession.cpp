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
    t  =read_int();
    while(t--)
    {
        bool isValid = true;
        string s;
        ll counter = -1;
        ll len;
        len = read_int();
        cin>>s;

        rep(i,0,len)
        {
            if(s[i] == 'H')
            {
                if(counter == -1)
                {
                    counter = 0;
                }
                if(counter != 0)
                {
                    isValid = false;
                    break;
                }
                ++counter;
            }
            else if(s[i] == 'T')
            {
                if(counter > 1 || counter == -1 || counter <= 0)
                {
                    isValid = false;
                    break;
                }
                --counter;
            }
        }
        if(isValid == false || counter > 0)
        {
            cout<<"Invalid\n";
        }
        else
        {
            cout<<"Valid\n";
        }
    }
	return 0;
}
