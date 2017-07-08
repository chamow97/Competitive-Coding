
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
    ll n, pos = -1;
    n = read_int();
    vec arr(n,0);
    rep(i,0,n)
    {
        arr[i] = read_int();
    }
    bool isIncreasing = true;
    if(n == 2)
    {
        if(arr[0] <= arr[1])
        {
            cout<<0;
            return 0;
        }
        cout<<1;
        return 0;
    }
    rep(i,1,n)
    {
        if(arr[i] < arr[i-1])
        {
            pos = i;
            isIncreasing = false;
            break;
        }
    }
    if(isIncreasing == true)
    {
        cout<<0;
        return 0;
    }
    else
    {
        if(pos == n-1)
        {
            if(arr[n-1] <= arr[0])
            {
                cout<<1;
                return 0;
            }
            cout<<-1;
            return 0;
        }
        if(arr[pos] <= arr[0] && arr[pos] <= arr[pos+1])
        {bool isIncreasing = true;
        rep(i,pos+1,n)
        {
            if(i == n-1 && arr[i] <= arr[0] && arr[i] >= arr[i-1])
            {
                isIncreasing = true;
            }
            else if(arr[i] >= arr[i-1] && arr[i-1] <= arr[0])
            {
                isIncreasing = true;
            }
            else
            {
                isIncreasing = false;
                break;
            }
        }
        if(isIncreasing == true)
        {
            if(arr[n-1] <= arr[0])
            {
                cout<<(n-pos);
                return 0;
            }
        }
        }


    }
            cout<<-1;
    return 0;

	return 0;
}
