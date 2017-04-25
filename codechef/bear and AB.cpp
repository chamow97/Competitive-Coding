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
    ll t, len, k;
    t = read_int();
    while(t--)
    {
        len = read_int();
        k = read_int();
        string s;
        cin>>s;
        ll last = 0;
        vec v;
        ll a = 0, b = 0;
        rep(i,0,len)
        {
            if(s[i] == 'a')
            {
                ++a;
            }
            else if(s[i] == 'b')
            {
                v.pb(a);
                last = a;
            }
        }
        ll extra = a - last;
        rep(i,0,v.size())
        {
           ll ans = ((k*(k-1))/2);
           ans *= a;
           ll temp = (k-1)*v[i];
           v[i] += ((ans)+(temp));
        }
        ll sum = 0;
        rep(i,0,v.size())
        {
            sum += v[i];
        }
        cout<<sum<<endl;

    }
	return 0;
}
