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
    vec arr(n,0);
    vec arr1(n,0);
    vec arr2(n,0);
    rep(i,0,n)
    {
        arr[i] = read_int();
    }
    ll pos = -1;
    rep(i,0,n)
    {
        if(arr[i] == 0)
        {
            pos = i;
        }
        if(pos == -1)
        {
            arr1[i] = INF;
        }
        else if(arr[i] == 0)
        {
            pos = i;
            arr1[i] = 0;
        }
        else
        {
            arr1[i] = (i-pos);
        }
    }
     pos = -1;
    per(j,n-1,0)
    {
        if(arr[j] == 0)
        {
            pos = j;
        }
        if(pos == -1)
        {
            arr2[j] = INF;
        }
        else if(arr[j] == 0)
        {
            pos = j;
            arr2[j] = 0;
        }
        else
        {
            arr2[j] = (pos - j);
        }
    }
    rep(i,0,n)
    {
        cout<<min(arr1[i], arr2[i])<<" ";
    }
	return 0;
}
