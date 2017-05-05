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
        ll n, m;
        n = read_int();
        m = read_int();
        vec a(n,0), b(m,0);
        rep(i,0,n)
        {
            a[i] = read_int();
        }
        rep(i,0,m)
        {
            b[i] = read_int();
        }
        cout<<"\n";
        sort(a.begin(), a.end());

        sort(b.begin(), b.end());
        ll i = 0;
        ll j = 0;
        while(i < n && j < m)
        {
            if(a[i] < b[j])
            {
                i++;
            }
            else
            {
                j++;
            }

        }
        if(i >= n)
        {
            cout<<"MechaGodzilla\n";
        }
        else if(j >= m)
        {
            cout<<"Godzilla\n";
        }
        else
        {
            cout<<"uncertain\n";
        }
    }
	return 0;
}
