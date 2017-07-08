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
    ll n;
    n = read_int();
    vec a(n,0), b(n,0);
    rep(i,0,n)
    {
        a[i] = read_int();
        b[i] = a[i];
    }
    ll pos1 = -1, pos2 = -1,maximum = -1, minimum = INF, ans1 = 0, ans2 = 0;
    rep(i,0,n)
    {
        if(maximum < a[i])
        {
            maximum = a[i];
            pos1 = i;
        }
    }
    per(j,pos1,1)
    {
        swap(a[j],a[j-1]);
        ++ans1;
    }

    rep(i,0,n)
    {
        if(minimum > a[i])
        {
            minimum = a[i];
            pos2 = i;
        }
    }

    rep(i,pos2,n-1)
    {
        swap(a[i], a[i+1]);
        ++ans1;
    }
    //cout<<ans1;
    pos1 = -1, pos2 = -1,maximum = -1, minimum = INF;
    rep(i,0,n)
    {
        if(minimum > b[i])
        {
            minimum = b[i];
            pos2 = i;
        }
    }
    rep(i,pos2,n-1)
    {
        swap(b[i], b[i+1]);
        ++ans2;
    }
     rep(i,0,n)
    {
        if(maximum < b[i])
        {
            maximum = b[i];
            pos1 = i;
        }
    }
    per(j,pos1,1)
    {
        swap(b[j],b[j-1]);
        ++ans2;
    }
    cout<<min(ans1, ans2);
	return 0;
}
